#pragma once

#include <Model.h>

class Loader
{
public:
	Model* LoadToVAO(float* positions);

private:
	GLuint	CreateVAO();
	void	StoreDataInList(int attrNum, float* data);
	void	UnbindVAO();
};