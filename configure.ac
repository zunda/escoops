#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([escoops], [1.0.0], [zundan@gmai.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Initialize Automake
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(XINPUT, x11 xext)
PKG_CHECK_MODULES(XI2, [xi >= 1.2.99.2] [inputproto >= 1.9.99.15])
PKG_CHECK_MODULES(GIO, gio-2.0 gio-unix-2.0)

# Checks for header files.
AC_PATH_X
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
