#pragma once

#include <pp_types.h>
#include <GL\glew.h>

#define SHADER_DIR "Shaders/"

namespace SHADER
{
	enum class TYPE
	{
		VERTEX_SHADER,
		GEOMETRY_SHADER,
		TESS_CONTROL_SHADER,
		TESS_EVALUATION_SHADER,
		FRAGMENT_SHADER,
		COMPUTE_SHADER,
		NUM_SHADER_TYPES
	};
}

class Shader
{
public:
	Shader(std::string);
	~Shader();

	GLuint			ID() const;
	SHADER::TYPE	Type() const;
	bool			Load();
	void			Compile();

private:
	void			ValidateCompile();
	SHADER::TYPE	TypeFromExtension();

private:
	GLuint			m_id;
	SHADER::TYPE	m_type;
	std::string		m_file;
	std::string		m_raw;
};