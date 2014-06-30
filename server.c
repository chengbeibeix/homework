#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<pthread.h>


#define PORT 5000
#define BACKLOG 10
#define LENGTH 512

voidrec(void*);

intmain()
{
intsockfd;
pthread_tthread1;
intnsockfd;
intnum;
intret;
intsin_size;
charsdbuf[LENGTH];
structsockaddr_inaddr_local;
structsockaddr_inaddr_remote;
charsendstr[16]={"123456789abcde"};

if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
printf("ERROR:Failed to obtain Socket Despcritor.\n");
return(0);
}
else
{
printf("OK:Obtain Socket Despcritor successfully.\n");
}
addr_local.sin_family=AF_INET;
addr_local.sin_port=htons(PORT);
addr_local.sin_addr.s_addr=INADDR_ANY;
bzero(&(addr_local.sin_zero),8);

if(bind(sockfd,(structsockaddr*)&addr_local,sizeof(structsockaddr))==-1)
{
printf("ERROR:Failed to bind Port %d.\n",PORT);
return(0);
}
else
{
printf("OK:Bind the Pore %d successfully.\n",PORT);
}

if(listen(sockfd,BACKLOG)==-1)
{
printf("ERROR:Failed ti listen Port.\n",PORT);
return(0);
}
else
{
printf("OK:Listening the Port %d successfully.\n",PORT);
}


while(1)
{
sin_size=sizeof(structsockaddr_in);
if((nsockfd=accept(sockfd,(structsockaddr*)&addr_remote,&sin_size))==-1)
{
printf("ERROE:Obtain new Socket Despcritor error.\n");
continue;
}
else
{
printf("OK:Server has got connet from %s.\n",inet_ntoa(addr_remote.sin_addr));
}
ret=pthread_create(&thread1,PTHREAD_CREATE_JOINABLE,(void*)rec,(void*)nsockfd);
//{
// if(ret = -1)
// {
// perror("pthread_create");
// exit(-1);
// }
//}

if(!fork())
{
printf("Youcan enter string,and press'exit' to end the connet.\n");
while(strcmp(sdbuf,"exit")!=0)
{
scanf("%s",sdbuf);
if((num=send(nsockfd,sdbuf,strlen(sdbuf),0))==-1)
{
printf("ERROR:failed to sent string.\n");
close(nsockfd);
exit(1);
}
printf("OK:Sent %d bytes successful,please enter again.\n",num);
}
}
close(nsockfd);
while(waitpid(-1,NULL,WNOHANG)>0);
}
}

voidrec(void*nsockfd)
{
intfd=(int)nsockfd;
intnum;
//printf("%d\n",fd);
charbuf[LENGTH];
while(1)
{
bzero(buf,LENGTH);
num=read(fd,buf,LENGTH);
if(strlen(buf)>0)
{

printf("you have a message:%s\n",buf);
}
}
