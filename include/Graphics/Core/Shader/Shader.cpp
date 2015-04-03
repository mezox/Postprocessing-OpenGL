#include <Shader.h>

#include <iostream>
#include <fstream>
#include <algorithm>

Shader::Shader(std::string file)
{
	m_file = file;
}

Shader::~Shader()
{
	glDeleteShader(m_id);
}

/// <summary>
/// Loads shader source code from file.
/// </summary>
/// <param name="file">File name or path to file.</param>
/// <returns>Shader source code</returns>
bool Shader::Load()
{
	std::ifstream input;
	input.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::string shader_code;

	std::cout << "Opening " + (SHADER_DIR + m_file) + " \t";

	try
	{
		input.open((SHADER_DIR + m_file).c_str());
		shader_code.assign((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

		std::cout << "[Success]\n";
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "[Not Found]\n";
		return false;
	}

	m_raw = shader_code;

	return true;
}

/// <summary>
/// Creates and compiles shader.
/// </summary>
void Shader::Compile()
{
	m_type = TypeFromExtension();

	GLenum type;

	switch (m_type)
	{
	case SHADER::TYPE::VERTEX_SHADER:
		type = GL_VERTEX_SHADER;
		break;

	case SHADER::TYPE::GEOMETRY_SHADER:
		type = GL_GEOMETRY_SHADER;
		break;

	case SHADER::TYPE::TESS_CONTROL_SHADER:
		type = GL_TESS_CONTROL_SHADER;
		break;

	case SHADER::TYPE::TESS_EVALUATION_SHADER:
		type = GL_TESS_EVALUATION_SHADER;
		break;

	case SHADER::TYPE::FRAGMENT_SHADER:
		type = GL_FRAGMENT_SHADER;
		break;

	case SHADER::TYPE::COMPUTE_SHADER:
		type = GL_COMPUTE_SHADER;
		break;

	default:
		type = GL_NONE;
		break;
	}

	m_id = glCreateShader(type);

	if (m_id == 0)
	{
		throw std::runtime_error("glCreateShader failed");
	}

	const char * code = m_raw.c_str();

	glShaderSource(m_id, 1, (const GLchar**)&code, NULL);
	glCompileShader(m_id);

	ValidateCompile();
}

/// <summary>
/// Validates shader compilation.
/// </summary>
void Shader::ValidateCompile()
{
	GLint compiled;

	glGetShaderiv(m_id, GL_COMPILE_STATUS, &compiled);

	if (!compiled)
	{
		GLsizei length;
		glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &length);

		GLchar* log = new GLchar[length + 1];
		glGetShaderInfoLog(m_id, length, &length, log);

		std::cerr << log << std::endl;

		delete[] log;

		glDeleteShader(m_id);
	}
}

/// <summary>
/// Extracts shader type from shader file extension [vs|gs|tcs|tes|fs|cs].
/// </summary>
SHADER::TYPE Shader::TypeFromExtension()
{
	std::string ext;
	std::string::size_type idx;

	idx = m_file.rfind('.');

	if (idx != std::string::npos)
	{
		ext = m_file.substr(idx + 1);
	}
	else
	{
		std::cerr << "Couldn't extract shader type from file name!\n";
	}

	if (ext == "vs")
	{
		return SHADER::TYPE::VERTEX_SHADER;
	}
	else if (ext == "gs")
	{
		return SHADER::TYPE::GEOMETRY_SHADER;
	}
	else if (ext == "tcs")
	{
		return SHADER::TYPE::TESS_CONTROL_SHADER;
	}
	else if (ext == "tes")
	{
		return SHADER::TYPE::TESS_EVALUATION_SHADER;
	}
	else if (ext == "fs")
	{
		return SHADER::TYPE::FRAGMENT_SHADER;
	}
	else if (ext == "cs")
	{
		return SHADER::TYPE::COMPUTE_SHADER;
	}
	else
	{
		std::cerr << "Invalid extension of shader file!\n";
	}
}

/// <summary>
/// Identifiers shader instance.
/// </summary>
/// <returns>Shader ID</returns>
GLuint Shader::ID() const
{
	return m_id;
}

/// <summary>
/// Returns shader type.
/// </summary>
/// <returns></returns>
SHADER::TYPE Shader::Type() const
{
	return m_type;
}