/*
 * =====================================================================================
 *
 *       Filename:  header.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/12 18:20:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
using namespace std;
const int FILENAME_LEN = 50;

static int getfd(int clientid_arg)
{
    char* buf = new char[FILENAME_LEN];
    memset(buf, 0, FILENAME_LEN);
    if (buf)
    {
        memcpy(buf, "hello", 5);
        delete [] buf;
        buf = NULL;
        return 1;
    }
    delete [] buf;
    buf = NULL;
    return 0;
}

int copy_getfd(int clientid_arg)
{
    char* buf = new char[FILENAME_LEN];
    memset(buf, 0, FILENAME_LEN);
    if (buf)
    {
        memcpy(buf, "hello", 5);
        delete [] buf;
        buf = NULL;
        return 1;
    }
    delete [] buf;
    buf = NULL;
    return 0;
}
