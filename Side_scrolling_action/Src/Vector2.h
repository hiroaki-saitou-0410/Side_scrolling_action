#ifndef VECTOR2
#define VECTOR2

struct Vector2
{	
	int x = 0;
	int y = 0;

	float xf = 0.0f;
	float yf = 0.0f;

	void vec2(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	void vec2_f(float _x, float _y)
	{
		xf = _x;
		yf = _y;
	}
};

#endif // !VECTOR2

