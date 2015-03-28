#include <Loader.h>

Model* Loader::LoadToVAO(float* positions)
{
	GLuint vaoID = CreateVAO();
	StoreDataInList(0, positions);
	UnbindVAO();

	Model* m = new Model(vaoID, 6);

	return m;
}

GLuint Loader::CreateVAO()
{
	GLuint vao;

	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	return vao;
}

void Loader::StoreDataInList(int attrNum, float* positions)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions[0], GL_STATIC_DRAW);
	glVertexAttribPointer(attrNum, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::UnbindVAO()
{
	glBindVertexArray(0);
}