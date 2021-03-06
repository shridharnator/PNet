#include "Packet.h"
namespace PNet {
	void PNet::Packet::Clear()
	{
		buffer.clear();
		extractionOffset = 0;
	}

	void PNet::Packet::Append(const void* data, uint32_t size)
	{
		buffer.insert(buffer.end(), (char*) data, (char*)data + size);
	}

	Packet& PNet::Packet::operator<<(uint32_t data)
	{
		data = htonl(data);
		Append(&data, sizeof(uint32_t));
		return *this;
		// TODO: insert return statement here
	}

	Packet& PNet::Packet::operator>>(uint32_t & data)
	{
		data = *reinterpret_cast<uint32_t*>(&buffer[extractionOffset]);
		data = ntohl(data);
		extractionOffset += sizeof(uint32_t);
		return *this;
		// TODO: insert return statement here
	}
	Packet& Packet::operator<<(const std::string & data)
	{
		*this << (uint32_t)data.size();
		Append(data.data(), data.size());
		return *this;
		// TODO: insert return statement here
	}
	Packet& Packet::operator>>(std::string & data)
	{
		data.clear();
		uint32_t stringSize = 0;
		*this >> stringSize;
		data.resize(stringSize);
		data.assign(&buffer[extractionOffset], stringSize);
		extractionOffset += stringSize;
		return *this;
		// TODO: insert return statement here
	}
}