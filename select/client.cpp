#include 	"socket.h"

int main(int argc, char** argv)
{
	if (3 != argc)
	{
		cerr<<"USAGE:./client serverip serverport"<<endl;
		return ERROR;
	}

	int sockfd;
	struct sockaddr_in servaddr;
	char recvbuf[MAXLINE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	if ( SUCCESS == (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))))
	{
		cout<<"connect success"<<endl;
	}

	for ( ; ; )
	{
		bzero(recvbuf, MAXLINE);
		write(sockfd, "Hello", 5);
		if (read(sockfd, recvbuf, MAXLINE) == 0)
		{
			cout<<"server close socket"<<endl;
			return SUCCESS;
		}
		else
		{
			cout<<"recv from server:"<<recvbuf<<endl;
			//sleep(1);
		}
	}
}
