%define debug_package %{nil}
Summary: libvarnish-sslhelper
Name: libvarnish-sslhelper
Version: 1.0.0
Release: 1%{?dist}
License: BSD
Group: System Environment/Daemons
Source0: libvarnish-sslhelper-%{version}-beta1.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires: varnish
BuildRequires: varnish-plus-libs-devel
BuildRequires: varnish >= 4.0.0

%description
TBD

%prep
%setup -n %{name}-%{version}-beta1

%build
%configure --quiet
make VERBOSE=1

%install
make install DESTDIR=%{buildroot}

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
#%{_bindir}/vha-agent
/usr/include/
%{_libdir}/libvarnish*so
/usr/lib64/libvarnish-sslhelper*
/usr/lib64/pkgconfig/libvarnish-sslhelper.pc
%{_mandir}/man?/libvarnish-sslhelper*


%post
/sbin/ldconfig

%changelog
* Wed May 20 2015 Lasse Karstensen <lkarsten@varnish-software.com> - 1.0.0-beta1
- Initial packaging.
