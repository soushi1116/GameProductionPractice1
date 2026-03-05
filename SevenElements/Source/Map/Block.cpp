#include "Block.h"
#include "../Camera/Camera.h"
#include "MapChip.h"
#include <fstream>
#include <sstream>
#include <string>
#define MAP_WIDTH   10      
#define MAP_HEIGHT  5       
#define CHIP_SIZE   64 
int mapData[MAP_HEIGHT][MAP_WIDTH];

BlockData g_Blocks[BLOCK_MAX] = { 0 };
int g_BlockHandle[BLOCK_TYPE_MAX] = { 0 };

void LoadMapCSV(const char* filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
		return;

	std::string line;
	int y = 0;

	while (std::getline(file, line) && y < MAP_HEIGHT)
	{
		std::stringstream ss(line);
		std::string value;
		int x = 0;

		while (std::getline(ss, value, ',') && x < MAP_WIDTH)
		{
			mapData[y][x] = atoi(value.c_str());
			x++;
		}

		y++;
	}

	file.close();
}

void InitBlock()
{
	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		block->active = false;
		block->pos = VGet(0.0f, 0.0f, 0.0f);
		block->type = MAP_CHIP_NONE;
	}
}

void LoadBlock()
{
	g_BlockHandle[NORMAL_BLOCK] = LoadGraph("Data/Map/NormalBlock.png");
}

void StartBlock()
{
	LoadMapCSV("Data/Map/仮map.csv");

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (mapData[y][x] == 1)
			{
				VECTOR pos = VGet(x * CHIP_SIZE, y * CHIP_SIZE, 0.0f);
				CreateBlock(NORMAL_BLOCK, pos);
			}
		}
	}
}

void StepBlock()
{

}

void DrawBlock()
{
	// スクロールのためカメラを取得
	CameraData camera = GetCamera();

	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (block->active)
		{
			DrawGraph((int)(block->pos.x - camera.posX), (int)(block->pos.y - camera.posY), block->handle, TRUE);
		}
	}
}

void FinBlock()
{
}

BlockData* CreateBlock(MapChipType type, VECTOR pos)
{
	// 未使用のブロックを探す
	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (!block->active)
		{
			// ブロック生成
			block->active = true;
			block->handle = g_BlockHandle[type];
			block->pos = pos;
			block->type = type;
			return block;
		}
	}

	return nullptr;
}

BlockData* GetBlocks()
{
	return g_Blocks;
}
