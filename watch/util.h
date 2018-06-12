#ifndef UTIL_H
#define UTIL_H
#include <config.h>
#include <stddef.h>

size_t fget_bufsize(int fd);
long fcount_lines(int fd, size_t bufsiz, char *buf);
#endif
