/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  APUE上讲到了，create函数创建文件，只能以
 *    只写方式打开文件。我试一下。
 *    不是这样的。
 *    原因是我理解错了。
 *
 *        Version:  1.0
 *        Created:  11/01/2012 11:29:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <stdio.h>
#include    <fcntl.h>

int main()
{
    int creatfilefd = creat("foo.txt", O_RDWR);
    if (creatfilefd == -1)
    {
        perror("Creat file error.\n");
    }

}
