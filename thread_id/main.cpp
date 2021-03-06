/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  test if the threads in same process have same pid
 *
 *        Version:  1.0
 *        Created:  04/23/12 20:00:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
#include    <errno.h>
#include    <pthread.h>
using namespace std;

pthread_t   ntid;
void printids(const char* s)
{
    pid_t       pid;
    pthread_t   tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int) pid, (unsigned int) tid, (unsigned int) tid);
}

void* thr_fn(void *arg)
{
    printids("new thread: ");
    return ( (void*) 0);
}

int main(void)
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        cerr<<"can't create thread:"<<strerror(errno)<<endl;
    printids("main thread:");
    sleep(1);
    exit(0);
}
