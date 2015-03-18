#include <pp_sdl_timer.h>

#include <SDL2\SDL.h>

namespace PP
{
	SDLTimer::SDLTimer()
	{
		m_start_time = 0;
		m_cur_time = 0;;
		m_prev_time = 0;
		m_fps = 0.0f;
		m_delta_time = 0.0f;
	}

	SDLTimer::~SDLTimer()
	{

	}

	void SDLTimer::Start()
	{
		m_start_time = SDL_GetTicks();	//[ms]
	}

	void SDLTimer::Tick()
	{
		m_prev_time = m_cur_time;
		m_cur_time = SDL_GetTicks();

		m_delta_time = static_cast<float>(m_cur_time - m_prev_time);
	}

	float SDLTimer::DeltaTime()
	{
		return m_delta_time;
	}

	float SDLTimer::FPS()
	{
		return m_fps;
	}

	void SDLTimer::CalculateFPS()
	{
		static int frame_cnt = 0;

		if (m_start_time < (SDL_GetTicks() - 1000.0f))
		{
			m_start_time = SDL_GetTicks();
			m_fps = static_cast<float>(frame_cnt);

			frame_cnt = 0;
		}

		frame_cnt++;
	}
}
