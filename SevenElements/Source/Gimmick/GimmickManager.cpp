#include "DxLib.h"
#include "GimmickManager.h"
#include "Gimmick.h"
#include "Tree.h"
#include "AirBalloon.h"
#include "WoodBlock.h"
#include "WaterGimmick.h"

Gimmick* gimmick = nullptr;

Tree* tree[TREE_MAX] = { nullptr };
AirBalloon* airBalloon[AIRBALLOON_MAX] = { nullptr };
WoodBlock* woodBlock[WOODBLOCK_MAX] = { nullptr };
WaterGimmick* waterGimmick[WATER_GIMMICK_MAX] = { nullptr };

void InitGimmickManager()
{
	gimmick = new Gimmick;
	for (int i = 0; i < GIMMICK_MAX; i++)
	{
		tree[i] = new Tree;
		airBalloon[i] = new AirBalloon;
		woodBlock[i] = new WoodBlock;
		waterGimmick[i] = new WaterGimmick;
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

VECTOR GetGimmickPos(int index, GimmickType type)
{
	float posX = 0.0f;
	float posY = 0.0f;

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
	default:
		break;
	}
	return pos;
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
	default:
		break;
	}
	return active;
}

bool AirBalloonBurning(int index)
{
	return airBalloon[index]->Burning();
}