// App 2
#pragma warning(disable: 4996)
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <string>
#include <WinSock2.h>

bool checkMessage(char* msg) {
    if (strlen(msg) < 2) return false;
    if (std::atoi(msg) % 32) return false;
    else return true;
}

int main()
{
    setlocale(LC_ALL, "");

    bool clientStatus = 0;

    WSAData wsaData;
    if (WSAStartup(MAKEWORD(2, 1), &wsaData)) {
        std::cout << "ERROR #1!" << std::endl;
        return 1;
    }

    SOCKADDR_IN address;
    int addressSize = sizeof(address);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(1111);
    address.sin_family = AF_INET;


    SOCKET socket_listen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(socket_listen, (SOCKADDR*)&address, addressSize);
    listen(socket_listen, SOMAXCONN);

    SOCKET socket_connection;
    std::cout << "Server is active ..." << std::endl;
    while (1) {
        socket_connection = accept(socket_listen, (SOCKADDR*)&address, &addressSize);
        if (!socket_connection) {
            std::cout << "ERROR #2!" << std::endl;
            return 1;
        }
        if (clientStatus == 0) {
            clientStatus = 1;
            std::cout << "client "
                << address.sin_addr.S_un.S_addr
                << " connected!" << std::endl;
        }
        char buff[5];
        recv(socket_connection, buff, sizeof(buff), NULL);
        if (!strcmp(buff, "exit")) {
            clientStatus = 0;
            std::cout << "client "
                << address.sin_addr.S_un.S_addr
                << " disconnected!" << std::endl;
        }
        else {
            std::cout << "client send: "
                << (checkMessage(buff) ? buff : "INVALID MESSAGE!!!")
                << std::endl;
        }
    }


    system("pause");
}


