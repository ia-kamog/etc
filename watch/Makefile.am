bin_PROGRAMS = watch
watch_SOURCES = watch.c error.c util.c
EXTRA_watch_SOURCES = update_portable.c
watch_LDADD = update_$(NOTIFY_TYPE).$(OBJEXT)
watch_dependencies = update_$(NOTIFY_TYPE).$(OBJEXT)
.PHONY: clean-all
clean-all:
	-rm -rf .deps config.h* configure Makefile Makefile.in stamp-h* \
		autom4te.cache aclocal.m4 compile install-sh missing depcomp \
		config.log config.status *.o $(bin_PROGRAMS) conf653*
