#pragma once
#include "Module.h"
#include "../ModuleManager.h"
#include "../../../Utils/Target.h"

class Hitbox : public IModule
{
public:
	float height = 2;
	float width = 4;
	float range = 8;

	Hitbox();
	~Hitbox();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};

