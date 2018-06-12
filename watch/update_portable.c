#include <config.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#include "update.h"

#define SLEEP 5

bool
is_old(int fd)
{
	bool res;
	struct stat st;
	static struct timespec old = {0};
	sleep(SLEEP);
	if (fstat(fd, &st) == -1)
		err(EX_IOERR, NULL);

	if (old.tv_sec < st.st_mtim.tv_sec) {
		old = st.st_mtim;
		res = true;
	} else {
		res = false;
	}

	return res;
}
