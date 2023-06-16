


#pragma once
#include "ShaderOld.h"
#include <list>


class Material
{
public:
	Material();
	~Material();

private:
	ShaderOld shader;
	//TODO: add textures for shader
};

