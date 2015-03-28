#pragma once

#include <IShaderProgram.h>
#include <Graphics\GLShader.h>

#define	SHADER_GLOBAL_PROJECTION	"gProjection"
#define	SHADER_GLOBAL_VIEW	"gView"
#define SHADER_GLOBAL_WORLD	"gWORLD"

class GLShaderProgram : public IShaderProgram
{
public:
	GLShaderProgram();
	~GLShaderProgram();

	void Bind();
	void Unbind();
	bool IsInUse();

	void GetUniformLocation(const GLchar* name, GLuint& location);
	void Create()						override;
	void AttachShader(Shader* shader);

protected:


private:
	GLuint m_program_id;

	static void ValidateCompile(GLuint program);
	static void ValidateLink(GLuint program);
};