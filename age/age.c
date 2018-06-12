// Print my precise age in mean years
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum {
    MEAN_YEAR = 31556952
};
#ifdef AGE
static const char *age_str = AGE;
#else
#error "Define age!"
#endif
static const char *time_format = "%F %R %Z";

int main(void)
{
    struct tm tm0;
    time_t t0, t1;
    double dt;

    memset(&tm0, 0, sizeof tm0);
    strptime(age_str, time_format, &tm0);
    t0 = mktime(&tm0);
    t1 = time(NULL);
    dt = difftime(t1, t0) / MEAN_YEAR;
    printf("%.5f\n", dt);
    return EXIT_SUCCESS;
}
