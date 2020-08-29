#include "network.h"
#include<iostream>

bool PNet::network::Initialize()
{
    WSADATA wsadata;
    int result=WSAStartup(MAKEWORD(2,2),&wsadata);
    if (result != 0) {
        std::cerr << "Failed to start up the winsock API." << std::endl;
        return false;
    }
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
        std::cerr << "Could not find a usable version of the winsock api dll. " << std::endl;
        return false;
    }
    return true;
}

void PNet::network::ShutDown()
{
    WSACleanup();

}
