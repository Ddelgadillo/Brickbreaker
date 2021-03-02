#include "RectF.h"

RectF::RectF(float left, float right, float top, float bottom)
	:
	mLeft(left),
	mRight(right),
	mTop(top),
	mBottom(bottom)
{}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomLeft)
	:
	RectF(topLeft.x, bottomLeft.x, topLeft.y, bottomLeft.y)
{}

RectF::RectF(const Vec2& topLeft, float width, float height)
	:
	RectF(topLeft, topLeft + Vec2(width, height))
{}

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

bool RectF::Collision(const RectF& other) const
{
	return mLeft <= other.mRight && mRight >= other.mLeft &&
		mTop <= other.mBottom && mBottom >= other.mTop;
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(mLeft - offset, mRight + offset, mTop - offset, mBottom + offset);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((mLeft + mRight) / 2.0f, (mTop + mBottom) / 2.0f);
}
