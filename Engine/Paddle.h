#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(Vec2& pos);
	Paddle(Vec2& pos, float halfWidth, float halfHeight);
	void Draw(Graphics& gfx) const;
	bool BallCollision(Ball& ball);
	void WallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float delta);
	RectF GetRect() const;
	void ResetCoolDown();
private:
	Vec2 mPos;
	float mHalfWidth;
	float mHalfHeight;
	float mSpeed = 300.0f;
	Color mColor = Colors::Blue;
	bool isCoolDown = false;
};