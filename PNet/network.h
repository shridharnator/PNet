#pragma once
#define WIN32_LEAN_AND_MEAN
#include<WinSock2.h>
namespace PNet
{
	class network {
	public:
		static bool Initialize();
		static void ShutDown();
	};
}