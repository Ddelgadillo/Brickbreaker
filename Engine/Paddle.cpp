#include "Paddle.h"
#include<iostream>

Paddle::Paddle(Vec2& pos, float halfWidth, float halfHeight)
	:
	mPos(pos),
	mHalfWidth(halfWidth),
	mHalfHeight(halfHeight)
{}

void Paddle::Draw(Graphics& gfx) const
{
	//If you want wings...
	//RectF rect = GetRect();
	//gfx.DrawRect(rect, wingColor);
	//rect.left += wingWidth;
	//rect.right -= wingWidth;
	gfx.DrawRect(GetRect(), mColor);
}

bool Paddle::BallCollision(Ball& ball)
{
	if (!isCoolDown)
	{
		const RectF rect = GetRect();

		if (rect.Collision(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetPosition();

			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - mPos).x))
			{
				ball.ReboundY();
			}
			else if (ballPos.x >= rect.mLeft && ballPos.x <= rect.mRight)
			{
				ball.ReboundY();
			}
			else
			{
				ball.ReboundX();
			}

			isCoolDown = true;

			return true;
		}
		
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

void Paddle::ResetCoolDown()
{
	isCoolDown = false;
}
