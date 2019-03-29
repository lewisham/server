
#include <string>
#include <iostream>
using namespace std;

#include "network/Log.h"
#include "network/Network.h"
#include "network/Server.h"

using namespace walrus_server;

void main(int argc, char* argv[])
{
	Log::Setup();
	bool bDebug = true;
	u_short port = 17000;
	int maxPostAccept = 2;
	if (!bDebug)
	{
		if (argc != 3)
		{
			TRACE("Please add port and max number of accept posts.");
			TRACE("(ex) 17000 100");
			return;
		}
		port = static_cast<u_short>(atoi(argv[1]));
		maxPostAccept = atoi(argv[2]);
	}

	

	TRACE("Input : port : %d, max accept : %d", port, maxPostAccept);

	if(Network::Initialize() == false)
	{
		ERROR_MSG("Network::Initialize() failed");
		return;
	}

	Server::New();
	
	if(Server::Instance()->Create(port, maxPostAccept) == false)
	{
		ERROR_MSG("Server::Create() failed");
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
			TRACE(" Number of Clients : %d", Server::Instance()->GetNumClients());
		}
		if(input == "`accept_size")
		{
			TRACE(" Number of Accept posts : %d", Server::Instance()->GetNumPostAccepts());
		}
		else if(input == "`enable_trace")
		{
			Log::EnableTrace(true);
		}
		else if(input == "`disable_trace")
		{
			Log::EnableTrace(false);
		}
	}

	Server::Delete();

	Network::Deinitialize();

	Log::Cleanup();

	return;
}
