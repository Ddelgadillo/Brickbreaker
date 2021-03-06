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
	bool WallCollision(const RectF& walls);\
	void ReboundY();
	void ReboundX();
	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
private:
	static constexpr float mRadius = 7.0f;
	Vec2 mPos;
	Vec2 mVel;
};