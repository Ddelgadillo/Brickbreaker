#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	//centered drawing of the player paddle 100x30
	static void DrawPaddle(const Vec2& center, Graphics& gfx);
	// centered drawing of 14x14 sprite
	static void DrawBall(const Vec2& center, Graphics& gfx);
	// centered drawing of 30x30 wallsprite
	static void DrawWall(const Vec2& center, Graphics& gfx);
	// centered drawing of 200x160 sprite
	static void DrawTitle(const Vec2& center, Graphics& gfx);
	// centered drawing of 84x64 sprite
	static void SpriteCodex::DrawGameOver(const Vec2& center, Graphics& gfx);
	// centered drawing of 104x19 sprite
	static void SpriteCodex::DrawReady(const Vec2& center, Graphics& gfx);
	// centered drawing of 24x24 sprite
	static void SpriteCodex::DrawPoo(const Vec2& center, Graphics& gfx);
	static void DrawBBMainMenu(const Vec2& pos, Graphics& gfx);
};