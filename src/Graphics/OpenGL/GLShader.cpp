#include <Graphics\GLShader.h>

#include <iostream>
#include <fstream>
#include <algorithm>

GLShader::GLShader(const std::string& file)
{
	m_path = file;
	m_raw = Readfile(file);

	Compile();
}

GLShader::~GLShader()
{
	glDeleteShader(m_id);
}

/// <summary>
/// Loads shader source code from file.
/// </summary>
/// <param name="file">File name or path to file.</param>
/// <returns>Shader source code</returns>
std::string GLShader::Readfile(const std::string& file)
{
	std::ifstream input;
	input.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::string shader_code;

	try
	{
		input.open(file.c_str());
	
		shader_code.assign((std::istreambuf_iterator<char>(input)),(std::istreambuf_iterator<char>()));
	}
	catch(std::ifstream::failure e)
	{
		std::cerr << "Exception opening/reading/closing file\n";
	}

	return shader_code;
}

/// <summary>
/// Creates and compiles shader.
/// </summary>
void GLShader::Compile()
{
	TypeFromExtension();

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
void GLShader::ValidateCompile()
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
void GLShader::TypeFromExtension()
{
	std::string ext;
	std::string::size_type idx;

	idx = m_path.rfind('.');

	if (idx != std::string::npos)
	{
		ext = m_path.substr(idx + 1);
	}
	else
	{
		std::cerr << "Couldn't extract shader type from file name!\n";
		return;
	}

	if (ext == "vs")
	{
		m_type = SHADER::TYPE::VERTEX_SHADER;
	}
	else if (ext == "gs")
	{
		m_type = SHADER::TYPE::GEOMETRY_SHADER;
	}
	else if (ext == "tcs")
	{
		m_type = SHADER::TYPE::TESS_CONTROL_SHADER;
	}
	else if (ext == "tes")
	{
		m_type = SHADER::TYPE::TESS_EVALUATION_SHADER;
	}
	else if (ext == "fs")
	{
		m_type = SHADER::TYPE::FRAGMENT_SHADER;
	}
	else if (ext == "cs")
	{
		m_type = SHADER::TYPE::COMPUTE_SHADER;
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
GLuint GLShader::ID() const
{
	return m_id;
}

/// <summary>
/// Shader name getter.
/// </summary>
/// <returns>Shader filename</returns>
std::string GLShader::FileName() const
{
	std::string file;
	const std::string::size_type last_slash_idx = m_path.find_last_of("\\/");
	
	if (std::string::npos != last_slash_idx)
	{
		return { std::find_if(m_path.rbegin(), m_path.rend(),[](char c) { return c == '/'; }).base(), m_path.end() };
	}
}

/// <summary>
/// Shader source file path getter.
/// </summary>
/// <returns>Path to shader source file</returns>
std::string& GLShader::PathToFile()
{
	return m_path;
}
