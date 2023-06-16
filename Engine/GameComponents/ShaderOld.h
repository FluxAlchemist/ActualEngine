#pragma once


#include <d3dcompiler.h>
#include "../Main.h"
#include "../Rendering/VertexShader.h"
#include "../Rendering/PixelShader.h"
#include "../Rendering/Prerequisites.h"

class DllExport ShaderOld
{
public:
	ShaderOld();
	ShaderOld(const wchar_t* filename);

	~ShaderOld();

private:
	bool compileVertexShader(void** shader_byte_code, size_t* byte_code_size);
	bool compilePixelShader(void** shader_byte_code, size_t* byte_code_size);
	//TODO: GeometryShader (computeshader?)

	bool compileVertexShader();
	bool compilePixelShader();
	//TODO: GeometryShader (computeshader?)

	VertexShaderPtr createVertexShader(RenderSystem* renderSystem);
	PixelShaderPtr createPixelShader(RenderSystem* renderSystem);
	//TODO: GeometryShader (computeshader?)

private:
	const wchar_t* m_filename;

private:
	ID3DBlob* m_blob_vertex = nullptr;
	ID3DBlob* m_blob_pixel = nullptr;

private:
	friend class RenderSystem;
	//TODO: temp af
	friend class AppWindow;
};