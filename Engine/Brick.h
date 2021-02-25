#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(Vec2& pos);
	void Init(Vec2& pos);
	void Draw(Graphics& gfx) const;
	bool BallCollision(Ball& ball);
	RectF GetRect() const;
private:
	Vec2 mPos;
	const float mWidth = 100.0f;
	const float mHeight = 30.0f;
	bool mIsDestroyed = false;
};