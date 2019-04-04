
#include <string>
#include <iostream>
#include "../engine/network/net.h"
#include "GameApp.h"

#pragma comment(lib, "../libs/Engine.lib ")

using namespace std;
using namespace wls;

void main(int argc, char* argv[])
{
	wls::Setup();
	GameApp app;
	app.Run();
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
	app.Stop();
	return;
}
