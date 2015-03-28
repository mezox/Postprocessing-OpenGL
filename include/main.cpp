#include <iostream>
#include <SDLWindow.h>
#include <Graphics\GLShader.h>
#include <GLShaderProgram.h>

#undef main

int main(int argc, char** argv)
{
	SDLAppWindow * win = new SDLAppWindow();

	win->Init();

	win->Run();

	return 0;
}
