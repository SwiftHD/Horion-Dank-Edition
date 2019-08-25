#include "NoWeb.h"



NoWeb::NoWeb() : IModule(0x0, MOVEMENT)
{
}


NoWeb ::~NoWeb()
{
}

const char* NoWeb::getModuleName()
{
	return ("NoWeb");
}

void NoWeb::onTick(C_GameMode* gm) {
	if (gm->player != nullptr)
		gm->player->web = 0.f;
}

