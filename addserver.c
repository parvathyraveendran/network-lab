#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define size 500
int add(int a,int b)
{
int c;
c=a+b;
return c;
}
main()
{
  int num1,num2,sum;

  //creating a socket
  int socketid=socket(AF_INET,SOCK_STREAM,0);
  
  //inbuilt structures in c
  struct sockaddr_in client;
  struct sockaddr_in server;

  //binding sockets to a port
  server.sin_family=AF_INET;
  server.sin_port=htons(2343);
  server.sin_addr.s_addr=INADDR_ANY;
  bind(socketid,(struct sockaddr*)&server,sizeof(server));

  //listen to connection request
  listen(socketid,1);

  //accept connection request
  int s=sizeof(server);
  int clientsocketid=accept(socketid,(struct sockaddr*)&server,&s);
  printf("\n Connected");

  //receive and print the data
  recv(clientsocketid,num1,sizeof(num1),0);
//  printf("1st num recieved:%d",num1);
  recv(clientsocketid,num2,sizeof(num2),0);
  //printf("2nd num recieved:%d",num2);
 sum=add(num1,num2);
 // sum=num1+num2;
  printf("\n%d\n",sum);

  //closing the sockets
  close(clientsocketid);
}
