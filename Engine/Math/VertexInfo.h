#pragma once

#include "../Main.h"
#include "Vector3D.h"
#include "Vector2D.h"

class DllExport VertexInfo
{
public:
	/*
	* Create empty
	*/
	VertexInfo() :m_position(), m_texcoord(), m_normal()
	{
	}

	/*
	* Create with position
	*/
	VertexInfo(Vector3D position) :
		m_position(position),
		m_texcoord(), 
		m_normal()
	{
	}

	/*
	* Create with position and texcoord
	*/
	VertexInfo(Vector3D position, Vector2D texcoord) :
		m_position(position),
		m_texcoord(texcoord),
		m_normal()
	{
	}

	/*
	* Create with position and normal
	*/
	VertexInfo(Vector3D position, Vector3D normal) :
		m_position(position),
		m_texcoord(),
		m_normal(normal)
	{
	}

	/*
	* Create with position, texcoord and normal
	*/
	VertexInfo(Vector3D position, Vector2D texcoord, Vector3D normal) :
		m_position(position),
		m_texcoord(texcoord),
		m_normal(normal)
	{
	}

	/*
	* Create from existing vertexinfo
	*/
	VertexInfo(const VertexInfo& vertex) :
		m_position(vertex.m_position),
		m_texcoord(vertex.m_texcoord),
		m_normal(vertex.m_normal)
	{
	}

	~VertexInfo()
	{
	}

public:
	Vector3D m_position;
	Vector2D m_texcoord;
	Vector3D m_normal;
};