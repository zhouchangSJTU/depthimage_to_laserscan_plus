#include <WinSock2.h>  
#include <stdio.h>  
#include <stdlib.h>  

#include <TCPdata.h>

#pragma comment(lib, “ws2_32.lib”) 

struct SendInfo
{
    float32 angle_min;
    float32 angle_max;
    float32 angle_increment;
    float32[] ranges;
}

static SendInfo si;

void TCPsend(SendInfo si)
{
    TCPdata data;
    //加载套接字  
    WSADATA wsaData;  
    char buff[1024];  
    memset(buff, 0, sizeof(buff));  
  
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)  
    {  
        printf(”Failed to load Winsock”);  
        return;  
    }  
  
    SOCKADDR_IN addrSrv;  
    addrSrv.sin_family = AF_INET;  
    addrSrv.sin_port = htons(data.port);  
    addrSrv.sin_addr.S_un.S_addr = inet_addr(data.ip);  
  
    //创建套接字  
    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);  
    if(SOCKET_ERROR == sockClient){  
        printf(”Socket() error:%d”, WSAGetLastError());  
        return;  
    }  
  
    //发送数据  
    char buff = “hello, this is a Client….”;  
    send(sockClient, buff, sizeof(buff), 0);  
  
    //关闭套接字  
    closesocket(sockClient);  
    WSACleanup();  
}