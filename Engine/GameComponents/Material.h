


#pragma once
#include "Shader.h"
#include <list>


class Material
{
public:
	Material();
	~Material();

private:
	Shader shader;
	//TODO: add textures for shader
};

