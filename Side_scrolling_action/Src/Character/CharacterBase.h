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
	* @brief ��`�̓����蔻��
	* @param own ���g�̍\����
	* @param target ����̍\����
	* @param ownSize ���g�̃T�C�Y
	* @param targetSize ����̃T�C�Y
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

