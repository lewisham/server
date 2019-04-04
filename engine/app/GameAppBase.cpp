#include "GameAppBase.h"
#include "../network/net.h"

using namespace wls;


GameAppBase::GameAppBase()
{

}

GameAppBase::~GameAppBase()
{

}

void GameAppBase::Stop()
{
	Server::Delete();
	Network::Deinitialize();
	wls::Cleanup();
}

bool GameAppBase::StartServer(short port)
{
	if (Network::Initialize() == false)
	{
		NET_ERROR_MSG("Network::Initialize() failed");
		return false;
	}
	if (Server::Instance())
	{
		NET_ERROR_MSG("Server::Instance() failed");
		return false;
	}
	Server::New();
	int maxPostAccept = 10;
	if (Server::Instance()->Create(port, maxPostAccept) == false)
	{
		NET_ERROR_MSG("Server::Create() failed");
		Network::Deinitialize();
		return false;
	}
	return true;
}



