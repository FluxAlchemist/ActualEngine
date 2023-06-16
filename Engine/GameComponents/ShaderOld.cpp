#include "ShaderOld.h"
#include <d3dcompiler.h>

#define SHADER_ENTRY_VERTEX "vsmain"
#define SHADER_ENTRY_PIXEL "psmain"

ShaderOld::ShaderOld()
{
}

ShaderOld::ShaderOld(const wchar_t* filename)
{
	m_filename = filename;
}

ShaderOld::~ShaderOld()
{
	if (m_blob_pixel) m_blob_pixel->Release();
	if (m_blob_vertex) m_blob_pixel->Release();
}

bool ShaderOld::compileVertexShader(void** shader_byte_code, size_t* byte_code_size)
{
	if (!compileVertexShader())
		return false;

	*shader_byte_code = m_blob_vertex->GetBufferPointer();
	*byte_code_size = m_blob_vertex->GetBufferSize();

	return true;
}

bool ShaderOld::compilePixelShader(void** shader_byte_code, size_t* byte_code_size)
{
	if (!compilePixelShader())
		return false;

	*shader_byte_code = m_blob_pixel->GetBufferPointer();
	*byte_code_size = m_blob_pixel->GetBufferSize();

	return true;
}

bool ShaderOld::compileVertexShader()
{
	ID3DBlob* error_blob = nullptr;
	if (!SUCCEEDED(D3DCompileFromFile(m_filename, nullptr, nullptr, SHADER_ENTRY_VERTEX, "vs_5_0", 0, 0, &m_blob_vertex, &error_blob)))
	{
		if (error_blob) error_blob->Release();
		return false;
	}

	return true;
}

bool ShaderOld::compilePixelShader()
{
	ID3DBlob* error_blob = nullptr;
	if (!SUCCEEDED(D3DCompileFromFile(m_filename, nullptr, nullptr, SHADER_ENTRY_PIXEL, "vs_5_0", 0, 0, &m_blob_pixel, &error_blob)))
	{
		if (error_blob) error_blob->Release();
		return false;
	}

	return true;
}

VertexShaderPtr ShaderOld::createVertexShader(RenderSystem* renderSystem)
{
	VertexShaderPtr vs = nullptr;
	try
	{
		vs = std::make_shared<VertexShader>(
			m_blob_vertex->GetBufferPointer(), 
			m_blob_vertex->GetBufferSize(),
			renderSystem);
	}
	catch (...) {}
	m_blob_vertex->Release();
	return vs;
}

PixelShaderPtr ShaderOld::createPixelShader(RenderSystem* renderSystem)
{
	PixelShaderPtr ps = nullptr;
	try
	{
		ps = std::make_shared<PixelShader>(
			m_blob_pixel->GetBufferPointer(),
			m_blob_pixel->GetBufferSize(),
			renderSystem);
	}
	catch (...) {}
	m_blob_pixel->Release();
	return ps;
}
