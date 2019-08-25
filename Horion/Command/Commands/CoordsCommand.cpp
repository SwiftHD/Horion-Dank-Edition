#include "CoordsCommand.h"

CoordsCommand::CoordsCommand() : IMCCommand("coords", "Prints your coordinates", "")
{
	registerAlias("pos");
}

CoordsCommand::~CoordsCommand()
{
}

bool CoordsCommand::execute(std::vector<std::string>* args)
{
	vec3_t* pos = g_Data.getLocalPlayer()->getPos();
	clientMessageF("[%sHorion%s] %sX: %.1f Y: %.1f Z: %.1f", GOLD, WHITE, GREEN, pos->x, (float) (pos->y - 1.62f) /* eye height */, pos->z);
	return true;
}
