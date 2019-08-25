#pragma once

#include "Module.h"
#include "../../DrawUtils.h"
#include "../../../Utils/Target.h"

class ESP : public IModule
{
public:
	bool isMobEsp = false;
	bool doRainbow = true;
	ESP();
	~ESP();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onPostRender() override;
};

