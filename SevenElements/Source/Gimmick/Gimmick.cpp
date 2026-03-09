#include "Gimmick.h"
#include <map>

Reaction gReactionTable[ATTR_MAX][ATTR_MAX];
bool gIsFrozen = false;
int gPlayerX = 0;
int gPlayerY = 0;
bool gStageClear = false;

void FindSpawn(Attribute map[][MAP_W])
{
	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++)
		{
			if (map[y][x] == ATTR_SPAWN)
			{
				gPlayerX = x;
				gPlayerY = y;
				return;
			}
		}
	}
}

void CheckEvent(Attribute map[][MAP_W])
{
	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++)
		{
			if (map[y][x] == ATTR_BALLOON_FIRE)
			{
				if (y > 0 && map[y - 1][x] == ATTR_NONE)
				{
					map[y - 1][x] = ATTR_BALLOON_FIRE;
					map[y][x] = ATTR_NONE;
				}
			}
		}
	}
}

void InitGimmick()
{
	for (int i = 0; i < ATTR_MAX; i++)
	{
		for (int j = 0; j < ATTR_MAX; j++)
		{
			gReactionTable[i][j] = REACT_NONE;
		}
	}
	gIsFrozen = false;
}

void LoadGimmick()
{
	gReactionTable[ATTR_FIRE][ATTR_WATER] = REACT_EXTINGUISH;
	gReactionTable[ATTR_WATER][ATTR_FIRE] = REACT_EXTINGUISH;

	gReactionTable[ATTR_WATER][ATTR_ICE] = REACT_FREEZE;
	gReactionTable[ATTR_ICE][ATTR_WATER] = REACT_FREEZE;

	gReactionTable[ATTR_THUNDER][ATTR_METAL] = REACT_CONDUCT;
	gReactionTable[ATTR_METAL][ATTR_THUNDER] = REACT_CONDUCT;

	gReactionTable[ATTR_FIRE][ATTR_GRASS] = REACT_BURN_GRASS;
	gReactionTable[ATTR_GRASS][ATTR_FIRE] = REACT_BURN_GRASS;

	gReactionTable[ATTR_FIRE][ATTR_BALLOON] = REACT_BALLOON_UP;
	gReactionTable[ATTR_BALLOON][ATTR_FIRE] = REACT_BALLOON_UP;
}

void StartGimmick(Attribute map[][MAP_W])
{
	gIsFrozen = false;
    gStageClear = false;
    FindSpawn(map);

}

void StepGimmick(int xA, int yA, int xB, int yB,Attribute map[][MAP_W])
{
	Attribute attrA = map[yA][xA];
	Attribute attrB = map[yB][xB];
	Reaction r = gReactionTable[attrA][attrB];
	Attribute attr = map[gPlayerY][gPlayerX];
	if (gIsFrozen)
		return;
	switch (r)
	{
	case REACT_EXTINGUISH:
		if (attrA == ATTR_FIRE) map[yA][xA] = ATTR_NONE;
		if (attrB == ATTR_FIRE) map[yB][xB] = ATTR_NONE;
		break;

	case REACT_FREEZE:
		if (attrA == ATTR_WATER) map[yA][xA] = ATTR_ICE;
		if (attrB == ATTR_WATER) map[yB][xB] = ATTR_ICE;
		gIsFrozen = true;
		break;

	case REACT_CONDUCT:
		break;

	case REACT_BURN_GRASS:
		if (attrA == ATTR_GRASS)
		{
			map[yA][xA] = ATTR_NONE;
		}
		if (attrB == ATTR_GRASS)
		{
			map[yB][xB] = ATTR_NONE;
		}
		break;
	case REACT_BALLOON_UP:
	{
		int bx = -1;
		int by = -1;

		if (attrA == ATTR_BALLOON) { bx = xA; by = yA; }
		if (attrB == ATTR_BALLOON) { bx = xB; by = yB; }

		if (bx != -1)
		{
			if (bx != -1)
			{
				map[by][bx] = ATTR_BALLOON_FIRE;
			}
		}
	}
	break;
	}
	switch (attr)
	{
	case ATTR_WARP_IN_A:
		// 22‚ð’T‚·
		for (int y = 0; y < MAP_H; y++)
		{
			for (int x = 0; x < MAP_W; x++)
			{
				if (map[y][x] == ATTR_WARP_OUT_A)
				{
					gPlayerX = x;
					gPlayerY = y;
					return;
				}
			}
		}
		break;

	case ATTR_WARP_IN_B:
		for (int y = 0; y < MAP_H; y++)
		{
			for (int x = 0; x < MAP_W; x++)
			{
				if (map[y][x] == ATTR_WARP_OUT_B)
				{
					gPlayerX = x;
					gPlayerY = y;
					return;
				}
			}
		}
		break;

	case ATTR_GOAL:
		gStageClear = true;
		break;
	}
}

void DrawGimmick()
{
	if (gIsFrozen)
	{

	}
}

void FinGimmick()
{
}

int main()
{
	InitGimmick();
	LoadGimmick();

	Attribute map[MAP_H][MAP_W];

	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++)
		{
			map[y][x] = ATTR_NONE;
		}
	}

	while (true)
	{
		int xA = 0;
		int yA = 0;
		int xB = 1;
		int yB = 0;

		StepGimmick(xA, yA, xB, yB, map);
		CheckEvent(map);
		DrawGimmick();
	}
	while (true)
	{
		CheckEvent(map);

		if (gStageClear)
		{
			printf("STAGE CLEAR!\n");
			break;
		}
	}
	FinGimmick();
	return 0;
}




