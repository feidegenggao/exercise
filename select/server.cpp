#include 	"socket.h"

int
main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout<<"USAGE:./server port"<<endl;
		return ERROR;
	}

	int i, maxi, maxfd, listenfd, connfd, sockfd;
	int nready, client[FD_SETSIZE];
	ssize_t n;
	fd_set rset, allset;
	char buf[MAXLINE];
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));
	bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

	listen(listenfd, LISTENQ);

	maxfd = listenfd;
	maxi = -1;

	for (i = 0; i < FD_SETSIZE; ++i)
	{
		client[i] = -1;
	}

	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);

	for ( ; ; )
	{
		rset = allset;
		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(listenfd, &rset))
		{
			clilen = sizeof(cliaddr);
			connfd = accept(listenfd, (SA*)&cliaddr, &clilen);

			for (i = 0; i < FD_SETSIZE; ++i)
			{
				if (client[i] < 0)
				{
					client[i] = connfd;
					break;
				}
			}

			if (i == FD_SETSIZE)
			{
				cerr<<"too many clients"<<endl;
				return ERROR;
			}

			FD_SET(connfd, &allset);
			if (connfd > maxfd)
			{
				maxfd = connfd;
			}

			if (i > maxi)
			{
				maxi = i;
			}

			if (--nready <= 0)
				continue;
		}

		//if (i)
		//	cout<<"i:"<<i<<endl;

		for (i = 0; i < maxi; ++i)
		{
			if ( ( sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset))
			{
				cout<<"one sockfd:"<<sockfd<<" can be read"<<endl;
				if ( (n = read(sockfd, buf, MAXLINE)) == 0)
				{
					close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i] = -1;
				}
				else
				{
					cout<<"sockfd"<<sockfd<<" can read,"<<n<<" content:"<<buf<<endl;
					write(sockfd, buf, n);
					bzero(buf, sizeof(buf));
				}

				if (--nready <= 0)
					break;
			}
		}
	}
}
