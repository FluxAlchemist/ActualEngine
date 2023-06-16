
#pragma once
#include <d3d11_3.h>
#include "Prerequisites.h"
#include "../GameComponents/ShaderOld.h"


class RenderSystem
{
public:
	//Initialize the GraphicsEngine and DirectX 11 Device
	RenderSystem();
	//Release all the resources loaded
	~RenderSystem();

public:
	SwapChainPtr createSwapChain(HWND hwnd, UINT width, UINT height);
	D3DDrawPtr getD3DDraw();
	VertexBufferPtr createVertexBuffer(void* list_vertices, UINT size_vertex, UINT size_list);
	IndexBufferPtr createIndexBuffer(void* list_indices, UINT size_list);
	ConstantBufferPtr createConstantBuffer(void* buffer, UINT size_buffer);

	void setRasterizerState(bool cull_front);
	void initRasterizerState();

private:
	D3DDrawPtr m_d3d_draw;

private:
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;

private:
	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;
	ID3D11DeviceContext* m_imm_context;

private:
	ShaderOld* m_layout_shader = nullptr;
	void* m_layout_shader_byte_code = nullptr;
	size_t m_layout_shader_size = 0;

	ID3D11RasterizerState* m_cull_front_state = nullptr;
	ID3D11RasterizerState* m_cull_back_state = nullptr;

private:
	friend class SwapChain;
	friend class VertexBuffer;
	friend class IndexBuffer;
	friend class ConstantBuffer;
	friend class VertexShader;
	friend class PixelShader;
	friend class Texture;
};