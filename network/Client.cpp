#include "Client.h"
#include "TPool.h"
#include "Log.h"
#include "Network.h"

using namespace walrus_server;

static TPool<Client>* mClientPool = new TPool<Client>();

Client::Client()
{

}

Client::~Client()
{

}

/* static */ 
Client* Client::Create()
{
	Client* client = new Client();

	client->m_State = WAIT;

	client->m_Socket = Network::CreateSocket(false, 0);
	if(client->m_Socket == INVALID_SOCKET)
	{
		ERROR_MSG("Could not create socket.");		
		mClientPool->free(client);
		return NULL;
	}
	return client;
}


/* static */ 
void Client::Destroy(Client* client)
{
	if( client->m_Socket != INVALID_SOCKET )
	{
		Network::CloseSocket(client->m_Socket);
		CancelIoEx(reinterpret_cast<HANDLE>(client->m_Socket), NULL);
		client->m_Socket = INVALID_SOCKET;
		client->m_State = DISCONNECTED;
	}

	if( client->m_pTPIO != NULL )
	{
		WaitForThreadpoolIoCallbacks( client->m_pTPIO, true );
		CloseThreadpoolIo( client->m_pTPIO );
		client->m_pTPIO = NULL;
	}

	mClientPool->free(client);
}