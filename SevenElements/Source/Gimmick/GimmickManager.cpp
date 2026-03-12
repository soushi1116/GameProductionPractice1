#include "DxLib.h"
#include "GimmickManager.h"
#include "Gimmick.h"
#include "Tree.h"
#include "AirBalloon.h"
#include "WoodBlock.h"
#include "WaterGimmick.h"
#include "FireGimmick.h"
#include "Battery.h"
#include "Windmill.h"
#include "MoveBlock.h"
#include "Warp.h"
#include "Goal.h"

Gimmick* gimmick = nullptr;

Tree* tree[TREE_MAX] = { nullptr };
AirBalloon* airBalloon[AIRBALLOON_MAX] = { nullptr };
WoodBlock* woodBlock[WOODBLOCK_MAX] = { nullptr };
WaterGimmick* waterGimmick[WATER_GIMMICK_MAX] = { nullptr };
FireGimmick* fireGimmick[FIREGIMMICK_MAX] = { nullptr };
Battery* battery[BATTERY_MAX] = { nullptr };
Windmill* windmill[WINDMILL_MAX] = { nullptr };
MoveBlock* moveBlock[MOVEBLOCK_MAX] = { nullptr };
Warp* warp[WARP_MAX] = { nullptr };
Goal* goal[GOAL_MAX] = { nullptr };

void InitGimmickManager()
{
	gimmick = new Gimmick;
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i] = new Tree;
		airBalloon[i] = new AirBalloon;
		woodBlock[i] = new WoodBlock;
		waterGimmick[i] = new WaterGimmick;
		fireGimmick[i] = new FireGimmick;
		battery[i] = new Battery;
		windmill[i] = new Windmill;
		moveBlock[i] = new MoveBlock;
		warp[i] = new Warp;
		goal[i] = new Goal;
	}
}

void LoadGimmickManager()
{
	gimmick->Load();
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i]->Load();
		airBalloon[i]->Load();
		woodBlock[i]->Load();
		waterGimmick[i]->Load();
		fireGimmick[i]->Load();
		battery[i]->Load();
		windmill[i]->Load();
		moveBlock[i]->Load();
		warp[i]->Load();
		goal[i]->Load();
	}
}

void StartGimmickManager()
{
	gimmick->Start();
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i]->Start();
		airBalloon[i]->Start();
		woodBlock[i]->Start();
		waterGimmick[i]->Start();
		fireGimmick[i]->Start();
		battery[i]->Start();
		windmill[i]->Start();
		moveBlock[i]->Start();
		warp[i]->Start();
		goal[i]->Start();
	}
}

void StepGimmickManager()
{
	gimmick->Step();
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i]->Step();
		airBalloon[i]->Step();
		woodBlock[i]->Step();
		waterGimmick[i]->Step();
		fireGimmick[i]->Step();
		battery[i]->Step();
		windmill[i]->Step();
		moveBlock[i]->Step();
		warp[i]->Step();
		goal[i]->Step();
	}
}

void UpdateGimmickManager()
{
	gimmick->Update();
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i]->Update();
		airBalloon[i]->Update();
		woodBlock[i]->Update();
		waterGimmick[i]->Update();
		fireGimmick[i]->Update();
		battery[i]->Update();
		windmill[i]->Update();
		moveBlock[i]->Update();
		warp[i]->Update();
		goal[i]->Update();
	}
}

void DrawGimmickManager()
{
	gimmick->Draw();
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i]->Draw();
		airBalloon[i]->Draw();
		woodBlock[i]->Draw();
		waterGimmick[i]->Draw();
		fireGimmick[i]->Draw();
		battery[i]->Draw();
		windmill[i]->Draw();
		moveBlock[i]->Draw();
		warp[i]->Draw();
		goal[i]->Draw();
	}
}

void FinGimmickManager()
{
	delete gimmick;

	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		delete tree[i];
		delete airBalloon[i];
		delete woodBlock[i];
		delete waterGimmick[i];
		delete fireGimmick[i];
		delete battery[i];
		delete windmill[i];
		delete moveBlock[i];
		delete warp[i];
		delete goal[i];
	}
}

void SpawnGimmick(int posX, int posY, GimmickType type)
{
	switch (type)
	{
	case GIMMICK_TYPE_NONE:
		break;

	case GIMMICK_TYPE_TREE:
		for (int i = 0; i < TREE_MAX; i++)
		{
			if (!tree[i]->IsActive())
			{
				tree[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_AIRBALLOON:
		for (int i = 0; i < AIRBALLOON_MAX; i++)
		{
			if (!airBalloon[i]->IsActive())
			{
				airBalloon[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_WOODBLOCK:
		for (int i = 0; i < AIRBALLOON_MAX; i++)
		{
			if (!woodBlock[i]->IsActive())
			{
				woodBlock[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_FIRE:
		for (int i = 0; i < FIREGIMMICK_MAX; i++)
		{
			if (!fireGimmick[i]->IsActive())
			{
				fireGimmick[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_BATTERY:
		for (int i = 0; i < BATTERY_MAX; i++)
		{
			if (!battery[i]->IsActive())
			{
				battery[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_WINDMILL:
		for (int i = 0; i < WINDMILL_MAX; i++)
		{
			if (!windmill[i]->IsActive())
			{
				windmill[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_MOVEBLOCK:
		for (int i = 0; i < MOVEBLOCK_MAX; i++)
		{
			if (!moveBlock[i]->IsActive())
			{
				moveBlock[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_WARP:
		for (int i = 0; i < WARP_MAX; i++)
		{
			if (!warp[i]->IsActive())
			{
				warp[i]->Spawn(posX, posY);

				break;
			}
		}
		break;

	case GIMMICK_TYPE_GOAL:
		for (int i = 0; i < GOAL_MAX; i++)
		{
			if (!goal[i]->IsActive())
			{
				goal[i]->Spawn(posX, posY);

				break;
			}
		}
		break;
	case GIMMICK_TYPE_MAX:
		break;
	default:
		break;
	}
}

void TreeHitFire(int index)
{
	tree[index]->TreeHitFire();
}

void AirBalloonHitFire(int index)
{
	airBalloon[index]->AirBalloonHitFire();
}

void AirBalloonHitBlock(int index)
{
	airBalloon[index]->AirBalloonHitBlock();
}

void WoodBlockHitBlock(int indexA, int indexB)
{
	woodBlock[indexA]->WoodBlockHitBlock(indexB);
}

void WoodBlockHitWind(int indexA, int indexB)
{
	woodBlock[indexB]->WoodBlockHitWind(indexA);
}

void FireGimmickHitWater(int index)
{
	fireGimmick[index]->Delete();
}

void BatteryHitThunder(int index)
{
	battery[index]->BatteryHitThunder();
}

void WindmillHitWind(int index)
{
	windmill[index]->WindmillHitWind();
}

VECTOR GetGimmickPos(int index, GimmickType type)
{
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);

	switch (type)
	{
	case GIMMICK_TYPE_NONE:
		break;
	case GIMMICK_TYPE_TREE:
		pos = tree[index]->GetPos();
		break;
	case GIMMICK_TYPE_AIRBALLOON:
		pos = airBalloon[index]->GetPos();
		break;
	case GIMMICK_TYPE_WOODBLOCK:
		pos = woodBlock[index]->GetPos();
		break;
	case GIMMICK_TYPE_FIRE:
		pos = fireGimmick[index]->GetPos();
		break;
	case GIMMICK_TYPE_BATTERY:
		pos = battery[index]->GetPos();
		break;
	case GIMMICK_TYPE_WINDMILL:
		pos = windmill[index]->GetPos();
		break;
	case GIMMICK_TYPE_MOVEBLOCK:
		pos = moveBlock[index]->GetPos();
		break;
	case GIMMICK_TYPE_WARP:
		pos = warp[index]->GetPos();
		break;
	case GIMMICK_TYPE_GOAL:
		pos = goal[index]->GetPos();
		break;
	default:
		break;
	}
	return pos;
}

VECTOR GetGimmickMove(int index, GimmickType type)
{
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);

	switch (type)
	{
	case GIMMICK_TYPE_NONE:
		break;
	case GIMMICK_TYPE_TREE:
		break;
	case GIMMICK_TYPE_AIRBALLOON:
		break;
	case GIMMICK_TYPE_WOODBLOCK:
		break;
	case GIMMICK_TYPE_FIRE:
		break;
	case GIMMICK_TYPE_BATTERY:
		break;
	case GIMMICK_TYPE_WINDMILL:
		break;
	case GIMMICK_TYPE_MOVEBLOCK:
		move = moveBlock[index]->GetMove();
		break;
	case GIMMICK_TYPE_WARP:
		break;
	case GIMMICK_TYPE_GOAL:
		break;
	case GIMMICK_TYPE_MAX:
		break;
	default:
		break;
	}
	return move;
}

bool IsGimmickActive(int index, GimmickType type)
{
	bool active = false;

	switch (type)
	{
	case GIMMICK_TYPE_NONE:
		break;
	case GIMMICK_TYPE_TREE:
		active = tree[index]->IsActive();
		break;
	case GIMMICK_TYPE_AIRBALLOON:
		active = airBalloon[index]->IsActive();
		break;
	case GIMMICK_TYPE_WOODBLOCK:
		active = woodBlock[index]->IsActive();
		break;
	case GIMMICK_TYPE_FIRE:
		active = fireGimmick[index]->IsActive();
		break;
	case GIMMICK_TYPE_BATTERY:
		active = battery[index]->IsActive();
		break;
	case GIMMICK_TYPE_WINDMILL:
		active = windmill[index]->IsActive();
		break;
	case GIMMICK_TYPE_MOVEBLOCK:
		active = moveBlock[index]->IsActive();
		break;
	case GIMMICK_TYPE_WARP:
		active = warp[index]->IsActive();
		break;
	case GIMMICK_TYPE_GOAL:
		active = goal[index]->IsActive();
		break;
	default:
		break;
	}
	return active;
}

bool AirBalloonBurning(int index)
{
	return airBalloon[index]->Burning();
}