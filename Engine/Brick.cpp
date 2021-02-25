#include "Brick.h"

Brick::Brick(Vec2& pos)
	:
	mPos(pos)
{}

void Brick::Init(Vec2& pos)
{
	mPos = pos;
}

void Brick::Draw(Graphics& gfx) const
{
	if (!mIsDestroyed)
	{
		gfx.DrawRect(GetRect(), Colors::Red);
	}
}

bool Brick::BallCollision(Ball& ball)
{
	if (!mIsDestroyed && GetRect().Collision(ball.GetRect()))
	{
		ball.ReboundY();
		mIsDestroyed = true;
	}

	return false;
}

RectF Brick::GetRect() const
{
	return RectF::RectF(mPos, mWidth, mHeight);
}
