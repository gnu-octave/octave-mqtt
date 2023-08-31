#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
### Copyright (C) 2022-2023 John Donoghue <john.donoghue@ieee.org>
###
### This program is free software; you can redistribute it and/or
### modify it under the terms of the GNU General Public License as
### published by the Free Software Foundation; either version 3 of the
### License, or (at your option) any later version.
###
### This program is distributed in the hope that it will be useful,
### but WITHOUT ANY WARRANTY; without even the implied warranty of
### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
### General Public License for more details.
###
### You should have received a copy of the GNU General Public License
### along with this program; if not, see
### <http://www.gnu.org/licenses/>.

AC_PREREQ([2.67])
AC_INIT([Octave mqtt], [0.0.4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])
AH_TOP([#include "undef-ah-octave.h"])

AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AC_PROG_SED
AC_PROG_GREP

AC_PATH_PROG([MKOCTFILE], [mkoctfile])
if test -z "$MKOCTFILE"; then
  AC_MSG_ERROR([*** 'mkoctfile' not found.])
fi
AC_CHECK_PROG(OCTAVE_CONFIG,octave-config,octave-config)
test -z "$OCTAVE_CONFIG" && OCTAVE_CONFIG=$MKOCTFILE

if test "X${IGNORE_MINGW_PATH_MODIFICATION}" == "X"; then
case $host_os in
  mingw*)
    # try demangle spaces in escaped input strings  
    MKOCTFILE=`echo $MKOCTFILE | $SED "s,\\\\\ ,?,g"`
    OCTAVE_CONFIG=`echo $OCTAVE_CONFIG | $SED "s,\\\\\ ,?,g"`
    ;;
  *)
    ;;
esac
fi

CXX=`${MKOCTFILE} -p CXX`
save_CXX="$CXX"
AC_PROG_CXX
AC_PROG_CXXCPP

AX_CXX_COMPILE_STDCXX(11)
CXX11_SWITCH=$(echo "$CXX" | $SED "s,^$save_CXX,,")
AC_SUBST(CXX11_SWITCH)
CXX="$save_CXX"

AC_LANG(C++)

# check can access std c files
AC_CHECK_HEADERS([string.h])

AX_PTHREAD([],[AC_MSG_ERROR([thread library is needed to install $PACKAGE_NAME])])

## octave API tests
save_CXX="$CXX"
save_CXXFLAGS="$CXXFLAGS"
save_LIBS="$LIBS"
save_LDFLAGS="$LDFLAGS"

CXX=`${MKOCTFILE} -p CXX`
OCTINCLUDEDIR="${OCTINCLUDEDIR:-`$MKOCTFILE -p OCTINCLUDEDIR`}/.."
OCTLIBDIR=${OCTLIBDIR:-`$MKOCTFILE -p OCTLIBDIR`}

if test "X${IGNORE_MINGW_PATH_MODIFICATION}" == "X"; then
  MSYSTEM="${MSYSTEM}"
else
  MSYSTEM="none"
fi

case X$MSYSTEM in
  XMINGW64*)
    OCTAVE_HOME=`${MKOCTFILE} -p OCTAVE_HOME | $SED 's,\\\\,/,g'`
    # change \ to / and replace octave home part with mingw part
    OCTINCLUDEDIR=`echo $OCTINCLUDEDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw64,g"`
    OCTLIBDIR=`echo $OCTLIBDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw64,g"`
    ;;
  XMINGW32*)
    OCTAVE_HOME=`${MKOCTFILE} -p OCTAVE_HOME | $SED 's,\\\\,/,g'`
    # change \ to / and replace octave home part with mingw part
    OCTINCLUDEDIR=`echo $OCTINCLUDEDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw32,g"`
    OCTLIBDIR=`echo $OCTLIBDIR | $SED -e 's,\\\\,/,g -e "s,${OCTAVE_HOME},/mingw32,g"'`
    ;;
  *)
    ;;
esac

CXXFLAGS="-I$OCTINCLUDEDIR $CXXFLAGS"
LDFLAGS="-L$OCTLIBDIR $LDFLAGS"
LIBS="-loctinterp $LIBS"

# includes
AC_CHECK_HEADERS([octave/interpreter.h octave/oct-time.h],
  [],
  [],
  [#include <octave/oct.h>]
)

# need to use interpreter->get_load_path in dev version of octave,
# prior to that methods of load_path were static
AC_CACHE_CHECK(
  [interpreter get_load_path],
  [octave_cv_interpreter_get_load_path],
  [AC_COMPILE_IFELSE(
    [AC_LANG_PROGRAM([
      #include <octave/oct.h>
      #include <octave/octave.h>
      #include <octave/interpreter.h>
      #include <octave/load-path.h>
      ],
      [
        octave::load_path &p = octave::interpreter::the_interpreter ()->get_load_path ();
      ])],
    [octave_cv_interpreter_get_load_path=yes],
    [octave_cv_interpreter_get_load_path=no])
  ])
if test "$octave_cv_interpreter_get_load_path" = "yes" ; then
  AC_DEFINE(HAVE_OCTAVE_LOAD_PATH,[1],[Whether we have the interpreter load path])
fi

dnl NOTE: most of these are to handle octave < 4.0 so probally not needed
OF_OCTAVE_LIST_ALT_SYMS([

[dnl
  [feval],
  [octave::feval],
  [[octave::feval ("date");]],
  [OCTAVE__FEVAL],
  [[#include <octave/parse.h>]],
  [[#include <octave/parse.h>]]
],

[dnl
  [octave_time],
  [octave::sys::time],
  [[octave::sys::time t;]],
  [OCTAVE__TIME],
  [[#include <octave/oct-time.h>]],
  [[#include <octave/oct-time.h>]]
],

[dnl
  [is_float_type],
  [isfloat],
  [[octave_value ().isfloat ();]],
  [OV_ISFLOAT],
  [],
  []
],

[dnl
  [is_integer_type],
  [isinteger],
  [[octave_value ().isinteger ();]],
  [OV_ISINTEGER],
  [],
  []
],

[dnl
  [is_bool_type],
  [islogical],
  [[octave_value ().islogical ();]],
  [OV_ISLOGICAL],
  [],
  []
],

[dnl
  [octave_base_value],
  [octave_base_dld_value],
  [[octave_base_dld_value tmp;]],
  [OCTAVE_BASE_CLASS],
  [],
  []
],

[dnl
  [octave_execution_exception],
  [octave::execution_exception],
  [[octave::execution_exception err;]],
  [OCTAVE_EXECUTION_EXCEPTION],
  [#include <octave/quit.h>],
  [#include <octave/quit.h>]
]

],[oct-alt-includes.h])

# check if method of getting execution exception message
AC_MSG_CHECKING([for execution_exception message field])
octave_execution_field=none
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
   #include <octave/oct.h>
   #include <octave/quit.h>
  ]], [
    OCTAVE_EXECUTION_EXCEPTION err; err.message();
  ])],
 [octave_execution_field=message],
 [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
     #include <octave/oct.h>
     #include <octave/quit.h>
    ]], [
      OCTAVE_EXECUTION_EXCEPTION err; err.info();
    ])],
    [octave_execution_field=info],
    [])
 ]
)
AC_MSG_RESULT([$octave_execution_field])
AC_DEFINE_UNQUOTED([OCTAVE_EXCEPTION_MESSAGE],$octave_execution_field,[execution_exception message field])

if test $octave_execution_field != none; then
AC_DEFINE([HAS_OCTAVE_EXCEPTION_MESSAGE],[1],[has some kid of execution_exception message field])
fi

AC_MSG_CHECKING([for octave_base_value count field])
octave_count_field=count
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
   #include <octave/oct.h>
   #ifdef HAVE_CONFIG_H
   #  include "config.h"
   #endif
   class test_base_class : public octave_base_value
   {
   public:
     test_base_class() {}
     ~test_base_class() {}
     void test() { m_count ++; }
     bool is_object (void) const { return true; }
   };
  ]], [
    test_base_class t;  t.is_object();
  ])],
 [octave_count_field=m_count],
 [octave_count_field=count]
)
AC_MSG_RESULT([$octave_count_field])
AC_DEFINE_UNQUOTED([OV_COUNT],$octave_count_field,[octave_base_value ref count field])

CC=$save_CXX
CXXFLAGS=$save_CXXFLAGS
LIBS="$save_LIBS"
LDFLAGS="$save_LDFLAGS"

# look for phaho-mqtt
save_LDFLAGS=$LDFLAGS
save_CPPFLAGS=$CPPFLAGS
save_LIBS=$LIBS

MQTT_CXXFLAGS=$MQTT_CXXFLAGS
MQTT_LIBS=$MQTT_LIBS
AC_SUBST(MQTT_CXXFLAGS)
AC_SUBST(MQTT_LIBS)

have_mqtt=no
AC_CHECK_HEADERS([MQTTClient.h],
  [AC_SEARCH_LIBS([MQTTClient_connect], [paho-mqtt3cs paho-mqtt3c], [have_mqtt=$ac_cv_search_MQTTClient_connect], [])], [])

if test "x$have_mqtt" == "xno"; then
  AC_MSG_ERROR([paho-mqtt is required to install $PACKAGE_NAME])
else
  MQTT_LIBS=$have_mqtt
fi

## restore
CPPFLAGS=$save_CPPFLAGS
LDFLAGS=$save_LDFLAGS
LIBS="$save_LIBS"

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
