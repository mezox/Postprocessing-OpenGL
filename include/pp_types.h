#pragma once

#include <pp_generic_types.h>
#include <string>

#ifdef OPENGL_RENDERER
	#include <GLM.h>

	using Mat4 = glm::mat4x4;
	using Mat3 = glm::mat3x3;
	using Vec2 = glm::vec2;
	using Vec3 = glm::vec3;
	using Vec4 = glm::vec4;
#endif

typedef unsigned int uint;
typedef unsigned long int ulint;
typedef unsigned char uchar;
typedef const std::string cstring;

// Unsigned base types
using uint8 = GenericPlatformTypes::uint8;
using uint16 = GenericPlatformTypes::uint16;
using uint32 = GenericPlatformTypes::uint32;
using uint64 = GenericPlatformTypes::uint64;

// Signed base types
using int8 = GenericPlatformTypes::int8;
using int16 = GenericPlatformTypes::int16;
using int32 = GenericPlatformTypes::int32;
using int64 = GenericPlatformTypes::int64;

// Character types
using ANSICHAR = GenericPlatformTypes::ANSICHAR;
using WIDECHAR = GenericPlatformTypes::WIDECHAR;
using UTF8CHAR = GenericPlatformTypes::CHAR8;
using UTF16CHAR = GenericPlatformTypes::CHAR16;
using UTF32CHAR = GenericPlatformTypes::CHAR32;
using TCHAR = GenericPlatformTypes::WIDECHAR;

using uptrint = GenericPlatformTypes::uptrint;