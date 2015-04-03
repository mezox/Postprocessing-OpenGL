#include <iostream>
#include <SDLWindow.h>
#include <SProgram.h>

#undef main

int main(int argc, char** argv)
{
	SDLAppWindow * win = new SDLAppWindow();

	win->Init();

	win->Run();

	return 0;
}
