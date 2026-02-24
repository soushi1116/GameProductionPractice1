#include "ElementsManager.h"
#include "Elements.h"
#include "Fire.h"
#include "Ground.h"
#include "Ice.h"
#include "Iron.h"
#include "Thunder.h"
#include "Water.h"
#include "Wind.h"

Element* element = new Element;

Fire fire       [FIRE_MAX];
Ground ground   [GROUND_MAX];
Ice ice         [ICE_MAX];
Iron iron       [IRON_MAX];
Thunder thunder [THUNDER_MAX];
Water water     [WATER_MAX];
Wind wind       [WIND_MAX];

void InitElementsManager()
{
	for (int i = 0; i < IRON_MAX; i++)
	{
		if (!iron[i].IsActive())
		{
			iron[i].Spawn(400.0f, 0.0f, false);

			break;
		}
	}
}

void LoadElementsManager()
{
	element->Load();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i].Load();
		ground[i].Load();
		ice[i].Load();
		iron[i].Load();
		thunder[i].Load();
		water[i].Load();
		wind[i].Load();
	}
}

void StartElementsManager()
{
	element->Start();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i].Start();
		ground[i].Start();
		ice[i].Start();
		iron[i].Start();
		thunder[i].Start();
		water[i].Start();
		wind[i].Start();
	}
}

void StepElementsManager()
{
	element->Step();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i].Step();
		ground[i].Step();
		ice[i].Step();
		iron[i].Step();
		thunder[i].Step();
		water[i].Step();
		wind[i].Step();
	}
}

void UpdateElementsManager()
{
	element->Update();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i].Update();
		ground[i].Update();
		ice[i].Update();
		iron[i].Update();
		thunder[i].Update();
		water[i].Update();
		wind[i].Update();
	}
}

void DrawElementsManager()
{
	element->Draw();
	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		fire[i].Draw();
		ground[i].Draw();
		ice[i].Draw();
		iron[i].Draw();
		thunder[i].Draw();
		water[i].Draw();
		wind[i].Draw();
	}
}

void FinElementsManager()
{
	delete element;

	for (int i = 0; i < ELEMENTS_MAX; i++)
	{
		delete fire;
		delete ground;
		delete ice;
		delete iron;
		delete thunder;
		delete water;
		delete wind;
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
			if (!fire[i].IsActive())
			{
				fire[i].Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_WATER:
		for (int i = 0; i < WATER_MAX; i++)
		{
			if (!water[i].IsActive())
			{
				water[i].Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_THUNDER:
		for (int i = 0; i < THUNDER_MAX; i++)
		{
			if (!thunder[i].IsActive())
			{
				thunder[i].Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_WIND:
		for (int i = 0; i < WIND_MAX; i++)
		{
			if (!wind[i].IsActive())
			{
				wind[i].Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_GROUND:
		for (int i = 0; i < GROUND_MAX; i++)
		{
			if (!ground[i].IsActive())
			{
				ground[i].Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_ICE:
		for (int i = 0; i < ICE_MAX; i++)
		{
			if (!ice[i].IsActive())
			{
				ice[i].Spawn(posX, posY, isTurn);

				break;
			}
		}
		break;

	case ELEMENT_TYPE_IRON:
		for (int i = 0; i < IRON_MAX; i++)
		{
			if (!iron[i].IsActive())
			{
				iron[i].Spawn(posX, posY, isTurn);

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

VECTOR GetIronPos(int index)
{
	float posX = 0.0f;
	float posY = 0.0f;
	VECTOR pos = iron[index].GetPos();
	return pos;
}

bool IsIronActive(int index)
{
	return iron[index].IsActive();
}

void IronHitIron(int indexA, int indexB)
{
	int ironAPosY = iron[indexA].GetPos().y;
	int ironBPosY = iron[indexB].GetPos().y;

	if (ironAPosY < ironBPosY)
	{
		iron[indexA].IronHitIron(indexA, indexB, ironBPosY);
	}
	else if (ironAPosY > ironBPosY)
	{
		iron[indexB].IronHitIron(indexA, indexB, ironAPosY);
	}
}