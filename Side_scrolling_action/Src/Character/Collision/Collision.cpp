#include "Collision.h"

bool Collision::Collider::BoxAndBox(Vector2 target, Vector2 targetSize, Vector2 target2, Vector2 targetSize2)
{
	if ((target.x<target2.x + targetSize2.x&& target.x + targetSize.x>target2.x) ||
		(target.y<target2.y + targetSize2.y && target.y + targetSize.y>target2.x))
	{
		return true;
	}
	return false;
}
