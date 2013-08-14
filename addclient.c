#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define size 500
main()
{
  int num1,num2;
  int length;

  //creating socket
  int socketid=socket(AF_INET,SOCK_STREAM,0);
  
  //setting port information of socket 
  struct sockaddr_in client;
  client.sin_family=AF_INET;
  client.sin_port=htons(2343);
  client.sin_addr.s_addr=inet_addr("127.0.0.1");

  //request for connection
  connect(socketid,(struct sockaddr*)&client,sizeof(client));

  //send a message
  printf("\n Enter num1: ");
  scanf("%d",num1);
 // printf("\nnum1 send");
 // int tmp1 = htonl(num1);
  send(socketid,num1,sizeof(num1),0);
//  printf("\nnum1 send");
  printf("\n Enter num2: ");
  scanf("%d",num2);
 // printf("\nnum2 send");
  send(socketid,num2,sizeof(num2),0);
//  printf("\nnum2 send");
//  printf("\n Data transfer successfull!\n");
}
