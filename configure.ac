AC_PREREQ(2.59)
AC_COPYRIGHT([Copyright (c) 2015 Varnish Software AS])
AC_INIT([libvarnish-sslhelper], [1.0.0-beta1])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR(src/vsslh.c)
AM_CONFIG_HEADER(config.h)

AC_CANONICAL_SYSTEM
AC_LANG(C)

AM_INIT_AUTOMAKE([foreign])

AC_GNU_SOURCE
AC_PROG_CC
AC_PROG_CC_STDC
if test "x$ac_cv_prog_cc_c99" = xno; then
	AC_MSG_ERROR([Could not find a C99 compatible compiler])
fi
AC_PROG_CPP

AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_MAKE_SET

PKG_CHECK_MODULES([openssl], [libssl])

# Check for rst utilities
AC_CHECK_PROGS(RST2MAN, [rst2man rst2man.py], "no")
if test "x$RST2MAN" = "xno"; then
	AC_MSG_WARN([rst2man not found - not building man pages])
fi
AM_CONDITIONAL(HAVE_RST2MAN, [test "x$RST2MAN" != "xno"])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([sys/stdlib.h])

AC_CONFIG_FILES([
	libvarnish-sslhelper.pc
	Makefile
	include/Makefile
	src/Makefile
])
AC_OUTPUT
