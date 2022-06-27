#ifndef COLLITON_H
#define COLLITON_H

#include"../../Vector2.h"

namespace Collision
{
	class Collider
	{
	public:
		struct collider
		{
			Vector2 vec{0,0};
			Vector2 size{0,0};
		};

		struct Fan
		{
			Vector2 vec;
			float degree;
			float length;
			float directionDegree;

		};

		static bool BoxAndBox(Vector2 target,Vector2 targetSize,Vector2 target2, Vector2 targetSize2);

	};

}
#endif // !COLLITON_H

