#pragma once

class Shader
{
public:
	Shader();
	Shader(const wchar_t* filename);

	~Shader();

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