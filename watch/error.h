#ifndef ERROR_H
#define ERROR_H
#include <config.h>

#include <stdio.h>
void print_usage(void);

#if defined(HAVE_ERR_H) && defined(HAVE_SYSEXITS_H)
#include <err.h>
#include <sysexits.h>
#else /* !(defined(HAVE_ERR_H) && defined(HAVE_SYSEXITS_H)) */
#include <stdnoreturn.h>

#define EX_OSERR 71
#define EX_IOERR 74
#define EX_USAGE 64

noreturn void err(int eval, const char *fmt, ...);
noreturn void errx(int eval, const char *fmt, ...);
#endif /* defined(HAVE_ERR_H) && defined(HAVE_SYSEXITS_H) */

#if defined(BSD_LINUX) && defined(HAVE_SETPROGNAME)
#include <bsd/stdlib.h>
#elif defined(HAVE_SETPROGNAME)
#include <stdlib.h>
#else
void setprogname(const char *);
const char *getprogname(void);
#endif
#endif /* !ERROR_H */
