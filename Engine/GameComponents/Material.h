#pragma once

#include <list>
#include "../Main.h"
#include "ShaderOld.h"


class DllExport Material
{
public:
	Material();
	~Material();

private:
	ShaderOld shader;
	//TODO: add textures for shader
};

