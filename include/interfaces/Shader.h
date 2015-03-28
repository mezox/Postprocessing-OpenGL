#pragma once

#include <pp_types.h>

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
	virtual ~Shader() {}

protected:
	virtual std::string Readfile(const std::string& file) = 0;
};