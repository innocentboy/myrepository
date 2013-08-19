#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream> 
#include <cmath>
#include <algorithm>

using namespace std;

void error(char *msg)
{
   printf("\nsome error in reading the port.:%s\n",msg);
   //exit(1);
}

int main(int argc, char* argv[])
{
 //  printf("\nserver programm is running ..\n");  
    int sockfd,newsockfd,portno,clilen,n;
    char buffer[256];
    struct sockaddr_in server_addr,client_addr;
    if(argc<2)
  {
     error("Not sufficient argument given to the server..");
     return 1;
  }
   
   sockfd=socket(AF_INET,SOCK_STREAM,0);
   if(sockfd<0)
 {
   error("some error in openning the socket");
   return 1;
 }
   portno=atoi(argv[1]);
   bzero((char *)&server_addr,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_addr.s_addr=INADDR_ANY;
   server_addr.sin_port=htons(portno); 
   if(bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
  {
    error("some error in binding the socket to the internet address.");
    return 1;
  }
  listen(sockfd,5);
  clilen=sizeof(client_addr);
  newsockfd=accept(sockfd,(struct sockaddr *)&(client_addr),
   (socklen_t *)&clilen);
  if(newsockfd<0)
  {
    error("some problem in accepting the new client.");
    return 1;
  } 
  bzero(buffer,sizeof(buffer));
  n=read(newsockfd,buffer,sizeof(buffer));
  if(n<0)
  {	
     error("some error in reading the client.");
     return 1;
  }
   printf("\nhere is the message:%s\n",buffer);
   n=write(newsockfd,"I got your message",18);
   if(n<0)
   {
     printf("\nsome problem in sending the message to particular client     .\n");
   return 1;
   }
   
   
  return 0;
}
