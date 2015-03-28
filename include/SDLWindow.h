#pragma once

#include <IAppWindow.h>
#include <SDLInput.h>
#include <Rectangle.h>
#include <pp_types.h>
#include <SDL2\SDL.h>

namespace SDL
{
	enum class WIN_FLAGS
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

	struct WIN_PARAMS
	{
		std::string title;
		int x;
		int y;
		int width;
		int height;
		uint32 flags;
	};
}
	
class SDLAppWindow : IAppWindow
{
public:
	SDLAppWindow();
	SDLAppWindow(const SDL::WIN_PARAMS& params);
	~SDLAppWindow();


public:
	void Init()							override;
	void Resize()						override;
	void MoveTo()						override;
	void Focus()						override;
	void Minimalize()					override;
	void Maximalize()					override;
	void Show()							override;
	void Hide()							override;
	void ToggleMode(WindowMode::Type)	override;
	void ToggleCursor()					override;
	void Destroy()						override;
	void SwapBuffers()					override;
	void Run()							override;

	bool IsRunning()					override;
	bool IsHidden()						override;
	bool IsMaximized()					override;
	bool IsMinimized()					override;

	void SetRenderer(IRenderer* r)		override;

	void*				GetWindowHandle()	const override;
	WindowMode::Type	GetMode()			const override;
	const Rect			GetClientBounds()	override;

private:
	std::string		m_title;
	bool			m_running;
	bool			m_fullscreen;
	bool			m_cursor_hidden;
	SDL_Window*		m_win_handler;
	SDL_GLContext	m_gl_context;
	SDL::WIN_PARAMS	m_params;
	WindowMode::Type m_win_mode;
	uint32			m_win_flags;
	SDLMouseState*	m_mouse_state;
	SDLKeyState*	m_key_state;
	Rect			m_client;
};