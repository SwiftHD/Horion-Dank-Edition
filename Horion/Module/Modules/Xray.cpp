#include "Xray.h"



Xray::Xray() : IModule(VK_NUMPAD6, VISUAL)
{
}


Xray::~Xray()
{
}

const char* Xray::getModuleName()
{
	return ("X-Ray");
}