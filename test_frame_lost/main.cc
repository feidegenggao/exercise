/*
 * ============================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  用两个函数测试丢帧的策略问题
 *
 *        Version:  1.0
 *        Created:  2012年10月22日 09时51分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"
#include    <list>
#include    <unistd.h>
int f1(int a)
{
    return a;
}

int f4(int a)
{
    static int maxnu = 25000;
    static int minnu = 15000;
    maxnu += 1;
    minnu += 1;
    cout<<"请求："<<a<<"MIN,MAX"<<maxnu<<","<<minnu<<endl;
    if ( (a >= minnu) and (a <= maxnu))
    {
        return a;
    }
    else if (a < minnu)
    {
        int temp = minnu;
        while(temp % 4 != 3)
        {
            temp++;
        }
        return temp;
    }
    else 
    {
        return -1;
    }
}

class SyncBuffer
{
    public:
        SyncBuffer()
            {BUFFERMAX=2000;} 
        ~SyncBuffer();

        void putInBuffer(int);
        void deleteHead(void);
        
    private:
        int BUFFERMAX;
        list<int> buffer;
};

void SyncBuffer::putInBuffer(int framenu)
{
    if ( (framenu > 0) and 
            ( ((buffer.size() > 0 ) and (framenu > buffer.back())) or (buffer.size() == 0) )
       )
    {
        list<int>::iterator it;
        for(it = buffer.begin(); it != buffer.end(); it++)
        {
            if ((*it) > framenu)
            {
                buffer.insert(it, framenu);
                break;
            }
        }
        if (buffer.end() == it)
            buffer.push_back(framenu);

        if (buffer.size() > BUFFERMAX)
        {
            deleteHead();
        }
    }
    else
    {
        cout<<"丢弃了："<<framenu<<"begin:"<<(*buffer.begin())<<"----"<<"end:"<<buffer.back()<<"size:"<<buffer.size()<<endl;
    }
}

void SyncBuffer::deleteHead()
{
    static int last_head = 0;
    if (last_head != (*(buffer.begin())) - 1)
    {
        cout<<"lost:"<<*(buffer.begin())<<"----"<<last_head<<endl;
    }
    last_head = *(buffer.begin());
    buffer.erase(buffer.begin());
}

int main()
{
    SyncBuffer *pSyncBuf = new SyncBuffer();

    for (int frameBegin = 15005;
            frameBegin < 100000;
            frameBegin++)
    {
        pSyncBuf->putInBuffer(frameBegin++);
        pSyncBuf->putInBuffer(frameBegin++);
        pSyncBuf->putInBuffer(frameBegin++);
        pSyncBuf->putInBuffer(f4(frameBegin));
        //sleep(1);
    }

    return 0;
}
