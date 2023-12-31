#pragma once

#include <d3d11_3.h>
#include "../Main.h"
#include "Prerequisites.h"

class DllExport PixelShader
{
public:
	PixelShader(const void* shader_byte_code, size_t byte_code_size,RenderSystem * system);
	~PixelShader();
private:
	ID3D11PixelShader * m_ps;
	RenderSystem * m_system = nullptr;
private:
	friend class RenderSystem;
	friend class D3DDraw;
};