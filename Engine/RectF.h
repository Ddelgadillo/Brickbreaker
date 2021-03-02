#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left, float right, float top, float bottom);
	RectF(const Vec2& topLeft, const Vec2& bottomLeft);
	RectF(const Vec2& topLeft, float width, float height);
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	bool Collision(const RectF& other) const;
	RectF GetExpanded(float offset) const;
	Vec2 GetCenter() const;
public:
	float mLeft;
	float mRight;
	float mTop;
	float mBottom;
};