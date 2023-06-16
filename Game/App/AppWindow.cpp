#include "AppWindow.h"
#include <Math/VertexInfo.h>
#include <vector>


__declspec(align(16))
struct constant
{
	Matrix4x4 m_world;
	Matrix4x4 m_view;
	Matrix4x4 m_proj;
	Vector4D m_light_direction;
	Vector4D m_camera_position = Vector4D(0, 0, 4, 0);
	Vector4D m_light_position = Vector4D(0, 1, 0, 0);
	float m_light_radius = 4.0f;
	float m_time = 0.0f;

};

AppWindow::AppWindow()
{
	//TODO: move
	m_render_system = new RenderSystem();
	m_shader = new ShaderOld();
	m_shader->m_filename = L"TestShader.hlsl";
}


// new functions:

void AppWindow::render()
{
	m_render_system->getD3DDraw()->clearRenderTargetColor(this->m_swap_chain,
		0, 0.3f, 0.4f, 1);
	//SET VIEWPORT OF RENDER TARGET IN WHICH WE HAVE TO DRAW
	RECT rc = this->getClientWindowRect();
	m_render_system->getD3DDraw()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);

	//Update matrices
	update();

	//Render a thing
	m_render_system->setRasterizerState(false);
	drawSomething(m_vs, m_ps, m_cb);

	m_swap_chain->present(true);
	m_old_delta = m_new_delta;
	m_new_delta = ::GetTickCount();

	m_delta_time = (m_old_delta) ? ((m_new_delta - m_old_delta) / 1000.0f) : 0;
	m_time += m_delta_time;
}

void AppWindow::update()
{
	updateCamera();
	updateModel();
	updateSkyBox();
}

void AppWindow::updateCamera()
{
	Matrix4x4 world_cam, temp;
	world_cam.setIdentity();

	temp.setIdentity();
	temp.setRotationX(m_rot_x);
	world_cam *= temp;

	temp.setIdentity();
	m_rot_y = sinf(m_time);
	temp.setRotationY(m_rot_y);
	world_cam *= temp;

	Vector3D new_pos = m_world_cam.getTranslation() + world_cam.getZDirection() * (m_forward * 0.05f);

	new_pos = new_pos + world_cam.getXDirection() * (m_rightward * 0.05f);

	world_cam.setTranslation(new_pos);

	m_world_cam = world_cam;

	world_cam.inverse();

	m_view_cam = world_cam;

	int width = (this->getClientWindowRect().right - this->getClientWindowRect().left);
	int height = (this->getClientWindowRect().bottom - this->getClientWindowRect().top);

	m_proj_cam.setPerspectiveFovLH(1.57f, ((float)width / (float)height), 0.1f, 100.0f);
}


void AppWindow::updateModel()
{
	constant cc;

	Matrix4x4 m_light_rot_matrix;
	m_light_rot_matrix.setIdentity();
	m_light_rot_matrix.setRotationY(m_light_rot_y);

	m_light_rot_y += 1.57f * m_delta_time;

	cc.m_world.setIdentity();
	cc.m_view = m_view_cam;
	cc.m_proj = m_proj_cam;
	cc.m_camera_position = m_world_cam.getTranslation();

	float dist_from_origin = 1.0f;

	cc.m_light_position = Vector4D(cos(m_light_rot_y) * dist_from_origin, 3.1f, sin(m_light_rot_y) * dist_from_origin, 1.0f);

	cc.m_light_radius = m_light_radius;
	cc.m_light_direction = m_light_rot_matrix.getZDirection();
	cc.m_time = m_time;

	m_cb->update(m_render_system->getD3DDraw(), &cc);
}

void AppWindow::updateSkyBox()
{
	//nothing yet
}

void AppWindow::drawSomething(const VertexShaderPtr& vs, const PixelShaderPtr& ps, const ConstantBufferPtr& cb)
{
	m_render_system->getD3DDraw()->setConstantBuffer(vs, cb);
	m_render_system->getD3DDraw()->setConstantBuffer(ps, cb);

	//SET DEFAULT SHADER IN THE GRAPHICS PIPELINE TO BE ABLE TO DRAW
	m_render_system->getD3DDraw()->setVertexShader(vs);
	m_render_system->getD3DDraw()->setPixelShader(ps);

	// fill vertices with position and normals
	std::vector<VertexInfo> vertices =
	{
		VertexInfo(Vector3D(0,0,0), Vector3D(0,0,1)),
		VertexInfo(Vector3D(1,0,0), Vector3D(0,0,1)),
		VertexInfo(Vector3D(0,1,0), Vector3D(0,0,1)),
		VertexInfo(Vector3D(0,1,0), Vector3D(0,0,-1)),
		VertexInfo(Vector3D(1,0,0), Vector3D(0,0,-1)),
		VertexInfo(Vector3D(0,0,0), Vector3D(0,0,-1)),
	};

	// make 2 triangles facing in different directions
	std::vector<unsigned int> indices =
	{
		0,1,2,
		3,4,5
	};

	m_vertex_buffer = m_render_system->createVertexBuffer(&vertices, sizeof(VertexInfo),
		(UINT)vertices.size());
	m_render_system->getD3DDraw()->setVertexBuffer(m_vertex_buffer);
	
	m_index_buffer = m_render_system->createIndexBuffer(&indices,
		(UINT)indices.size());
	m_render_system->getD3DDraw()->setIndexBuffer(m_index_buffer);

	m_render_system->getD3DDraw()->drawIndexedTriangleList(m_index_buffer->getSizeIndexList(), 0, 0);
}

// overriden:

void AppWindow::onCreate()
{
	Window::onCreate();
	m_play_state = true;


	RECT rc = this->getClientWindowRect();
	m_swap_chain = m_render_system->createSwapChain(this->m_hwnd, rc.right - rc.left, rc.bottom - rc.top);

	m_world_cam.setTranslation(Vector3D(0, 0, -1));

	ShaderOld* shader = new ShaderOld(L".//Resources//TestShader.hlsl");
	shader->compilePixelShader();
	shader->compileVertexShader();

	m_vs = shader->createVertexShader(m_render_system);
	m_ps = shader->createPixelShader(m_render_system);

	constant cc;

	m_cb = m_render_system->createConstantBuffer(&cc, sizeof(constant));

	m_world_cam.setTranslation(Vector3D(0, 0, -2));

}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	this->render();
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_swap_chain->setFullScreen(false, 1, 1);
}

void AppWindow::onFocus()
{
	Window::onFocus();
}

void AppWindow::onKillFocus()
{
	Window::onKillFocus();
}

void AppWindow::onSize()
{
	RECT rc = this->getClientWindowRect();
	m_swap_chain->resize(rc.right, rc.bottom);
	this->render();
}

// dispose
AppWindow::~AppWindow()
{
}