#include "Brick.h"

Brick::Brick(Vec2& pos)
	:
	mPos(pos)
{}

Brick::Brick(const RectF& rect, Color color)
	:
	mRect(rect),
	mColor(color)
{}

void Brick::Draw(Graphics& gfx) const
{
	if (!mIsDestroyed)
	{
		gfx.DrawRect(mRect, mColor);
	}
}

bool Brick::BallCollision(Ball& ball)
{
	if (!mIsDestroyed && mRect.Collision(ball.GetRect()))
	{
		ball.ReboundY();
		mIsDestroyed = true;

		return true;
	}

	return false;
}