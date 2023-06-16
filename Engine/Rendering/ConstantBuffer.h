#pragma once


#include <d3d11_3.h>
#include "../Main.h"
#include "Prerequisites.h"

class DllExport ConstantBuffer
{
public:
	ConstantBuffer(void* buffer, UINT size_buffer, RenderSystem* system);
	void update(D3DDrawPtr context, void* buffer);
	~ConstantBuffer();
private:
	ID3D11Buffer* m_buffer;
	RenderSystem* m_system = nullptr;
private:
	friend class D3DDraw;
};