#include "Step.h"



Step::Step() : IModule('B', MOVEMENT)
{
}


Step::~Step()
{
}

const char* Step::getModuleName()
{
	return ("Step");
}

void Step::onTick(C_GameMode* gm) {
	if(gm->player != nullptr)
		gm->player->stepHeight = 10;
}
void Step::onDisable() {
	if (g_Data.getLocalPlayer() != nullptr) 
		g_Data.getLocalPlayer()->stepHeight = 0.5625f;	
}