/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  get NTP TimeStamp 
 *
 *        Version:  1.0
 *        Created:  11/15/2012 10:41:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <unistd.h>
#include    <inttypes.h>
#include    <sys/time.h>
#include    <iostream>
#include    <assert.h>

/**
 * @return NTP 64-bits timestamp in host byte order.
 */
uint64_t NTPtime64 (void)
{
    struct timespec ts;
#if defined (CLOCK_REALTIME)
    //clock_gettime (CLOCK_REALTIME, &ts);
#else
    {
        struct timeval tv;
        gettimeofday (&tv, NULL);
        ts.tv_sec = tv.tv_sec;
        ts.tv_nsec = tv.tv_usec * 1000;
    }
#endif

    /* Convert nanoseconds to 32-bits fraction (232 picosecond units) */
    uint64_t t = (uint64_t)(ts.tv_nsec) << 32;
    t /= 1000000000;


    /* There is 70 years (incl. 17 leap ones) offset to the Unix Epoch.
     * No leap seconds during that period since they were not invented yet.
     */
    std::cout<<"t:"<<t<<std::endl;
    assert (t < 0x100000000);
    t |= ((70LL * 365 + 17) * 24 * 60 * 60 + ts.tv_sec) << 32;
    return t;
}

int main(void)
{
    //for (int i = 0; i < 20; i++)
    while(1)
    {
        uint64_t ntptimstamp = NTPtime64();
        std::cout<<"ntptimstamp:"<<ntptimstamp<<std::endl;
        ntptimstamp = NTPtime64();
        std::cout<<"ntptimstamp:"<<ntptimstamp<<std::endl;
    }
}
