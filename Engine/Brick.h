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
	Brick(const RectF& rect, Color color);
	void Draw(Graphics& gfx) const;
	bool BallCollision(Ball& ball);
	static constexpr float mWidth = 40.0f;
	static constexpr float mHeight = 24.0f;
private:
	Vec2 mPos;
	RectF mRect;
	Color mColor;
	bool mIsDestroyed = false;
};