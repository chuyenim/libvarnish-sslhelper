/*-
 * Copyright (c) 2015 Varnish Software AS
 * All rights reserved.
 *
 * Author: Martin Blix Grydeland <martin@varnish-software.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "vsslh.h"

int
main(int argc, char *argv[])
{

	if (VSSLH_status()) {
		printf("VSSL status ok\n");
		exit(0);
	} else {
		printf("VSSL status NOT ok\n");
		abort();
	}
}
