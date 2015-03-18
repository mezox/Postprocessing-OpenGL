#include <pp_sdl_window.h>

#include <iostream>

namespace PP
{
	SDLAppWindow::SDLAppWindow(const SDL_AW_Params& params)
	{
		m_hidden = true;
		m_running = false;
		m_paused = false;
		m_fullscreen = false;
		m_cursor_hidden = false;
		m_win_handler = nullptr;
		m_gl_context = nullptr;
		m_params = params;
	}

	SDLAppWindow::~SDLAppWindow()
	{
		m_win_handler = nullptr;
		m_gl_context = nullptr;
	}

	void SDLAppWindow::VInit()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
		{
			std::cout << "SDL failed to initialize %s\n";
		}
	}

	void SDLAppWindow::VRun()
	{
		return;
	}

	void SDLAppWindow::VSetVisible(bool flag)
	{

	}

	void SDLAppWindow::VSetFullscreen(bool flag)
	{
		m_fullscreen = flag;

		if (flag)
		{
			SDL_SetWindowFullscreen(m_win_handler, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else
		{
			SDL_SetWindowFullscreen(m_win_handler, 0);
		}

		//TODO: setViewport etc.
	}

	void SDLAppWindow::VSwapBuffers()
	{
		SDL_GL_SwapWindow(m_win_handler);
	}

	void SDLAppWindow::VToggleCursor()
	{
		m_cursor_hidden = !m_cursor_hidden;

		if (m_cursor_hidden)
			SDL_ShowCursor(0);
		else
			SDL_ShowCursor(1);
	}

	void SDLAppWindow::VClose()
	{
		m_running = false;
		SDL_GL_DeleteContext(m_gl_context);
		SDL_Quit();
	}

	const std::string& SDLAppWindow::VGetTitle()
	{
		return m_title;
	}

	bool SDLAppWindow::VIsRunning()
	{
		return m_running;
	}

	bool SDLAppWindow::VIsPaused()
	{
		return m_paused;
	}

	bool SDLAppWindow::VIsHidden()
	{
		return m_hidden;
	}
}