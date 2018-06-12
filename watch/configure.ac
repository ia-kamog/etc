AC_INIT([watch], [1.0], [ia.kamog@ya.ru])
AM_INIT_AUTOMAKE([-Werror foreign])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_PROG_CC
AC_DEFINE([_XOPEN_SOURCE],[700], [POSIX])
AC_CHECK_HEADERS([fcntl.h stddef.h stdlib.h unistd.h err.h sysexits.h])
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_MEMBERS([struct stat.st_blksize])
AC_CHECK_FUNCS([atexit strerror])
AC_CHECK_FUNCS([setprogname getprogname],
	[AC_DEFINE(HAVE_SETPROGNAME)],
	[AC_CHECK_HEADER([bsd/stdlib.h],
		[AC_DEFINE([BSD_LINUX],[1],[BSD libc on Linux])])
 	AC_CHECK_LIB([bsd], [setprogname],
		[AC_CHECK_LIB([bsd],[getprogname],
			[AC_DEFINE(HAVE_SETPROGNAME)])
		LIBS+=-lbsd])])

case $host in
*BSD*) NOTIFY_TYPE=bsd ;;
*) NOTIFY_TYPE=portable ;;
esac
AC_SUBST([NOTIFY_TYPE])
AC_OUTPUT