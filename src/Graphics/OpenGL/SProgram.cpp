#include <SProgram.h>

#include <iostream>

SProgram::SProgram(const std::string file)
{
	m_file = file;

	m_program_id = glCreateProgram();

	m_shaders.clear();
	m_attribs.clear();
	m_uniforms.clear();
}

SProgram::~SProgram()
{
	glDeleteProgram(m_program_id);
}

/// <summary>
/// Binds this instance of shaderprogram.
/// </summary>
void SProgram::Bind()
{
	glUseProgram(m_program_id);
}

/// <summary>
/// Unbinds this instance of shaderprogram.
/// </summary>
void SProgram::Unbind()
{
	glUseProgram(NULL);
}

/// <summary>
/// Determines whether [is in use].
/// </summary>
/// <returns>TRUE if program is used, false otherwise</returns>
bool SProgram::IsInUse()
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
void SProgram::GetUniformLocation(const GLchar * name, GLuint & location)
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
void SProgram::Create()
{
	std::string extensions[static_cast<uint8>(SHADER::TYPE::NUM_SHADER_TYPES)] = {".vs",".gs",".tcs",".tes",".fs",".cs"};

	bool vs_loaded;
	bool fs_loaded;

	for (uint8 i = 0; i < static_cast<uint8>(SHADER::TYPE::NUM_SHADER_TYPES); i++)
	{
		Shader* tmp = new Shader(m_file + extensions[i]);
		SHADER::TYPE type;
		
		if (tmp->Load() != false)
		{
			tmp->Compile();
			type = tmp->Type();

			m_shaders.push_back(tmp);

			if (type == SHADER::TYPE::VERTEX_SHADER)
			{
				vs_loaded = true;
			}

			if (type == SHADER::TYPE::FRAGMENT_SHADER)
			{
				fs_loaded = true;
			}
		}
		else
		{
			delete tmp;
		}
	}

	//Compile all loaded shaders if loaded atleast vertex and fragment shader
	if (vs_loaded && fs_loaded)
	{
		for (auto& shader : m_shaders)
		{
			AttachShader(shader);
		}
	}

	glLinkProgram(m_program_id);
}

/// <summary>
/// Detaches shaders.
/// </summary>
void SProgram::Clear()
{
	Unbind();

	for (auto& shader : m_shaders)
	{
		glDetachShader(m_program_id, shader->ID());
		glDeleteShader(shader->ID());
	}

	glDeleteProgram(m_program_id);
}

/// <summary>
/// Attaches a shader to this shader program.
/// </summary>
/// <param name="shader">Shader to attach.</param>
void SProgram::AttachShader(Shader * shader)
{
	if (shader != nullptr)
	{
		glAttachShader(m_program_id, shader->ID());
	}
}

/// <summary>
/// Returns location of specified attribute.
/// </summary>
/// <param name="name">Location</param>
uint8 SProgram::AttribLocation(std::string name)
{
	return (m_attribs.find(name) == m_attribs.end()) ? -1 : m_attribs.find(name)->second;
}

/// <summary>
/// Returns location of specified uniform.
/// </summary>
/// <param name="name">Location</param>
uint8 SProgram::UniLocation(std::string name)
{
	uint8 result = 0;
	if (m_uniforms.find(name) == m_uniforms.end())
	{
		GLint loc = glGetUniformLocation(m_program_id, name.c_str());
		m_uniforms.insert(std::pair<std::string,uint8>(name,loc));
		result = loc;
	}
	else
	{
		result = m_uniforms.find(name)->second;
	} 
	return result;
}

/// <summary>
/// Checks if shader contains specific attribute
/// </summary>
/// <param name="name">Attribute</param>
bool SProgram::HasAttribute(std::string name)
{
	return (m_attribs.find(name) == m_attribs.end()) ? false : true;
}

/// <summary>
/// Checks if shader contains specific uniform
/// </summary>
/// <param name="name">Uniform</param>
bool SProgram::HasUniform(std::string name)
{
	return (m_uniforms.find(name) == m_uniforms.end()) ? false : true;
}


void SProgram::BindUniform(const std::string name, int32 i)
{
	glUniform1i(UniLocation(name), i);
}

void SProgram::BindUniform(const std::string name, float f)
{
	glUniform1f(UniLocation(name), f);
}

void SProgram::BindUniform(const std::string name, float f1, float f2)
{
	glUniform2f(UniLocation(name), f1, f2);
}

void SProgram::BindUniform(const std::string name, float f1, float f2, float f3)
{
	glUniform3f(UniLocation(name), f1, f2, f3);
}

void SProgram::BindUniform(const std::string name, const Vec3& v)
{
	glUniform3f(UniLocation(name), v.x, v.y, v.z);
}

void SProgram::BindUniform(const std::string name, const Vec4& v)
{
	glUniform4f(UniLocation(name), v.x, v.y, v.z, v.w);
}

void SProgram::BindUniform(const std::string name, const Mat3& m)
{
	glUniformMatrix3fv(UniLocation(name), 1, GL_TRUE, glm::value_ptr(m));
}

void SProgram::BindUniform(const std::string name, const Mat4& m)
{
	glUniformMatrix4fv(UniLocation(name), 1, GL_TRUE, glm::value_ptr(m));
}

void SProgram::BindUniform(const std::string name, bool b)
{
	glUniform1i(UniLocation(name), b ? 1 : 0);
}

/// <summary>
/// Validates shader program compilation.
/// </summary>
/// <param name="program">Shader program.</param>
void SProgram::ValidateCompile(GLuint program)
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
void SProgram::ValidateLink(GLuint program)
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
