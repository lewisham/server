#pragma once

#include <winsock2.h>

namespace walrus_server
{

	class Client
	{
	public:
		enum
		{
			MAX_RECV_BUFFER = 1024,
		};

		enum State
		{
			WAIT,
			ACCEPTED,
			DISCONNECTED,
		};

	public:
		static Client* Create();
		static void Destroy(Client* client);

	public:
		void SetTPIO(TP_IO* pTPIO)
		{
			m_pTPIO = pTPIO;
		}
		TP_IO* GetTPIO()
		{
			return m_pTPIO;
		}

		void SetState(State state)
		{
			m_State = state;
		}
		State GetState()
		{
			return m_State;
		}

		SOCKET GetSocket()
		{
			return m_Socket;
		}
		BYTE* GetRecvBuff()
		{
			return m_recvBuffer;
		}

	public:
		Client(void);
		~Client(void);

	private:
		TP_IO* m_pTPIO;
		State m_State;
		SOCKET m_Socket;
		BYTE m_recvBuffer[MAX_RECV_BUFFER];
	};
};