/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/12 21:36:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    <stdlib.h>
#include    <sys/types.h>
#include    <sys/wait.h>
#include    <sys/wait.h>
#include    <string.h>
#include    <errno.h>
#include    <iostream>
using namespace std;

int
main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout<<"USEAGE:"<<argv[0]<<"ZhiXingKeZhiXingWenJianCiShu"<<endl;
        exit(0);
    }
    pid_t pid;

    int n =atoi(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if ( (pid = fork()) < 0)
            cerr<<"fork error:"<<strerror(errno)<<endl;
        else if (pid == 0)
        {
            cout<<"in child process, i:"<<i<<"\tpid:"<<getpid()<<endl;
            if (execlp("/root/lxf/exercise/exec/hello",
                        "/root/lxf/exercise/exec/hello", (char*) 0) < 0)
            {
                cerr<<"execlp error:"<<strerror(errno)<<endl;
            }
            sleep(1);
            exit(0);
        }
        sleep(2);
    }
    /* 
    if ( (pid = fork()) < 0)
            cerr<<"fork error:"<<strerror(errno)<<endl;
    else if (pid == 0)
    {
        if ( (pid = fork()) < 0)
            cerr<<"fork error:"<<strerror(errno)<<endl;
        else if (pid > 0)
            exit(0);

        for (int i = 1; i < argc; i++)
        {
            if ( (pid = fork()) < 0)
                cerr<<"fork error:"<<strerror(errno)<<endl;
            else if (0 == pid)
            {
                cout<<"in child process, i:"<<i<<"\tpid:"<<getpid()<<endl;
                if (execlp("./hello",
                            "./hello", "192.168.1.12", "123", "1", argv[i], (char*) 0) < 0)
                    cerr<<"execlp error:"<<strerror(errno)<<endl;
            }
        }
    }

    if (waitpid(pid, NULL, 0) != pid)
            cerr<<"waitpid error:"<<strerror(errno)<<endl;
    */
    exit(0);
}
