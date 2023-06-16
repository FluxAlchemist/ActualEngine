#pragma once


#include <memory>
#include "../Main.h"

class DllExport SwapChain;
class DllExport D3DDraw;
class DllExport VertexBuffer;
class DllExport IndexBuffer;
class DllExport ConstantBuffer;
class DllExport VertexShader;
class DllExport PixelShader;

class DllExport RenderSystem;
//class DllExport GraphicsEngine;

//class DllExport Resource;
//class DllExport ResourceManager;
//class DllExport Texture;
//class DllExport TextureManager;
//class DllExport Mesh;
//class DllExport MeshManager;


typedef DllExport std::shared_ptr<SwapChain> SwapChainPtr;
typedef DllExport std::shared_ptr<D3DDraw> D3DDrawPtr;
typedef DllExport std::shared_ptr<VertexBuffer> VertexBufferPtr;
typedef DllExport std::shared_ptr<IndexBuffer> IndexBufferPtr;
typedef DllExport std::shared_ptr<ConstantBuffer> ConstantBufferPtr;
typedef DllExport std::shared_ptr<VertexShader> VertexShaderPtr;
typedef DllExport std::shared_ptr<PixelShader> PixelShaderPtr;

//typedef std::shared_ptr<Resource> ResourcePtr;
//typedef std::shared_ptr<Texture> TexturePtr;
//typedef std::shared_ptr<Mesh> MeshPtr;