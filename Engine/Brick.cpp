#include "Brick.h"

Brick::Brick(Vec2& pos)
	:
	mPos(pos)
{}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetRect(), Colors::Red);
}

RectF Brick::GetRect() const
{
	return RectF::RectF(mPos, mWidth, mHeight);
}
