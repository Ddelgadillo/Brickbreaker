#include "Wall.h"
#include "SpriteCodex.h"

Wall::Wall(const RectF& rect)
	:
	mRect(rect)
{}

RectF Wall::GetRect() const
{
	return mRect;
}

void Wall::DrawWall(Graphics& gfx) const
{
	SpriteCodex::DrawWall(mRect.GetCenter(), gfx);
}
