#pragma once
#include <memory>

class SwapChain;
class D3DDraw;
class VertexBuffer;
class IndexBuffer;
class ConstantBuffer;
class VertexShader;
class PixelShader;

class RenderSystem;
//class GraphicsEngine;

//class Resource;
//class ResourceManager;
//class Texture;
//class TextureManager;
//class Mesh;
//class MeshManager;


typedef std::shared_ptr<SwapChain> SwapChainPtr;
typedef std::shared_ptr<D3DDraw> D3DDrawPtr;
typedef std::shared_ptr<VertexBuffer> VertexBufferPtr;
typedef std::shared_ptr<IndexBuffer> IndexBufferPtr;
typedef std::shared_ptr<ConstantBuffer> ConstantBufferPtr;
typedef std::shared_ptr<VertexShader> VertexShaderPtr;
typedef std::shared_ptr<PixelShader> PixelShaderPtr;

//typedef std::shared_ptr<Resource> ResourcePtr;
//typedef std::shared_ptr<Texture> TexturePtr;
//typedef std::shared_ptr<Mesh> MeshPtr;