#include <GLShaderProgram.h>

#include <iostream>

GLShaderProgram::GLShaderProgram()
{
	m_vs = nullptr;
	m_gs = nullptr;
	m_tcs = nullptr;
	m_tes = nullptr;
	m_fs = nullptr;
	m_cs = nullptr;

	m_program_id = glCreateProgram();
}

GLShaderProgram::~GLShaderProgram()
{
	glDeleteProgram(m_program_id);
}

/// <summary>
/// Binds this instance of shaderprogram.
/// </summary>
void GLShaderProgram::Bind()
{
	glUseProgram(m_program_id);
}

/// <summary>
/// Unbinds this instance of shaderprogram.
/// </summary>
void GLShaderProgram::Unbind()
{
	glUseProgram(NULL);
}

/// <summary>
/// Determines whether [is in use].
/// </summary>
/// <returns>TRUE if program is used, false otherwise</returns>
bool GLShaderProgram::IsInUse()
{
	GLint cur_program = NULL;
	glGetIntegerv(GL_CURRENT_PROGRAM, &cur_program);

	if (cur_program == m_program_id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Gets the uniform variable location in shader program.
/// </summary>
/// <param name="name">Name of the variable in shader.</param>
/// <param name="location">Location of variable.</param>
void GLShaderProgram::GetUniformLocation(const GLchar * name, GLuint & location)
{
	location = glGetUniformLocation(m_program_id, name);
	if (location < 0)
	{
		std::cerr << "Failed to locate uniform variable in program\n";
	}
}

/// <summary>
/// Loads shaders, compiles them.
/// </summary>
void GLShaderProgram::Create()
{
	std::string path;

	/*for (auto& i: m_args)
	{
		switch ()
		{
		case SHADER::TYPE::VERTEX_SHADER:
			if (m_vs == nullptr)
			{
				m_vs = new GLShader(path);
				AttachShader(m_vs);
			}
			break;

		case SHADER::TYPE::GEOMETRY_SHADER:
			if (m_gs == nullptr)
			{
				m_gs = new GLShader(path);
				AttachShader(m_gs);
			}
			break;

		case SHADER::TYPE::TESS_CONTROL_SHADER:
			if (m_tcs == nullptr)
			{
				m_tcs = new GLShader(path);
				AttachShader(m_tcs);
			}
			break;

		case SHADER::TYPE::TESS_EVALUATION_SHADER:
			if (m_tes == nullptr)
			{
				m_tes = new GLShader(path);
				AttachShader(m_tes);
			}
			break;

		case SHADER::TYPE::FRAGMENT_SHADER:
			if (m_fs == nullptr)
			{
				m_fs = new GLShader(path);
				AttachShader(m_fs);
			}
			break;

		case SHADER::TYPE::COMPUTE_SHADER:
			if (m_cs == nullptr)
			{
				m_cs = new GLShader(path);
				AttachShader(m_cs);
			}
			break;

		default:
			break;
		}
	}*/

	glLinkProgram(m_program_id);
}

/// <summary>
/// Attaches a shader to this shader program.
/// </summary>
/// <param name="shader">Shader to attach.</param>
void GLShaderProgram::AttachShader(Shader * shader)
{
	if (shader != nullptr)
	{
		glAttachShader(m_program_id, ((GLShader*)shader)->ID());
	}
}

/// <summary>
/// Validates shader program compilation.
/// </summary>
/// <param name="program">Shader program.</param>
void GLShaderProgram::ValidateCompile(GLuint program)
{
	GLint compiled;
	glGetProgramiv(program, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		GLsizei length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		GLchar* log = new GLchar[length + 1];
		glGetProgramInfoLog(program, length, &length, log);

		std::cerr << "Shader program linking failed:\n" << log << std::endl;

		delete[] log;
	}
}

/// <summary>
/// Validates shader program linking.
/// </summary>
/// <param name="program">Shader program.</param>
void GLShaderProgram::ValidateLink(GLuint program)
{
	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		GLsizei length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		GLchar* log = new GLchar[length + 1];
		glGetProgramInfoLog(program, length, &length, log);

		std::cerr << "Shader program linking failed:\n" << log << std::endl;

		delete[] log;
	}
}
