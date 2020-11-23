#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2& pos, Vec2& vel)
	:
	mPos(pos),
	mVel(vel)
{
}

void Ball::Update(float delta)
{
	mPos += mVel * delta;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(mPos, gfx);
}
