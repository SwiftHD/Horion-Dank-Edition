#include "InfiniteBlockReach.h"



InfiniteBlockReach::InfiniteBlockReach() : IModule(0x0, PLAYER)
{
	this->registerFloatSetting(std::string("reach"), &this->blockReach, this->blockReach, 7, 100);
}


InfiniteBlockReach::~InfiniteBlockReach()
{
}

const char* InfiniteBlockReach::getModuleName()
{
	return ("InfiniteBlockReach");
}