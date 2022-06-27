#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include"DxLib.h"
#include"CharaDefinition.h"
#include"../Vector2.h"

class CharacterBase
{
public:
	CharacterBase() {}
	virtual ~CharacterBase() {}

	virtual void Update()
	{

	}
	
	virtual void Draw() {}

	/**
	* @brief 矩形の当たり判定
	* @param own 自身の構造体
	* @param target 相手の構造体
	* @param ownSize 自身のサイズ
	* @param targetSize 相手のサイズ
	*/
	virtual bool BoxCollition(const Vector2& own, const Vector2& target, const int& ownSize, const int& targetSize)
	{
		if((own.x < target.x + targetSize && own.x + ownSize > target.x)||
			(own.y < target.y + targetSize && own.y + ownSize > target.y))
		{
			return true;
		}
		return false;
	}
protected:
	bool alive=false;
};

#endif // !CHARACTER_BASE_H

