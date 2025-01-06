#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.72])
AC_INIT([temp_converter], [1.0], [ilyagr2012@gmail.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])
DX_INIT_DOXYGEN([temp_converter])

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_REQUIRE_VERSION([0.21])
GETTEXT_PACKAGE=temp_converter
AC_SUBST(GETTEXT_PACKAGE)
ALL_LINGUAS="ru"

CPPFLAGS="-I/opt/homebrew/opt/gettext/include $CPPFLAGS"
LDFLAGS="-L/opt/homebrew/opt/gettext/lib $LDFLAGS"
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)

AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/converter.h])

AC_PROG_CC

PKG_CHECK_MODULES([CHECK], [check >= 0.12],
    [HAVE_CHECK=yes],
    [HAVE_CHECK=no],
)

AM_CONDITIONAL([HAVE_CHECK], [test "$HAVE_CHECK" = "yes"])

AC_SUBST(LOCALEDIR, "/opt/homebrew/share/locale")

AC_CHECK_HEADERS([libintl.h locale.h stdlib.h math.h])

AC_CHECK_FUNCS([setlocale isfinite])

AC_CONFIG_FILES([ po/Makefile.in
    Makefile
    src/Makefile
    tests/Makefile
    man/Makefile
    doc/Makefile
])
AC_OUTPUT