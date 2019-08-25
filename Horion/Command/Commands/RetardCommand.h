#pragma once
#include "ICommand.h"
class RetardCommand :
	public IMCCommand
{
public:
	RetardCommand();
	~RetardCommand();

	// Inherited via IMCCommand
	virtual bool execute(std::vector<std::string>* args) override;
};
