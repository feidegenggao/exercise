/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/12 10:41:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    "my.h"

void * listen_thread(void *arg);
static void sig_usr(int signo);
static void sig_pipe(int signo);
int pipe_fd_work[2];
 
int main(int argc, char** argv)
{
    if (pipe(pipe_fd_work) < 0)
    {
        cerr<<"open pipe_fd_work error:"<<strerror(errno)<<endl;
        return -1;
    }
    else
    {
        //if i close this read of pipe ,thread can't read it
        //because they share the same fd
        //close(pipe_fd_work[0]);
    }

    signal(SIGINT, sig_usr);
    pthread_t listen_pid;
    pthread_create(&listen_pid, NULL, listen_thread, NULL);

    int nwrited;
    char *writebuf = new char[4];
    while(1)
    {
        cout<<"before write\n"<<endl;
        nwrited = write(pipe_fd_work[1], writebuf, 4);
        cout<<"\tafter write\n"<<endl;
        if (nwrited == -1)
        {
            cerr<<"write pipe error:"<<strerror(errno)<<endl;
        }
        else
        {
            cout<<"writen:"<<nwrited<<endl;
        }
        //sleep(3);
    }

    pthread_join(listen_pid, NULL);

    return 0;
}

void * listen_thread(void *arg)
{
    char *buf = new char[4];
    int nreaded;
    while(1)
    {
        nreaded = read(pipe_fd_work[0], buf, 4);
        if (nreaded == -1)
            break;
        else
        {
            cout<<"readed:"<<nreaded<<endl;
            //cout<<"buf:"<<buf<<endl;
        }
        sleep(10);
    }
    delete [] buf;
    buf = NULL;
    signal(SIGPIPE, sig_pipe);
}

static void sig_pipe(int signo)
{
    if (signo == SIGPIPE)
    {
        cout<<"progrom exit"<<endl;
        exit(1);
    }
}

static void sig_usr(int signo)
{
    if (signo == SIGINT)
    {
        cout<<"progrom exit"<<endl;
        exit(1);
    }
}
