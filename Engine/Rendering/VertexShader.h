#pragma once


#include <d3d11_3.h>
#include "../Main.h"
#include "Prerequisites.h"

class DllExport VertexShader
{
public:
	VertexShader(const void* shader_byte_code, size_t byte_code_size, RenderSystem* system);
	~VertexShader();
private:
	ID3D11VertexShader* m_vs;
	RenderSystem* m_system = nullptr;
private:
	friend class RenderSystem;
	friend class D3DDraw;
};

