#pragma once

#include "../../Memory/GameData.h"

#include "Commands/ICommand.h"
#include "Commands/EjectCommand.h"
#include "Commands/TeleportCommand.h"
#include "Commands/BindCommand.h"
#include "Commands/RelativeTeleportCommand.h"
#include "Commands/ToggleCommand.h"
#include "Commands/PlayerTeleportCommand.h"
#include "Commands/GameModeCommand.h"
#include "Commands/FriendListCommand.h"
#include "Commands/UnbindCommand.h"
#include "Commands/EnchantCommand.h"
#include "Commands/HelpCommand.h"
#include "Commands/ModulesCommand.h"
#include "Commands/PanicCommand.h"
#include "Commands/HideCommand.h"
#include "Commands/GiveCommand.h"
#include "Commands/BruhCommand.h"
#include "Commands/setoffhandCommand.h"
#include "Commands/CoordsCommand.h"
#include "Commands/SayCommand.h"
#include "Commands/RetardCommand.h"

#ifdef _DEBUG
#include "Commands/TestCommand.h"
#endif

#include <string>
#include <vector>
#include <algorithm>

class CommandMgr {
private:
	GameData* gameData;
	std::vector<IMCCommand*> commandList;
public:
	CommandMgr(GameData* gm);
	~CommandMgr();
	
	void initCommands();
	void disable();
	std::vector<IMCCommand*>* getCommandList();

	void execute(char* message);
};

extern CommandMgr* cmdMgr;
