AM_CPPFLAGS = -I$(top_srcdir)/include

# libvarnish-sslhelper library
lib_LTLIBRARIES = libvarnish-sslhelper.la
libvarnish_sslhelper_la_LDFLAGS = -shared ${openssl_LIBS}
libvarnish_sslhelper_la_SOURCES = vsslh.c

# test program
noinst_PROGRAMS = test
test_LDADD = libvarnish-sslhelper.la ${openssl_LIBS}
test_LDFLAGS = -pthread
test_SOURCES = test.c

check: test
	./test
