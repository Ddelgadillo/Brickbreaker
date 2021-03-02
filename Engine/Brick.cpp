#include "Brick.h"
#include<assert.h>
#include<iostream>

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
		gfx.DrawRect(mRect.GetExpanded(-mPadding), mColor);
	}
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !mIsDestroyed && mRect.Collision(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));

	const Vec2 ballPos = ball.GetPosition();

	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}

	if (ballPos.x >= mRect.mLeft && ballPos.x <= mRect.mRight)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}

	mIsDestroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return mRect.GetCenter();
}
