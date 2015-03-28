#pragma once

#include <Graphics\Color.h>
#include <Graphics\Rectangle.h>
#include <Graphics\Camera.h>
#include <pp_types.h>

namespace RENDERER
{
	enum class CLEAR
	{
		COLOR_BUFFER,
		DEPTH_BUFFER,
		STENCIL_BUFFER,
		COLOR_DEPTH_BUFFER,
		COLOR_STENCIL_BUFFER,
		DEPTH_STENCIL_BUFFER,
		COLOR_DEPTH_STENCIL_BUFFER,
		NUM_CLEAR_ARGS
	};
}

class IRenderer
{
public:
	virtual ~IRenderer() {}

	virtual void	Init() = 0;
	virtual void	Shutdown() = 0;
	virtual void	SetClearColor(const Color& c) = 0;
	virtual void	ClearBuffer(RENDERER::CLEAR buf) = 0;
	virtual void	SetProjection(const Mat4& p) = 0;
	virtual void	SetClientRectangle(const Rect& r) = 0;

protected:
	Rect				m_client_rect;
	//Camera*			m_camera3D;
	//Camera*			m_camera2D;
};
