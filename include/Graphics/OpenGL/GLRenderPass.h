#pragma once

#include <Graphics\Renderer.h>

class GLRenderPass
{
public:
	void Init(std::string programName);
	GLuint GetFrameBuffer();
	SProgram *GetProgram();
private:
	SProgram *m_program;
	GLuint m_frameBuffer;
};