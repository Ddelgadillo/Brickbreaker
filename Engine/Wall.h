#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Wall
{
public:
	Wall() = default;
	Wall(const Vec2& pos);
	Wall(const RectF& rect);
	RectF GetRect() const;
	Vec2 GetPos() const;
	void DrawWall(Graphics& gfx) const;
	static constexpr float mWidth = 50.0f;
	static constexpr float mHeight = 50.0f;
private:
	Vec2 mPos;
	RectF mRect;
	float mHalfWidth;
	float mHalfHeight;
};