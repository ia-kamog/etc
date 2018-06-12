#include <config.h>
#include <stdio.h>
#include "error.h"

#ifndef HAVE_SETPROGNAME
static const char *progname;

void
setprogname(const char *x)
{
	progname = x;
}

const char *
getprogname(void)
{
	return progname;
}
#endif /* HAVE_SETPROGNAME */

#if !(defined(HAVE_SYSEXITS_H) && defined(HAVE_ERR_H))
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void
errx(int eval, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	if (fmt != NULL) {
		if (getprogname() != NULL)
			fprintf(stderr, "%s: ", getprogname());
		vfprintf(stderr, fmt, args);
	}

	va_end(args);
	exit(eval);
}

noreturn void
err(int eval, char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);

	if (getprogname() != NULL)
		fprintf(stderr, "%s: ", getprogname);
	if (fmt != NULL) {
		vfprintf(stderr, fmt, args);
		fprintf(stderr, ": %s\n", strerror(errno));
	} else {
		fprintf(stderr, "%s\n", strerror(errno));
	}
	exit(eval);
}
#endif /* defined(HAVE_SYSEXITS_H) && defined(HAVE_ERR_H) */

void
print_usage(void)
{
	const char *prog = getprogname();
	if (!prog)
		prog = "PROGRAM";
	fprintf(stderr, "Usage: %s FILE\n", prog);
}
