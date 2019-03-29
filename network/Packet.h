#pragma once
#include <Windows.h>
namespace wls
{

	class Client;
	class Packet
	{
	private:
		enum
		{
			MAX_BUFF_SIZE = 1024,
		};

	public:
		static Packet* Create(Client* sender, const BYTE* buff, DWORD size);
		static void Destroy(Packet* packet);

	public:
		Client* GetSender()
		{
			return m_Sender;
		}
		DWORD GetSize()
		{
			return m_Size;
		}
		BYTE* GetData()
		{
			return m_Data;
		}

	public:
		Packet();
		~Packet();

	private:
		Client* m_Sender;
		DWORD m_Size;
		BYTE m_Data[MAX_BUFF_SIZE];
	};
};