#pragma once

#include <GL\glew.h>
#include <pp_types.h>
#include <SProgram.h>

class Model
{
public:
	Model();
	Model(GLuint vao, unsigned int cnt);
	~Model();

	GLuint VAO() const { return m_vao; }
	unsigned int VertexCnt() const { return m_vertex_cnt; }

	// Setters
	void				SetPosition();

	// Getters
	const Vec3&			Position() const;
	SProgram*	Program() const;

	void Render();
	void Init();

private:
	void InitShaderPrg();

private:
	GLuint m_vao;
	unsigned int m_vertex_cnt;

	Mat4				m_model;
	Vec3				m_position;
	Vec3				m_scale;
	SProgram*	m_program;
	bool				m_initialized;
};