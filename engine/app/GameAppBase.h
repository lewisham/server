#pragma once

namespace wls
{

	class GameAppBase
	{
	public:
		GameAppBase();
		~GameAppBase();

	public:
		virtual void Run() = 0;

	public:
		void Stop();

	protected:
		bool StartServer(short port);
	};
};