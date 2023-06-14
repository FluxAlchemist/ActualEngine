#pragma once
#include "Window.h"

#include <Rendering/RenderSystem.h>
#include <Rendering/D3DDraw.h>
#include <Rendering/SwapChain.h>

#include <Rendering/VertexShader.h>
#include <Rendering/PixelShader.h>

#include <Rendering/ConstantBuffer.h>
#include <Rendering/IndexBuffer.h>
#include <Rendering/VertexBuffer.h>

#include <Math/Matrix4x4.h>
#include <GameComponents/Shader.h>



class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
	virtual void onFocus() override;
	virtual void onKillFocus() override;
	virtual void onSize() override;

public:
	void render();
	void update();
	void updateCamera();
	void updateModel();
	void updateSkyBox();

	void drawSomething(const VertexShaderPtr& vs, const PixelShaderPtr& ps, const ConstantBufferPtr& cb);

private:
	//TODO: propbably move to a resource management class
	RenderSystem* m_render_system;
	VertexBufferPtr m_vertex_buffer;
	IndexBufferPtr m_index_buffer;
	//temp af:
	Shader* m_shader;
	VertexShaderPtr m_vs;
	PixelShaderPtr m_ps;

	//already finished stuff:
	SwapChainPtr m_swap_chain;
	ConstantBufferPtr m_cb;

private:
	long m_old_delta;
	long m_new_delta;
	float m_delta_time;

	float m_delta_pos;
	float m_delta_scale;
	float m_delta_rot;

	float m_rot_x = 0.0f;
	float m_rot_y = 0.0f;

	float m_light_rot_y = 0.0f;


	float m_scale_cube = 1;
	float m_forward = 0.0f;
	float m_rightward = 0.0f;

	bool cull = true;
	Matrix4x4 m_world_cam;
	Matrix4x4 m_view_cam;
	Matrix4x4 m_proj_cam;

	float m_time = 0.0f;
	float m_light_radius = 4.0f;
	float m_attenuation = 2.0f;
	bool m_anim = false;

	bool m_play_state = false;
	bool m_fullscreen_state = false;
};