/*

   honggfuzz - utilities
   -----------------------------------------

   Author: Robert Swiecki <swiecki@google.com>

   Copyright 2010-2015 by Google Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#include <fcntl.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "common.h"
#include "log.h"

void util_rndInit(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    uint64_t seed = ((uint64_t) tv.tv_sec << 24) ^ ((uint64_t) tv.tv_usec);

    LOGMSG(l_DEBUG, "srand48() reinitialized with %ld", (long)seed);
    srand48((long)seed);
}

/*
 * Yeah.. the distribution is not perfect, but it's not supposed to be
 * cryptographically secure
 */
uint32_t util_rndGet(uint32_t min, uint32_t max)
{
    double rnd = drand48();

    return (uint32_t) lrint(floor((rnd * (max - min + 1)) + min));
}

void util_getLocalTime(const char *fmt, char *buf, size_t len)
{
    struct tm ltime;

    time_t t = time(NULL);

    localtime_r(&t, &ltime);
    strftime(buf, len, fmt, &ltime);
}

void util_nullifyStdio(void)
{
    int fd = open("/dev/null", O_RDWR);

    if (fd == -1) {
        LOGMSG_P(l_ERROR, "Couldn't open '/dev/null'");
        return;
    }

    dup2(fd, 0);
    dup2(fd, 1);
    dup2(fd, 2);

    if (fd > 2) {
        close(fd);
    }

    return;
}

bool util_redirectStdin(char *inputFile)
{
    int fd = open(inputFile, O_RDONLY);

    if (fd == -1) {
        LOGMSG_P(l_ERROR, "Couldn't open '%s'", inputFile);
        return false;
    }

    dup2(fd, 0);
    if (fd != 0) {
        close(fd);
    }

    return true;
}

void util_recoverStdio(void)
{
    int fd = open("/dev/tty", O_RDWR);

    if (fd == -1) {
        LOGMSG_P(l_ERROR, "Couldn't open '/dev/tty'");
        return;
    }

    dup2(fd, 0);
    dup2(fd, 1);
    dup2(fd, 2);

    if (fd > 2) {
        close(fd);
    }

    return;
}

/* This is not a cryptographically secure hash */
extern uint64_t util_hash(const char *buf, size_t len)
{
    uint64_t ret = 0;

    for (size_t i = 0; i < len; i++) {
        ret += buf[i];
        ret += (ret << 10);
        ret ^= (ret >> 6);
    }

    return ret;
}