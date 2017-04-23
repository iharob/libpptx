AC_INIT([libpptx], [0.0.1], [iharob@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_MACRO_DIRS([m4])
AC_PROG_CC
LT_INIT

PKG_CHECK_MODULES([LIBXML], [libxml-2.0 >= 2.9.0])
AC_SUBST([CFLAGS], ["-std=c99 -Wall -Werror"])
AC_ARG_ENABLE(
    [debug],
    AS_HELP_STRING([--enable-debug], [Enable debug output and symbols]),
    [
        AC_SUBST([CFLAGS], ["${CFLAGS} -O0 -g3"])
        AC_SUBST([LDFLAGS], ["${LDFALGS} -g3 -O0"])
    ],
    [
        AC_SUBST([CFLAGS], ["${CFLAGS} -O3 -g0"])
        AC_SUBST([LDFLAGS], ["${LDFALGS} -g0 -O3"])
    ]
)

AC_CONFIG_FILES([Makefile libpptx.pc])
AC_OUTPUT

