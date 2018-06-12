#include <config.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "error.h"
#include "util.h"

static long
count_lines(size_t len, char *buf)
{
	long c = 0;
	for (size_t i = 0; i < len; i++)
		c = buf[i] == '\n' ? c + 1 : c;
	return c;
}

long
fcount_lines(int fd, size_t bufsize, char *buf)
{
	long count = 0;
	ssize_t len;

	errno = 0;
	
	if (lseek(fd, 0, SEEK_SET) == -1)
		err(EX_IOERR, NULL);
	
	while ((len=read(fd, buf, bufsize)) > 0)
		count += count_lines(len, buf);

	if (errno != 0)
		err(EX_IOERR, NULL);

	return count;
}

#ifdef HAVE_STRUCT_STAT_BLKSIZE
size_t
fget_bufsize(int fd)
{
	struct stat st;
	if (fstat(fd, &st) == -1)
		err(EX_IOERR, NULL);

	return st.st_blksize > 0 ? st.st_blksize : BUFSIZ;
}
#else
size_t
fget_bufsize(int fd)
{
	return BUFSIZ;
}
#endif
