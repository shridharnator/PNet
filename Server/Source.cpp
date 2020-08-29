//Server Code
#include"..\PNet\IncludeMe.h"
#include<iostream>
using namespace PNet;
int main() {

	if (network::Initialize()) {
		std::cout << "Winsock API initilized successfully" << std::endl;
		
		Socket socket;
		if (socket.Create() == PResult::P_Success) {
			std::cout << "Socket Successfully Created." << std::endl;
			if (socket.Listen(IPEndpoint("0.0.0.0", 4790)) == PResult::P_Success) {
				std::cout << "Socket successfully listening to port 4790." << std::endl;
				Socket newConnection;
				if (socket.Accept(newConnection) == PResult::P_Success) {
					std::cout << "New Connection accepted." << std::endl;
					//uint32_t a(0), b(0), c(0);
					std::string string1, string2;
					Packet packet;
					//int result = PResult::P_Success;
					while (true) {
						PResult result = newConnection.Recv(packet);
						if (result != PResult::P_Success)
							break;
						
						packet >> string1 >> string2;
						std::cout << string1 << std::endl;
						std::cout << string2 << std::endl;
						
					}


					newConnection.Close();
				}
				else {
					std::cerr << "Failed to accept new connection." << std::endl;
				}
			}
			else {
				std::cerr << "Failed to listen to port 4790." << std::endl;
							}
			socket.Close();
		}
		else {
			std::cerr<<"Socket failed to create."<<std::endl;
		}
	}
	network::ShutDown();
	system("pause");
	return 0;
}