#pragma once


#include "../Main.h"
#include "Material.h"


class DllExport MeshRenderer
{
public:
	MeshRenderer();
	~MeshRenderer();

private:
	Material m_material;
};

