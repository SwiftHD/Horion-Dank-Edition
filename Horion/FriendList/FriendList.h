#pragma once

#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include "../../Memory/GameData.h"


class FriendList {
private:
	//GameData* gameData;
	std::vector<std::string>List;
public:
	FriendList();
	~FriendList();
	static bool findPlayer(std::string Name);
	static void addPlayerToList(std::string name);
	static bool removePlayer(std::string& g);

};

extern FriendList g_friend;
