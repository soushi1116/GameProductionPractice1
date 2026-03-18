#include "MapChip.h"
#include "DxLib.h"
#include "../GameSetting/GameSetting.h"
#include "MapParameter.h"
#include "Block.h"

MapChipData g_MapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };


void LoadMapChipData(int stage)
{
	FILE* fp;
	if (fopen_s(&fp, "Data/Map/Block(pre).bin", "rb") != 0) return;
	switch (stage)
	{
	case 1:
		if (fopen_s(&fp, "Data/Map/Block_Stage1.bin", "rb") != 0) return;
		break;
	case 2:
		if (fopen_s(&fp, "Data/Map/Block_Stage2.bin", "rb") != 0) return;
		break;
	case 3:
		if (fopen_s(&fp, "Data/Map/Block_Stage3.bin", "rb") != 0) return;
		break;
	default:
		break;
	}

	for (int i = 0; i < MAP_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < MAP_CHIP_X_NUM; j++)
		{
			int map = fgetc(fp);
			g_MapChip[i][j].mapChip = map;
		}
	}
	fclose(fp);
}

void CreateMap()
{
	for (int i = 0; i < MAP_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < MAP_CHIP_X_NUM; j++)
		{
			MapChipType type = (MapChipType)g_MapChip[i][j].mapChip;

			if (type == MAP_CHIP_NONE) continue;

			VECTOR pos = VGet(j * MAP_CHIP_WIDTH, i * MAP_CHIP_HEIGHT, 0.0f);

			g_MapChip[i][j].data = CreateBlock(type, pos);
		}
	}
}


MapChipData GetMapChipData(int x, int y)
{
	return g_MapChip[y][x];
}