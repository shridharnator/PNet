//Client Code
#include"..\PNet\IncludeMe.h"
#include <iostream>
using namespace PNet;
int main() {
	if (network::Initialize()) {
		std::cout << "Winsock API initilized successfully" << std::endl;
		Socket socket;
		if (socket.Create() == PResult::P_Success) {
			std::cout << "Socket Succssfully Created." << std::endl;
			if (socket.Connect(IPEndpoint("127.0.0.1", 4790)) == PResult::P_Success) {
				std::cout << "Successfully connected to server!" << std::endl;
				//uint32_t a, b, c;
				//a = 4; b = 6; c = 9;
				Packet packet;
				packet << std::string("This is the first string!");//<< b << c;
				packet << std::string("This is the second string!");
				while (true) {
					PResult result = socket.Send(packet);
					if (result != PResult::P_Success)
						break;
					std::cout << "Attempting to send chunk of data..." << std::endl;
					Sleep(500);
				}
			}
			else {
				std::cout << "Failed to connect to server." << std::endl;
			}
			socket.Close();
		}
		else {
			std::cerr << "Socket failed to create." << std::endl;
		}
	}
	network::ShutDown();
	system("pause");
	return 0;
}