#ifndef PP_SDL_WINDOW_H
#define PP_SDL_WINDOW_H

#include <pp_iappwindow.h>
#include <pp_types.h>
#include <SDL2\SDL.h>

namespace PP
{
	enum class SDL_AW_Flags
	{
		SDL_GW_FULLSCREEN,
		SDL_GW_FULLSCREEN_DESKTOP,
		SDL_GW_OPENGL,
		SDL_GW_HIDDEN,
		SDL_GW_BORDERLESS,
		SDL_GW_RESIZEABLE,
		SDL_GW_MINIMIZED,
		SDL_GW_INPUT_GRABBED,
		SDL_GW_ALLOW_HIGHDPI
	};

	struct SDL_AW_Params
	{
		std::string title;
		int x;
		int y;
		int width;
		int height;
		uint flags;
	};

	class SDLAppWindow : IAppWindow
	{
	public:
		SDLAppWindow(const SDL_AW_Params&);
		~SDLAppWindow();

		virtual void		VInit()						override;
		virtual void		VRun()						override;
		virtual void		VSetFullscreen(bool flag)	override;
		virtual void		VSetVisible(bool flag)		override;
		virtual void		VSwapBuffers()				override;
		virtual void		VToggleCursor()				override;
		virtual void		VClose()					override;

		virtual cstring&	VGetTitle()					override;
		virtual bool		VIsRunning()				override;
		virtual bool		VIsPaused()					override;
		virtual bool		VIsHidden()					override;

	private:
		std::string		m_title;
		bool			m_hidden;
		bool			m_running;
		bool			m_paused;
		bool			m_fullscreen;
		bool			m_cursor_hidden;
		SDL_Window*		m_win_handler;
		SDL_GLContext	m_gl_context;
		SDL_AW_Params	m_params;
	};
}
#endif