#include <pp_sdl_input.h>

namespace PP
{
	SDLMouseState::SDLMouseState()
	{
		m_x = 0;
		m_y = 0;
		m_cur[MOUSE_LEFT].state = SDL_RELEASED;
		m_cur[MOUSE_RIGHT].state = SDL_RELEASED;
		m_cur[MOUSE_MIDDLE].state = SDL_RELEASED;
		
		m_prev[MOUSE_LEFT].state = SDL_RELEASED;
		m_prev[MOUSE_RIGHT].state = SDL_RELEASED;
		m_prev[MOUSE_MIDDLE].state = SDL_RELEASED;
	}

	SDLMouseState::~SDLMouseState()
	{

	}

	const int SDLMouseState::X() const
	{
		return m_x;
	}

	const int SDLMouseState::Y() const
	{
		return m_y;
	}

	bool SDLMouseState::ButtonRelease(int button)
	{
		if (button >= 3)
		{
			return false;
		}

		return (m_cur[button].state == SDL_RELEASED && m_prev[button].state == SDL_PRESSED);
	}

	bool SDLMouseState::ButtonPress(int button)
	{
		if (button >= 3)
		{
			return false;
		}
			
		return m_cur[button].state == SDL_PRESSED;
	}

	bool SDLMouseState::SingleButtonPress(int button)
	{
		if (button >= 3)
		{
			return false;
		}

		return (m_cur[button].state == SDL_PRESSED && m_prev[button].state == SDL_RELEASED);
	}

	void SDLMouseState::MouseMove(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void SDLMouseState::MouseEvent(SDL_MouseButtonEvent e)
	{
		switch (e.button)
		{
		case SDL_BUTTON_LEFT:
			m_cur[MOUSE_LEFT].state = e.state;
			m_cur[MOUSE_LEFT].clicks = e.clicks;
			break;

		case SDL_BUTTON_RIGHT:
			m_cur[MOUSE_RIGHT].state = e.state;
			m_cur[MOUSE_RIGHT].clicks = e.clicks;
			break;

		case SDL_BUTTON_MIDDLE:
			m_cur[MOUSE_MIDDLE].state = e.state;
			m_cur[MOUSE_MIDDLE].clicks = e.clicks;
			break;
		}
	}

	void SDLMouseState::Update()
	{
		memcpy(m_prev, m_cur, sizeof(m_cur));
	}



	SDLKeyState::SDLKeyState()
	{

	}

	SDLKeyState::~SDLKeyState()
	{

	}
}