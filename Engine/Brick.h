#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Brick
{
public:
	Brick() = default;
	Brick(Vec2& pos);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;
private:
	Vec2 mPos;
	const float mWidth = 100.0f;
	const float mHeight = 30.0f;
};