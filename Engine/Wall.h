#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Wall
{
public:
	Wall() = default;
	Wall(Vec2& pos);
	Wall(Vec2& pos, float halfWidth, float halfHeight);
	Wall(const RectF& rect);
	void DrawWall(Graphics& gfx) const;
	static constexpr float mWidth = 50.0f;
	static constexpr float mHeight = 50.0f;
private:
	Vec2 mPos;
	RectF mRect;
	float mHalfWidth;
	float mHalfHeight;
};