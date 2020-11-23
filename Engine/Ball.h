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
private:
	Vec2 mPos;
	Vec2 mVel;
};