#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<sys/types.h>
#include 	<unistd.h>
#include 	<sys/socket.h>
#include 	<sys/select.h>
#include 	<arpa/inet.h>
#include 	<strings.h>
#include 	<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

const int LISTENQ = 1024;
const int MAXLINE = 4096;
const int ERROR = -1;
const int SUCCESS = 0;
typedef struct sockaddr SA;
