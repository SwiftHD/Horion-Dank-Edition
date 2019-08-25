#include "RetardCommand.h"



RetardCommand::RetardCommand() : IMCCommand("Retard", "retardcunt", "downy")
{

}


RetardCommand::~RetardCommand()
{
}


bool RetardCommand::execute(std::vector<std::string>* args)
{
	assertTrue(g_Data.getClientInstance()->getLocalPlayer() != nullptr);


	clientMessageF("%sYOU ARE A F*CKING RETARDED C*NT!", RED);
	return true;
}
