#include "Wall.h"
#include "SpriteCodex.h"

Wall::Wall(Vec2& pos)
	:
	mPos(pos)
{}

Wall::Wall(Vec2& pos, float halfWidth, float halfHeight)
	:
	mPos(pos),
	mHalfWidth(halfWidth),
	mHalfHeight(halfHeight)
{}

Wall::Wall(const RectF& rect)
	:
	mRect(rect)
{}

void Wall::DrawWall(Graphics& gfx) const
{
	SpriteCodex::DrawWall(mPos, gfx);
}
