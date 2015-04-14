AC_INIT(Isidor, 0.0.0)
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/isidor_main.cxx])
AM_INIT_AUTOMAKE(dist-bzip2)

AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_LANG(C++)

CXXFLAGS="$CXXFLAGS -I\${top_srcdir}/src/"
REQUIRED_CLANLIB_VERSION="0.7.3"

PKG_CHECK_MODULES(ISIDOR,
 [
  clanCore-0.7           >= $REQUIRED_CLANLIB_VERSION
  clanApp-0.7            >= $REQUIRED_CLANLIB_VERSION
  clanDisplay-0.7        >= $REQUIRED_CLANLIB_VERSION
  clanGL-0.7             >= $REQUIRED_CLANLIB_VERSION
  clanGUI-0.7            >= $REQUIRED_CLANLIB_VERSION
  clanGUIStyleSilver-0.7 >= $REQUIRED_CLANLIB_VERSION
  ],
 [])

AC_SUBST(ISIDOR_CFLAGS)
AC_SUBST(ISIDOR_LIBS)

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

dnl Local Variables:
dnl compile-command: "./autogen.sh && ./configure"
dnl End:

dnl EOF dnl
