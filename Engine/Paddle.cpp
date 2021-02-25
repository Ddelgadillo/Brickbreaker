#include "Paddle.h"

Paddle::Paddle(Vec2& pos, float halfWidth, float halfHeight)
	:
	mPos(pos),
	mHalfWidth(halfWidth),
	mHalfHeight(halfHeight)
{}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetRect(), mColor);
}

bool Paddle::BallCollision(Ball& ball) const
{
	if (GetRect().Collision(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}

	return false;
}

void  Paddle::WallCollision(const RectF& walls)
{
	const RectF rect = GetRect();

	if (rect.mLeft < walls.mLeft)
	{
		mPos.x += walls.mLeft - rect.mLeft;
	}
	else if (rect.mRight + 1 > walls.mRight)
	{
		mPos.x -= rect.mRight - walls.mRight;
	}
}

void Paddle::Update(const Keyboard& kbd, float delta)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		mPos.x -= mSpeed * delta;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		mPos.x += mSpeed * delta;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(mPos, mHalfWidth, mHalfHeight);
}
