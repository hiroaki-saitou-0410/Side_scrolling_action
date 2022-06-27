#include"AbilityManager.h"

AbilityManager::AbilityManager()
{
}

void AbilityManager::Update(std::shared_ptr<Player>player)
{
	if (player->UsedAbility()!=Ability::none)
	{
		activeAbility = true;
		Abi = player->UsedAbility();
		AbiCreate();
	}

	if (activeAbility){	AbiUpdate();}
}

void AbilityManager::Draw()
{
	switch (Abi)
	{
	case a:heavy->Draw();
		break;
	case s:
		for (int i = 0; i < bombardment.size(); i++)
		{
			if (bombardment.at(i).Active())
			{
				bombardment.at(i).Draw();
			}
		}
		break;
	case d:
		break;
	case f:
		break;
	}
}

void AbilityManager::AbiCreate()
{
	switch (Abi)
	{
	case a:heavy->Create();
		break;
	case s:
		srand((unsigned int)time(0));
		for (int i = 0; i < FIRE_BULLETS; i++)
		{
			if (!bombardment.at(i).Active())
			{
				bombardment.at(i).Create(rand());
			}
		}
		break;
	case d:	break;
	case f:
		break;
	}
}

void AbilityManager::AbiUpdate()
{
	if (!heavy->Active()&&!bombardment.back().Active())
	{
		activeAbility = false;
		Abi = Ability::none;
		bullet = 0;
		timer = COOL_TIME;
	}
	else if (activeAbility)
	{
		switch (Abi)
		{
		case a:heavy->Update(); break;
		case s:
			if (timer >= COOL_TIME)
			{
				if (bullet < FIRE_BULLETS)
				{
					bullet++;
					timer = 0;
				}
			}

			for (int i = 0; i < bullet; i++)
			{
				if (bombardment.at(i).Active())
				{
					bombardment.at(i).Update();
				}
			}
			timer++;
			break;
		case d:
			break;
		case f:
			break;
		}
	}
}

Collision::Collider::collider AbilityManager::AbiCollider()
{
	switch (Abi)
	{
	case a:Col = heavy->Collider();break;
	case s:break;
	case d:break;
	case f:break;	
	}
	return Col;
}
