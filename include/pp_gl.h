#ifndef PP_GL_H
#define PP_GL_H

#ifndef PP_NO_GLEW
	#include <gl/glew.h>
#endif

#if defined(PP_SYS_WINDOWS)
	#include <gl/GL.h>
	#include <gl/GLU.h>
#elif defined(PP_SYS_LINUX)
	#include <gl/gl.h>
	#include <gl/glu.h>
#elif defined(PP_SYS_MACOS)
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#endif

#endif