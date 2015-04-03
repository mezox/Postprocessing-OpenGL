#pragma once

#include <Shader.h>
#include <INonCopy.h>

#include <map>
#include <vector>

#define	SHADER_GLOBAL_PROJECTION	"gProjection"
#define	SHADER_GLOBAL_VIEW			"gView"
#define SHADER_GLOBAL_WORLD			"gWORLD"

using PAttributes	= std::map<std::string, uint8>;
using PUniforms		= std::map<std::string, uint8>;

class SProgram : INonCopy
{
public:
	SProgram(const std::string file);
	~SProgram();

	void Bind();
	void Unbind();
	bool IsInUse();

	void GetUniformLocation(const GLchar* name, GLuint& location);
	void Create();
	void Clear();


	uint8 AttribLocation(std::string);
	uint8 UniLocation(std::string);

	bool HasAttribute(std::string);
	bool HasUniform(std::string);

	//Uniform binders
	void BindUniform(const std::string name, int32 i);
	void BindUniform(const std::string name, float f);
	void BindUniform(const std::string name, float f1, float f2);
	void BindUniform(const std::string name, float f1, float f2, float f3);
	void BindUniform(const std::string name, const Vec3& v);
	void BindUniform(const std::string name, const Vec4& v);
	void BindUniform(const std::string name, const Mat3& m);
	void BindUniform(const std::string name, const Mat4& m);
	void BindUniform(const std::string name, bool b);
	//void BindUniform(const std::string name, const TODOTEX&);
	
private:
	static void ValidateCompile(GLuint program);
	static void ValidateLink(GLuint program);
	
	void AttachShader(Shader* shader);

private:
	std::string		m_file;
	GLuint			m_program_id;
	PAttributes		m_attribs;
	PUniforms		m_uniforms;

	std::vector<Shader*>	m_shaders;




};