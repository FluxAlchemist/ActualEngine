#pragma once


#include <d3d11_3.h>
#include "../Main.h"
#include "Prerequisites.h"

class DllExport IndexBuffer
{
public:
	IndexBuffer(void* list_indices, UINT size_list,RenderSystem * system);
	UINT getSizeIndexList();
	~IndexBuffer();
private:
	UINT m_size_list;
private:
	ID3D11Buffer * m_buffer;
	RenderSystem * m_system = nullptr;
private:
	friend class D3DDraw;
};