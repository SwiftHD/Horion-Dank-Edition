#pragma once
#include "Module.h"
#include "../../DrawUtils.h"

class InfiniteTreasureAura : public IModule
{
private:
	int delay = 15;
	int Odelay = 0;
	bool isMulti = true;
public:
	float range = 100;
	InfiniteTreasureAura();
	~InfiniteTreasureAura();
	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};

