#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2& pos, Vec2& vel);
	void Update(float delta);
	void Draw(Graphics& gfx) const;
	bool WallCollision(const RectF& walls);
	RectF GetRect() const;
private:
	static constexpr float mRadius = 7.0f;
	Vec2 mPos;
	Vec2 mVel;
};