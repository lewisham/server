
#include <string>
#include <iostream>
using namespace std;

#include "network/Log.h"
#include "network/Network.h"
#include "network/Server.h"

using namespace wls;

void main(int argc, char* argv[])
{
	wls::Setup();
	bool bDebug = true;
	u_short port = 6835;
	int maxPostAccept = 2;
	if (!bDebug)
	{
		if (argc != 3)
		{
			NET_TRACE("Please add port and max number of accept posts.");
			NET_TRACE("(ex) 17000 100");
			return;
		}
		port = static_cast<u_short>(atoi(argv[1]));
		maxPostAccept = atoi(argv[2]);
	}

	

	NET_TRACE("Input : port : %d, max accept : %d", port, maxPostAccept);

	if(Network::Initialize() == false)
	{
		NET_ERROR_MSG("Network::Initialize() failed");
		return;
	}

	Server::New();
	
	if(Server::Instance()->Create(port, maxPostAccept) == false)
	{
		NET_ERROR_MSG("Server::Create() failed");
		Network::Deinitialize();
		return;
	}

#ifndef _DEBUG
	Log::EnableTrace(false);
#endif

	string input;
	bool loop = true;
	while(loop)
	{
		std::getline(cin, input);

		if(input == "`client_size")
		{
			NET_TRACE(" Number of Clients : %d", Server::Instance()->GetNumClients());
		}
		if(input == "`accept_size")
		{
			NET_TRACE(" Number of Accept posts : %d", Server::Instance()->GetNumPostAccepts());
		}
		else if(input == "`enable_trace")
		{
			wls::EnableTrace(true);
		}
		else if(input == "`disable_trace")
		{
			wls::EnableTrace(false);
		}
	}

	Server::Delete();

	Network::Deinitialize();

	wls::Cleanup();

	return;
}
