#include "Wall.h"
#include "SpriteCodex.h"

Wall::Wall(const Vec2& pos)
	:
	mPos(pos)
{}

Wall::Wall(const RectF& rect)
	:
	mRect(rect)
{}

RectF Wall::GetRect() const
{
	return mRect;
}

Vec2 Wall::GetPos() const
{
	return mPos;
}

void Wall::DrawWall(Graphics& gfx) const
{
	SpriteCodex::DrawWall(mPos, gfx);
}
