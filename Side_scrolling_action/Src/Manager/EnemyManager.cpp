#include"EnemyManager.h"

//ˆø”‚ÅPlayer‚ğ‚Á‚Ä‚­‚é

EnemyManager::EnemyManager()
{
	flier.emplace_back();
	runner.emplace_back();
}

EnemyManager::~EnemyManager()
{	
	flier.clear();
	runner.clear();
}

void EnemyManager::Update(std::shared_ptr<Player> player_, std::unique_ptr<AbilityManager>& abilityManager)
{
	player = player_;
	playerCol = player_->PlayerCollider();
	if (abilityManager->ActiveAbility()) {
		AbilityCol = abilityManager->AbiCollider();
		if(player_->UsedAbility() != Ability::none)abi = player_->UsedAbility();
	}
	else{
		AbilityCol=InitCol;
	}
	CreateEnemies();
	UpdateEnemies();
	EnemiesCollision();
	BulletCollision();
	AbiCollision(abilityManager);
}

void EnemyManager::Draw()
{
	for (int i = 0; i < flier.size(); i++)
	{
		if (flier.at(i).IsAlive())
		{
			flier.at(i).Draw();
		}
	}

	for (int i = 0; i < runner.size(); i++)
	{
		if (runner.at(i).IsAlive())
		{
			runner.at(i).Draw();
		}
	}
}

void EnemyManager::CreateEnemies()
{
	if (inputManager.lock()->KeyPushed(KEY_INPUT_Q)) {
		for (int i = 0; i < runner.size(); i++)
		{
			if (!runner.at(i).IsAlive())
			{
				runner.at(i).Create();
				break;
			}
		}
		if (runner.at(runner.size() - 1).IsAlive())
		{
			runner.emplace_back();
		}
	}
	else if (inputManager.lock()->KeyPushed(KEY_INPUT_W)) {
		for (int i = 0; i < flier.size(); i++)
		{
			if (!flier.at(i).IsAlive())
			{
				flier.at(i).Create();
				break;
			}
		}
		if (flier.at(flier.size() - 1).IsAlive())
		{
			flier.emplace_back();
		}
	}
}

void EnemyManager::UpdateEnemies()
{
	for (int i = 0; i < flier.size(); i++)
	{
		if (flier.at(i).IsAlive())
		{
			flier.at(i).Update();
			if (!flier.at(i).IsAlive())
			{
				flier.at(i).Dead();
			}
		}
	}

	for (int i = 0; i < runner.size(); i++)
	{
		if (runner.at(i).IsAlive())
		{
			runner.at(i).Update();
			if (!runner.at(i).IsAlive())
			{
				runner.at(i).Dead();
			}
		}
	}
}

void EnemyManager::EnemiesCollision()
{
	if (hit)
	{
		hit = false;
	}

	for (int i = 0; i < runner.size(); i++)
	{
		if (runner.at(i).IsAlive())
		{
			if (runner.at(i).Collision(playerCol))
			{
				runner.at(i).Dead();
				hit = true;
			}
		}
	}

	for (int i = 0; i < flier.size() ; i++)
	{
		if (flier.at(i).IsAlive())
		{
			if (flier.at(i).Collision(playerCol))
			{
				flier.at(i).Dead();
				hit = true;
			}
		}
	}
}

void EnemyManager::BulletCollision()
{
	for (int i = 0; i < player.lock()->Bullets(); i++)
	{	
		if (player.lock()->IsBulletActive(i))
		{
			bulletCol = player.lock()->BulletCollider(i);
			for (int j = 0; j < runner.size(); j++)
			{
				if (runner.at(j).CircleCol(bulletCol,true) && runner.at(j).IsAlive())
				{
					runner.at(j).Dead();
					player.lock()->BulletNoneActive(i);
				}
			}

			for (int i = 0; i < player.lock()->Bullets(); i++)
			{
				for (int k = 0; k < flier.size(); k++)
				{
					if (flier.at(k).CircleCol(bulletCol,true) && flier.at(k).IsAlive())
					{
						flier.at(k).Dead();
						player.lock()->BulletNoneActive(i);
					}
				}
			}
		}
	}
}

void EnemyManager::AbiCollision(std::unique_ptr<AbilityManager>& abilityManager)
{
	if (!abilityManager->ActiveAbility())return;
	
	//if (abi== Ability::d)
	//{
	//	for (int i = 0; i < abilityManager->FireBullets(); i++)//Å‘å”‚Ìæ“¾
	//	{
	//		for (int j = 0; j < runner.size(); j++)
	//		{
	//			if (runner.at(j).Collision(abilityManager->BombardmentCollider(i)) && runner.at(j).IsAlive())
	//			{
	//				runner.at(j).Dead();
	//			}
	//		}
	//
	//		for (int j = 0; j < runner.size(); j++)
	//		{
	//			if (flier.at(j).Collision(abilityManager->BombardmentCollider(i)) && flier.at(j).IsAlive())
	//			{			  
	//				flier.at(j).Dead();
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	for (int i = 0; i < runner.size(); i++)
	//	{
	//		//runner.at(i).CircleCol(AbilityCol);
	//		if (runner.at(i).CircleCol(AbilityCol) && runner.at(i).IsAlive())
	//		{
	//			runner.at(i).Dead();
	//		}
	//	}
	//
	//	for (int i = 0; i < flier.size(); i++)
	//	{
	//		if (flier.at(i).Collision(AbilityCol) && flier.at(i).IsAlive())
	//		{
	//			flier.at(i).Dead();
	//		}
	//	}
	//}

	switch (abi)
	{
	case a:
		for (int i = 0; i < runner.size(); i++)
		{
			if (runner.at(i).CircleCol(AbilityCol,false) && runner.at(i).IsAlive())
			{
				runner.at(i).Dead();
			}
		}
		for (int i = 0; i < flier.size(); i++)
		{
			if (flier.at(i).CircleCol(AbilityCol, false) && flier.at(i).IsAlive())
			{
				flier.at(i).Dead();
			}
		}
		break;
	case s:
		for (int i = 0; i < abilityManager->FireBullets(); i++)//Å‘å”‚Ìæ“¾
		{
			for (int j = 0; j < runner.size(); j++)
			{
				if (runner.at(j).CircleCol(abilityManager->BombardmentCollider(i), false) && runner.at(j).IsAlive())
				{
					runner.at(j).Dead();
				}
			}

			for (int j = 0; j < runner.size(); j++)
			{
				if (flier.at(j).CircleCol(abilityManager->BombardmentCollider(i), false) && flier.at(j).IsAlive())
				{
					flier.at(j).Dead();
				}
			}
		}
		break;
	case d:
		break;
	case f:
		break;
	}
}
