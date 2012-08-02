/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  test the PTHREAD_MUTEX_INITIALIZER
 *
 *        Version:  1.0
 *        Created:  04/24/12 16:30:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <pthread.h>
#include    <stdio.h>

int main(void)
{
    pthread_mutex_t lock_a = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t lock_b;
    lock_b = { PTHREAD_MUTEX_INITIALIZER };
    return 0;
}
