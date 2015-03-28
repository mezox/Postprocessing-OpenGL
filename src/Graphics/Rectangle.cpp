#include <Rectangle.h>

const Rect Rect::EMPTY(0, 0, 0, 0);

bool Rect::Contains(int x, int y)
{
	return (
		((this->m_x <= x) && (m_x < (this->m_x + this->m_w)) &&
		(this->m_y <= y)) && (y < (this->m_y + this->m_h))
	);
}

bool Rect::Intersects(const Rect& r)
{
	return(
		r.Left() > Right() ||
		r.Right() < Left() ||
		r.Top() > Bottom() ||
		r.Bottom() < Top()
	);
}