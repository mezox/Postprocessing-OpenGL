#pragma once

#include <Graphics\Renderer.h>

class GLRenderPass
{
public:
	void Init(std::string programName);
	GLuint GetFrameBuffer();
	SProgram *GetProgram();
	bool IsActive();
	void Activate();
	void Deactivate();
	void ToggleActive();
private:
	SProgram *m_program;
	GLuint m_frameBuffer;
	bool m_active;
};