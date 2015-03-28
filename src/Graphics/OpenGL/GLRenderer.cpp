#include <GLRenderer.h>
#include <GLCamera3D.h>
#include <GL\glew.h>
#include <pp_types.h>
#include <iostream>

void GLRenderer::Init()
{
	GLenum err = glewInit();

	if (err != GLEW_OK)
	{
		std::cout << "Glew Error: -> " << glewGetErrorString(err) << std::endl;
		return;
	}

	glDisable(GL_DEPTH_TEST);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_camera3D = new GLCamera3D();
	m_camera3D->SetPerspective(static_cast<float>(1280) / static_cast<float>(720), 45.0f, 1.0f, 1000.0f);
	m_camera3D->SetView(Vec3(0.0f, 0.0f, 4.0f), Vec3(0.0f, 0.0f, -1.0f), Vec3(0.0f, 1.0f, 0.0f));
}

void GLRenderer::Shutdown()
{
	delete m_camera3D;
}

void GLRenderer::SetClearColor(const Color& c)
{
	glClearColor(c.r, c.g, c.b, c.a);
}

void GLRenderer::ClearBuffer(RENDERER::CLEAR arg)
{
	switch (arg)
	{
	case RENDERER::CLEAR::COLOR_BUFFER:
		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case RENDERER::CLEAR::DEPTH_BUFFER:
		glClear(GL_DEPTH_BUFFER_BIT);
		break;

	case RENDERER::CLEAR::STENCIL_BUFFER:
		glClear(GL_STENCIL_BUFFER_BIT);
		break;

	case RENDERER::CLEAR::COLOR_DEPTH_BUFFER:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		break;

	case RENDERER::CLEAR::COLOR_STENCIL_BUFFER:
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		break;

	case RENDERER::CLEAR::DEPTH_STENCIL_BUFFER:
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		break;

	case RENDERER::CLEAR::COLOR_DEPTH_STENCIL_BUFFER:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		break;
	}
}

/// <summary>
/// Sets the projection.
/// </summary>
/// <param name="p">The p.</param>
void GLRenderer::SetProjection(const Mat4& p)
{
	m_camera3D->SetProjection(p);
}

/// <summary>
/// Sets the client rectangle.
/// </summary>
/// <param name="r">The r.</param>
void GLRenderer::SetClientRectangle(const Rect& r)
{
	m_client_rect = r;
}

void GLRenderer::Render(Model * model)
{
	glBindVertexArray(model->VAO());
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
