#pragma once

#include <pp_types.h>
#include <Shader.h>
#include <GL\glew.h>

class GLShader : public Shader
{
public:
	GLShader(const std::string& file);
	~GLShader();

	GLuint			ID() const;
	std::string		FileName() const;
	std::string&	PathToFile();

private:
	std::string Readfile(const std::string& file)	override;

	void Compile();
	void ValidateCompile();
	void TypeFromExtension();

private:
	GLuint			m_id;
	SHADER::TYPE	m_type;
	std::string		m_path;
	std::string		m_raw;
};