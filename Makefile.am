ACLOCAL_AMFLAGS = -I m4

SUBDIRS = include src

EXTRA_DIST = README.rst

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libvarnish-sslhelper.pc

dist_man_MANS = libvarnish-sslhelper.7
MAINTAINERCLEANFILES = $(dist_man_MANS)

libvarnish-sslhelper.7: README.rst

%.1 %.2 %.3 %.4 %.5 %.6 %.7 %.8 %.9:
if HAVE_RST2MAN
	${RST2MAN} $< $@
else
	@echo "======================================="
	@echo "You need rst2man installed to make dist"
	@echo "======================================="
	@false
endif

