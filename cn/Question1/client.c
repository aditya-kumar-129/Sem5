#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>		//missing header in original file
int main(int argc , char **argv)
{
		int cs , n;
		int buffsize = 1024;
		char *buffer = malloc(buffsize);
		char fname[255];
		struct sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_port = htons(15000);
		inet_pton(AF_INET,argv[1],&address.sin_addr);

		cs = socket(AF_INET,SOCK_STREAM,0);
		connect(cs,(struct sockaddr *)&address,sizeof(address));
		printf("\nEnter Filename:");
		scanf("%s",fname);
		send(cs,fname,255.0,0);
		while((recv(cs,buffer,buffsize,0))>0)
			printf("%s\n",buffer );
		printf("\nEOF\n");
		return close(cs);
}