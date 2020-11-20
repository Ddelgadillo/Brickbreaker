#pragma once
#include "Graphics.h"
#include "RectF.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(const RectF& rect);//, Color color);
	void Draw(Graphics& gfx) const;
private:
	RectF mRect;
	Color mColor = Colors::Blue;
};