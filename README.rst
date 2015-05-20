====================
libvarnish-sslhelper
====================

---------------------------------------------
Varnish OpenSSL initialization helper library
---------------------------------------------

:Manual section: 7

DESCRIPTION
===========

This library initializes the global state of the OpenSSL library. It
will load the error strings and crypto bits, and set up the mutexes
and callback for multithreaded support.

Varnish modules needing the OpenSSL library should link against this
library instead of the OpenSSL library.

EXPORTED FUNCTIONS
==================

* int VSSLH_status(void)

  Returns 1 if the initialization code has been run correctly. Useful
  for asserts in the target module.

LICENSE
=======

See the LICENSE file.


COPYRIGHT
=========

* Copyright (c) 2015 Varnish Software
