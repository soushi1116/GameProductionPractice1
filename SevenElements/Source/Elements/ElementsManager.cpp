#include "ElementsManager.h"
#include "Elements.h"
#include "Fire.h"
#include "Ground.h"
#include "Ice.h"
#include "Iron.h"
#include "Thunder.h"
#include "Water.h"
#include "Wind.h"

Element* element = nullptr;

Fire* fire[FIRE_MAX]          = { nullptr };
Ground* ground[GROUND_MAX]    = { nullptr };
Ice* ice[ICE_MAX]             = { nullptr };
Iron* iron[IRON_MAX]          = { nullptr };
Thunder* thunder[THUNDER_MAX] = { nullptr };
Water* water[WATER_MAX]       = { nullptr };
Wind* wind[WIND_MAX]          = { nullptr };

void InitElementsManager()
{
	element = new Element;
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i] = new Fire;
		ground[i] = new Ground;
		ice[i] = new Ice;
		iron[i] = new Iron;
		thunder[i] = new Thunder;
		water[i] = new Water;
		wind[i] = new Wind;
	}
}

void LoadElementsManager()
{
	element->Load();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i]->Load();
		ground[i]->Load();
		ice[i]->Load();
		iron[i]->Load();
		thunder[i]->Load();
		water[i]->Load();
		wind[i]->Load();
	}
}

void StartElementsManager()
{
	element->Start();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i]->Start();
		ground[i]->Start();
		ice[i]->Start();
		iron[i]->Start();
		thunder[i]->Start();
		water[i]->Start();
		wind[i]->Start();
	}
}

void StepElementsManager()
{
	element->Step();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i]->Step();
		ground[i]->Step();
		ice[i]->Step();
		iron[i]->Step();
		thunder[i]->Step();
		water[i]->Step();
		wind[i]->Step();
	}
}

void UpdateElementsManager()
{
	element->Update();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i]->Update();
		ground[i]->Update();
		ice[i]->Update();
		iron[i]->Update();
		thunder[i]->Update();
		water[i]->Update();
		wind[i]->Update();
	}
}

void DrawElementsManager()
{
	element->Draw();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i]->Draw();
		ground[i]->Draw();
		ice[i]->Draw();
		iron[i]->Draw();
		thunder[i]->Draw();
		water[i]->Draw();
		wind[i]->Draw();
	}
}

void FinElementsManager()
{
	delete element;

	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		delete fire[i];
		delete ground[i];
		delete ice[i];
		delete iron[i];
		delete thunder[i];
		delete water[i];
		delete wind[i];
	}
}

void Action(int posX, int posY, ElementType type, bool isTurn)
{
	switch (type)
	{
	case ELEMENT_TYPE_NONE:
		break;

	case ELEMENT_TYPE_FIRE:
		for (int i = 0; i < FIRE_MAX; i++)
		{
			if (!fire[i]->IsActive())
			{
				fire[i]->Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_WATER:
		for (int i = 0; i < WATER_SPAWN_NUM; i++)
		{
			for (int j = 0; j < WATER_MAX; j++)
			{
				if (!water[j]->IsActive())
				{
					if (!isTurn)
					{
						water[j]->Spawn(posX + WATER_WIDTH * (WATER_SPAWN_NUM - i - 1) * WATER_SPAWN_OFFSET, posY, isTurn);
					}
					else
					{
						water[j]->Spawn(posX - WATER_WIDTH * (WATER_SPAWN_NUM - i - 1) * WATER_SPAWN_OFFSET, posY, isTurn);
					}

					break;
				}
			}
		}
		break;

	case ELEMENT_TYPE_THUNDER:
		for (int i = 0; i < THUNDER_MAX; i++)
		{
			if (!thunder[i]->IsActive())
			{
				thunder[i]->Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_WIND:
		for (int i = 0; i < WIND_MAX; i++)
		{
			if (!wind[i]->IsActive())
			{
				wind[i]->Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_GROUND:
		for (int i = 0; i < GROUND_MAX; i++)
		{
			if (!ground[i]->IsActive())
			{
				ground[i]->Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_ICE:
		for (int i = 0; i < ICE_MAX; i++)
		{
			if (!ice[i]->IsActive())
			{
				ice[i]->Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_IRON:
		for (int i = 0; i < IRON_MAX; i++)
		{
			if (!iron[i]->IsActive())
			{
				iron[i]->Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;
	case ELEMENT_TYPE_MAX:
		break;
	default:
		break;
	}

	
}

VECTOR GetElementPos(int index, ElementType type)
{
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);

	switch (type)
	{
	case ELEMENT_TYPE_NONE:
		break;
	case ELEMENT_TYPE_FIRE:
		pos = fire[index]->GetPos();
		break;
	case ELEMENT_TYPE_WATER:
		pos = water[index]->GetPos();
		break;
	case ELEMENT_TYPE_THUNDER:
		break;
	case ELEMENT_TYPE_WIND:
		break;
	case ELEMENT_TYPE_GROUND:
		pos = ground[index]->GetPos();
		break;
	case ELEMENT_TYPE_ICE:
		pos = ice[index]->GetPos();
		break;
	case ELEMENT_TYPE_IRON:
		pos = iron[index]->GetPos();
		break;
	case ELEMENT_TYPE_MAX:
		break;
	default:
		break;
	}
	return pos;
}

bool IsElementActive(int index, ElementType type)
{
	bool active = false;

	switch (type)
	{
	case ELEMENT_TYPE_NONE:
		break;
	case ELEMENT_TYPE_FIRE:
		active = fire[index]->IsActive();
		break;
	case ELEMENT_TYPE_WATER:
		active = water[index]->IsActive();
		break;
	case ELEMENT_TYPE_THUNDER:
		break;
	case ELEMENT_TYPE_WIND:
		break;
	case ELEMENT_TYPE_GROUND:
		active = ground[index]->IsActive();
		break;
	case ELEMENT_TYPE_ICE:
		active = ice[index]->IsActive();
		break;
	case ELEMENT_TYPE_IRON:
		active = iron[index]->IsActive();
		break;
	case ELEMENT_TYPE_MAX:
		break;
	default:
		break;
	}
	return active;
}

bool IsWaterFreeze(int index)
{
	return water[index]->IsFreeze();
	return iron[index]->IsActive();
}

void IronHitIron(int indexA, int indexB)
{
	int ironAPosY = iron[indexA]->GetPos().y;
	int ironBPosY = iron[indexB]->GetPos().y;

	if (ironAPosY < ironBPosY)
	{
		iron[indexA]->IronHitIron(indexA, indexB, ironBPosY);
	}
	else if (ironAPosY > ironBPosY)
	{
		iron[indexB]->IronHitIron(indexA, indexB, ironAPosY);
	}
}

void IronHitBlock(int indexA, int indexB)
{
	iron[indexA]->IronHitBlock(indexB);
}

void WaterHitBlock(int indexA, int indexB)
{
	water[indexA]->WaterHitBlock(indexB);
}

void GroundHitBlock(int indexA, int indexB)
{
	ground[indexA]->GroundHitBlock(indexB);
}

void FireDelete(int index)
{
	fire[index]->FireDelete();
}

void WindDelete(int index)
{
	wind[index]->WindDelete();
}

void WaterHitWater(int indexA, int indexB)
{
	int waterAPosX = water[indexA]->GetPos().x;
	int waterBPosX = water[indexB]->GetPos().x;

	int waterAPosY = water[indexA]->GetPos().y;
	int waterBPosY = water[indexB]->GetPos().y;

	int waterAMoveX = water[indexA]->GetMove().x;
	int waterBMoveX = water[indexB]->GetMove().x;

	if (waterAPosY < waterBPosY)
	{
		water[indexA]->WaterHitWater(indexA, indexB, waterBPosX, waterBPosY);
	}
	else if (waterAPosY > waterBPosY)
	{
		water[indexB]->WaterHitWater(indexA, indexB, waterAPosX, waterAPosY);
	}
	else
	{
		if (waterAMoveX != 0.0f)
		{
			water[indexA]->WaterHitWater(indexA, indexB, waterBPosX, waterBPosY);
		}
		else if (waterBMoveX != 0.0f)
		{
			water[indexB]->WaterHitWater(indexA, indexB, waterAPosX, waterAPosY);
		}
	}
}

void WaterHitFire(int index)
{
	water[index]->WaterHitFire();
}

void WaterHitIce(int index)
{
	water[index]->WaterHitIce();
}