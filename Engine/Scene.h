#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"
class Scene
{
public:
	Scene() = default;
	Scene(const Vec2& pos, float width, float height);
	void Draw(Graphics& gfx) const;
	bool StartGame(const Keyboard& kbd);
protected:
	Vec2 mPos;
	const float mWidht;
	const float mHeight;
};

