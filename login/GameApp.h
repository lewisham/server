#pragma once
#include <Windows.h>

#include "../engine/app/GameAppBase.h"

class GameApp: public wls::GameAppBase
{
public:
	GameApp();
	~GameApp();

public:
	virtual void Run();
};