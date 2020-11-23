#include "Paddle.h"

Paddle::Paddle(const RectF& rect, Color color)
	:
	mRect(rect),
	mColor(color)
{
	
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(mRect, mColor);
}
