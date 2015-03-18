#ifndef PP_SDL_INPUT_H
#define PP_SDL_INPUT_H

#include <pp_platform.h>
#include <pp_types.h>
#include <cstdint>
#include <SDL2\SDL.h>

#include <map>

#define MOUSE_BUTTONS_NUM 3
#define MOUSE_LEFT 0
#define MOUSE_RIGHT 1
#define MOUSE_MIDDLE 2

namespace PP
{
	struct MouseClickState
	{
		uint8_t clicks;
		uint8_t state;
		
	};

	class SDLMouseState
	{
	public:
		SDLMouseState();
		~SDLMouseState();

		const int X() const;
		const int Y() const;

		bool ButtonRelease(int button);
		bool ButtonPress(int button);
		bool SingleButtonPress(int button);

		void MouseMove(int x, int y);
		void MouseEvent(SDL_MouseButtonEvent e);
		void Update();

	private:
		int	m_x;
		int m_y;
		MouseClickState m_cur[MOUSE_BUTTONS_NUM];
		MouseClickState m_prev[MOUSE_BUTTONS_NUM];
		
	};

	class SDLKeyState
	{
		typedef std::map<SDL_Scancode, bool> KeyState;

	public:
		SDLKeyState();
		~SDLKeyState();

		void KeyDown(SDL_Scancode sc);
		void KeyUp(SDL_Scancode sc);
		void Update();
		bool SingleKey(SDL_Scancode sc);

	private:
		KeyState m_cur;
		KeyState m_prev;
	};
}


#endif