#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Wall
{
public:
	Wall() = default;
	Wall(const RectF& rect);
	RectF GetRect() const;
	void DrawWall(Graphics& gfx) const;
	static constexpr float mWidth = 50.0f;
	static constexpr float mHeight = 50.0f;
private:
	RectF mRect;
	float mHalfWidth;
	float mHalfHeight;
};