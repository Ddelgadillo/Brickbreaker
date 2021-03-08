#include "Scene.h"
#include "SpriteCodex.h"

Scene::Scene(const Vec2& pos, float width, float height)
	:
	mPos(pos),
	mWidht(width),
	mHeight(height)
{}

void Scene::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBBMainMenu(mPos, gfx);
}
