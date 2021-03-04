#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2& pos, Vec2& vel)
	:
	mPos(pos),
	mVel(vel)
{}

void Ball::Update(float delta)
{
	mPos += mVel * delta;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(mPos, gfx);
}

bool Ball::WallCollision(const RectF& walls)
{
	const RectF ballRect = GetRect();

	if (ballRect.mBottom >= walls.mBottom)
	{
		mPos.y -= ballRect.mBottom - walls.mBottom;
		ReboundY();
		return true;
	}
	if (ballRect.mTop <= walls.mTop)
	{
		mPos.y += walls.mTop - ballRect.mTop;
		ReboundY();
		return true;
	}

	if (ballRect.mLeft < walls.mLeft)
	{
		mPos.x += walls.mLeft - ballRect.mLeft;
		ReboundX();

		return true;
	}
	else if (ballRect.mRight > walls.mRight)
	{
		mPos.x -= ballRect.mRight - walls.mRight;
		ReboundX();

		return true;
	}

	return false;
}

void Ball::ReboundY()
{
	mVel.y = -mVel.y;
}

void Ball::ReboundX()
{
	mVel.x = -mVel.x;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(mPos, mRadius, mRadius);
}

Vec2 Ball::GetVelocity() const
{
	return mVel;
}

Vec2 Ball::GetPosition() const
{
	return mPos;
}
