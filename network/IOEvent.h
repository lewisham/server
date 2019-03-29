#pragma once
#include <winsock2.h>
namespace walrus_server
{

	class Client;
	class Packet;

	class IOEvent
	{
	public:
		enum Type
		{
			ACCEPT,
			RECV,
			SEND,
		};

	public:
		static IOEvent* Create(Type type, Client* client, Packet* packet = NULL);
		static void Destroy(IOEvent* event);

	public:
		Type GetType()
		{
			return m_Type;
		}
		Client* GetClient()
		{
			return m_Client;
		}
		Packet* GetPacket()
		{
			return m_Packet;
		}
		OVERLAPPED& GetOverlapped()
		{
			return m_Overlapped;
		}

	public:
		IOEvent();
		~IOEvent();

	private:
		OVERLAPPED m_Overlapped;
		Client* m_Client;
		Packet* m_Packet; // only for sending.
		Type m_Type;
	};
};