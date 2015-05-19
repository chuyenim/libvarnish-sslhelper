/*-
 * Copyright (c) 2015 Varnish Software AS
 * All rights reserved.
 *
 * Author: Martin Blix Grydeland <martin@varnish-software.com>
 */

#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/crypto.h>

#include "vsslh.h"

#ifdef NDEBUG
#define assert(e) ((void)(e))
#endif
#define AZ(e) do { assert((e) == 0); } while (0)
#define AN(e) do { assert((e) != 0); } while (0)

static int num_locks = 0;
static pthread_mutex_t *locks = NULL;
static int ok = 0;

static void
vsslh_lock_cb(int mode, int type, const char *file, int line)
{

	(void)file;
	(void)line;
	AN(ok);
	AN(locks);
	assert(type >= 0 && type < num_locks);
	if (mode & CRYPTO_LOCK)
		AZ(pthread_mutex_lock(&locks[type]));
	else
		AZ(pthread_mutex_unlock(&locks[type]));
}

static void __attribute__((constructor))
vsslh_init(void)
{
	int i;

	SSL_load_error_strings();
	AN(SSL_library_init());

	num_locks = CRYPTO_num_locks();
	assert(num_locks > 0);
	locks = malloc(sizeof (pthread_mutex_t) * num_locks);
	AN(locks);
	for (i = 0; i < num_locks; i++)
		AZ(pthread_mutex_init(&locks[i], NULL));

	AZ(CRYPTO_get_locking_callback());
	CRYPTO_set_locking_callback(vsslh_lock_cb);

	ok = 1;
}

static void __attribute__((destructor))
vsslh_fini(void)
{
	int i;

	ok = 0;

	assert(CRYPTO_get_locking_callback() == vsslh_lock_cb);
	CRYPTO_set_locking_callback(NULL);

	for (i = 0; i < num_locks; i++)
		AZ(pthread_mutex_destroy(&locks[i]));
	free(locks);
	locks = 0;
	num_locks = 0;

	EVP_cleanup();
	ERR_free_strings();
}

int
VSSLH_status(void)
{

	if (locks == NULL)
		return (0);
	if (CRYPTO_get_locking_callback() != vsslh_lock_cb)
		return (0);
	return (ok);
}
