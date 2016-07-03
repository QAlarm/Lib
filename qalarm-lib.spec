%global _hardened_build 1

Name:		qalarm-lib
Version:	VERSION
Release:	1%{?dist}
License:	GPLv3
Summary:	The shared lib of the qalarm system.
Summary(de):	Die gemeinsame Bibliothek des QAlarm System.

Source0:	SOURCE0

BuildRequires:	qt5-qtbase-devel qt5-qtwebsockets-devel systemd qalarm-lib-devel

%description
The shared lib of the QAlarm system.

%description -l de
Die gemeinsame Bibliothek vom QAlarm System.

%package devel
Summary:	The devel stuff.
Summary(de):	Die Entwicklungskomponenten.
Requires:	%{name}-%{version}-%{release}

%prep
%autosetup

%build
qmake-qt5
make %{?_smp_mflags}
echo %%_qalarm_conf %%{_sysconfdir}/qalarm >macros.qalarm

%install
rm -rf $RPM_BUILD_ROOT

mkdir -p %{buildroot}%{_libdir}
mkdir -p %{buildroot}%{_qalarm_conf}
mkdir -p %{buildroot}%{_qt5_translationdir}
mkdir -p %{buildroot}%{_rpmconfigdir}/macros.d

install bin/* %{buildroot}%{_libdir}
install macros.qalarm %{buildroot}%{_rpmconfigdir}/macros.d
%find_lang %{name} --with-qt

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files -f %{name}.lang
%defattr(-,root,root,-)
%doc README.md LICENSE
%dir %{_qalarm_conf}
%{_libdir}/*.so.*

%files devel
%defattr(-,root,root,-)
%{_libdir}/*.so
%{_rpmconfigdir}/macros.d/macros.qalarm

%changelog
* Tag Monat 2016 tuxmaster <qalarm@terrortux.de> - 0.0.1-1
- start
