#pragma once

#include <pp_types.h>

namespace Client
{
	class Rectangle
	{
	public:
		inline Rectangle() : m_x(0), m_y(0), m_w(0), m_h(0) {}
		inline Rectangle(int x, int y, uint w, uint h) :
			m_x(x), m_y(y), m_w(w), m_h(h) {}

	public:
		inline int Left()		const { return m_x; }
		inline int Right()		const { return m_x + m_w; }
		inline uint Top()		const { return m_y; }
		inline uint Bottom()	const { return m_y + m_h; }

		inline bool operator==(const Rectangle& rhs)
		{
			return (
				m_x == rhs.m_x &&
				m_y == rhs.m_y &&
				m_w == rhs.m_w &&
				m_h == rhs.m_h
				);
		}

		inline bool operator !=(const Rectangle& rhs)
		{
			return !(*this == rhs);
		}

		bool Contains(int x, int y);
		bool Intersects(const Rectangle& r);

		static const Rectangle EMPTY;


	public:
		int m_x;
		int m_y;
		int m_w;
		int m_h;
	};
}

using Rect = Client::Rectangle;