#include "Player.h"

Player::Player()
{
	inputManager = InputManager::Instance();
	cursorManager = CursorManager::Instance();
	Init();
}

void Player::Update(bool hit_)
{
	cursor = cursorManager.lock()->GetMousePos();

	Status(hit_);
	BulletUpdate();
	radian = atan2(cursor.y - player.y, cursor.x - player.x);
	barrelAnglePos = { player.x + playerSize.x / 2,player.y + playerSize.y / 2 };
}

void Player::Draw(std::weak_ptr<TextureManager>textureManger)
{
	for (int i = 0; i < bullet.size()-1; i++)
	{
		if (bullet.at(i).IsAlive())
		{
			bullet.at(i).Draw(textureManger);
		}
	}
	
	//DrawCircle(cursor.x, cursor.y, 10, GetColor(0, 255, 0), TRUE);
	DrawExtendGraph(player.x, player.y, player.x + playerSize.x, player.y + playerSize.y, textureManger.lock()->GetDivTexture("PLAYER", 0), TRUE);
	DrawRotaGraph2(player.x + playerSize.x / 2, player.y + playerSize.y / 2, 1,16, 1.0f,radian, textureManger.lock()->GetDivTexture("PLAYER", 1), TRUE,TRUE);
	
}

Collision::Collider::collider Player::PlayerCollider()
{
	Col.size = playerSize;
	Col.vec = player;
	return Col;
}

void Player::Init()
{
	bullet.emplace_back();
	player.vec2(100, 493);
	playerSize.vec2(32, 32);
	alive = true;
	health = INIT_HEALTH;
}

void Player::Status(bool hit_)
{
	if (inputManager.lock()->KeyPushed(KEY_INPUT_SPACE))
	{
		player.y -= 40;
	}
	else if (inputManager.lock()->KeyRelease(KEY_INPUT_SPACE))
	{
		player.y += 40;
	}

	if (cursorManager.lock()->Push(MOUSE_INPUT_LEFT) && COOL_TIME <= Timer)
	{
		BulletCreate();
		Timer = 0;
	}

	if (inputManager.lock()->KeyPushed(KEY_INPUT_A))
	{
		abi = Ability::a;
	}
	else if (inputManager.lock()->KeyPushed(KEY_INPUT_S))
	{
		abi = Ability::s;
	}
	else if (inputManager.lock()->KeyPushed(KEY_INPUT_D))
	{
		abi = Ability::d;
	}
	else if (inputManager.lock()->KeyPushed(KEY_INPUT_F))
	{
		abi = Ability::f;
	}
	else
	{
		abi = Ability::none;
	}
	Timer++;

	//if (hit_)
	//{
	//	health--;
	//	if (health <= 0)
	//	{
	//		alive = false;
	//	}
	//}
}

void Player::BulletCreate()
{
	//Vector2
	for (int i = 0; i < bullet.size(); i++)
	{
		if (!bullet.at(i).IsAlive())
		{
			bullet.at(i).Create(player,playerSize);
			break;
		}
	}
	if (bullet.at(bullet.size() - 1).IsAlive())
	{
		bullet.emplace_back();
	}
}

void Player::BulletUpdate()
{
	for (int i = 0; i < bullet.size()-1; i++)
	{
		if (bullet.at(i).IsAlive())
		{
			bullet.at(i).Update(cursor);
		}
	}
}
