#ifndef PP_SDL_TIMER_H
#define PP_SDL_TIMER_H

#include <pp_platform.h>
#include <pp_types.h>

namespace PP
{
	class SDLTimer
	{
	public:
		SDLTimer();
		~SDLTimer();
		
		void	Start();
		void	Tick();
		float	DeltaTime();
		float	FPS();
		void	CalculateFPS();

	private:
		uint	m_start_time;
		uint	m_cur_time;
		uint	m_prev_time;
		float	m_fps;
		float	m_delta_time;
	};
}

#endif
