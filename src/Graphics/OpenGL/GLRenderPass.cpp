#include "GLRenderer.h"
#include "IAppWindow.h"
#include "GLRenderPass.h"

GLuint	GLRenderPass::GetFrameBuffer()
{
	return m_frameBuffer;
}

void GLRenderPass::Init(std::string programName)
{
	m_program = new SProgram(programName);
	m_program->Create();
	m_active = true;

	GLuint texture;
	glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_WRAP_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_WRAP_BORDER);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, IAppWindow::DEF_WINDOW_WIDTH, IAppWindow::DEF_WINDOW_HEIGHT,
				 0, GL_RGBA, GL_FLOAT, NULL);

    glGenFramebuffers(1, &m_frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);  
}

void GLRenderPass::ToggleActive()
{
	m_active = !m_active;
}

bool GLRenderPass::IsActive()
{
	return m_active;
}

void GLRenderPass::Activate()
{
	m_active = true;
}

void GLRenderPass::Deactivate()
{
	m_active = false;
}

SProgram *GLRenderPass::GetProgram()
{
	return m_program;
}