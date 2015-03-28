#pragma once

#include <Graphics\Renderer.h>
#include <GLCamera3D.h>
#include <Model.h>

class GLRenderer : public IRenderer
{
public:
	void	Init()									override;
	void	Shutdown()								override;
	void	SetClearColor(const Color& c)			override;
	void	ClearBuffer(RENDERER::CLEAR buf)		override;
	void	SetProjection(const Mat4& p)			override;
	void	SetClientRectangle(const Rect& r)		override;

	void	Render(Model* model);

	Camera* GetCamera3D() const;

private:
	GLCamera3D*	m_camera3D;
};