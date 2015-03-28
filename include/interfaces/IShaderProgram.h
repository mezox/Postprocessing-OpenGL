#pragma once

#include <Shader.h>
#include <array>

class IShaderProgram
{
public:
	virtual ~IShaderProgram() {}

protected:
	virtual	void Create() = 0;

protected:
	Shader*	m_vs;
	Shader*	m_gs;
	Shader*	m_tcs;
	Shader*	m_tes;
	Shader*	m_fs;
	Shader*	m_cs;
};