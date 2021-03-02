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
		gfx.DrawRect(mRect.GetExpanded(-mPadding), mColor);
	}
}

bool Brick::BallCollision(Ball& ball)
{
	if (!mIsDestroyed && mRect.Collision(ball.GetRect()))
	{
		const Vec2 ballPos = ball.GetPosition();
		if (ballPos.x >= mRect.mLeft && ballPos.x <= mRect.mRight)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
		mIsDestroyed = true;

		return true;
	}

	return false;
}