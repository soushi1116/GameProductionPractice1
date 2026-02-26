#include "Block.h"
#include "../Camera/Camera.h"
#include "MapChip.cpp"

BlockData g_Blocks[BLOCK_MAX] = { 0 };
int g_BlockHandle[BLOCK_TYPE_MAX] = { 0 };


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
	for (int i = 0; i < MAP_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < MAP_CHIP_Y_NUM; j++)
		{
			MapChipType type = (MapChipType)g_MapChip[i][j].mapChip;

			if (type == MAP_CHIP_NONE) continue;

			VECTOR pos = VGet(j * MAP_CHIP_WIDTH, i * MAP_CHIP_HEIGHT, 0.0f);

			g_MapChip[i][j].data = CreateBlock(type, pos);
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
