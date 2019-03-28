#include "Packet.h"
#include "utils/TPool.h"

static TPool<Packet> PacketPool;

Packet::Packet()
{

}

Packet::~Packet()
{

}



/* static */ 
Packet* Packet::Create(Client* sender, const BYTE* buff, DWORD size)
{
	Packet* packet = static_cast<Packet*>(PacketPool.malloc());
	packet->m_Sender = sender; 
	packet->m_Size = size;
	CopyMemory(packet->m_Data, buff, size);

	return packet;
}

/* static */ 
void Packet::Destroy(Packet* packet)
{
	PacketPool.free(packet);
}

