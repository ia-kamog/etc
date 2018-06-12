#include <config.h>

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"
#include "util.h"
#include "update.h"

#define SLEEP 5

static void fin(void);
static void print_cl(long cl);
static void setprog(int argc, char *argv[]);

static bool printed = false;
static int fd = -1;

int
main(int argc, char *argv[])
{
	size_t bufsize;

	setprog(argc, argv);

	if ((fd=open(argv[1], O_RDONLY)) == -1)
		err(EX_IOERR, NULL);

	bufsize = fget_bufsize(fd);
	char buf[bufsize];
	while (true)
		if (is_old(fd))
			print_cl(fcount_lines(fd, bufsize, buf));

	close(fd);
	return EXIT_SUCCESS;
}

void
fin(void)
{
	if (fd != -1)
		close(fd);
	if (printed)
		putchar('\n');
}

void
setprog(int argc, char *argv[])
{
	if (argc == 0)
		abort();
	setprogname(argv[0]);
	if (argc != 2) {
		print_usage();
		exit(EX_USAGE);
	}
	atexit(fin);
}

void
print_cl(long cl)
{
	printf("\r%ld", cl);
	fflush(stdout);
	printed = true;
}
