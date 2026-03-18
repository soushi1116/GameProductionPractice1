#include "DxLib.h"
#include "Collision.h"
#include "../Player/Player.h"
#include "../Map/Block.h"
#include "../Map/MapManager.h"
#include "../Map/MapParameter.h"
#include "../Elements/Iron.h"
#include "../Elements/Fire.h"
#include "../Elements/Water.h"
#include "../Elements/Ice.h"
#include "../Elements/Ground.h"
#include "../Elements/Wind.h"
#include "../Elements/Thunder.h"
#include "../Elements/ElementsManager.h"
#include "../Elements/Elements.h"
#include "../Gimmick/GimmickManager.h"
#include "../Gimmick/Tree.h"
#include "../Gimmick/AirBalloon.h"
#include "../Gimmick/WoodBlock.h"
#include "../Gimmick/FireGimmick.h"
#include "../Gimmick/Battery.h"
#include "../Gimmick/Windmill.h"
#include "../Gimmick/MoveBlock.h"
#include "../Gimmick/Warp.h"
#include "../Gimmick/Goal.h"
#include "../Enemy/EnemyFlyCircle.h"
#include "../Enemy/EnemyFlyCircle2.h"
#include "../Enemy/EnemyTurret.h"
#include "../Enemy/EnemyFlyStraight.h"
#include "../Enemy/EnemyWalk.h"

bool CheckSquareSquare(float squareA_PosX, float squareA_PosY, float squareA_Width, float squareA_Height,
	float squareB_PosX, float squareB_PosY, float squareB_Width, float squareB_Height)
{
	float leftA = squareA_PosX;
	float rightA = squareA_PosX + squareA_Width;
	float topA = squareA_PosY;
	float bottomA = squareA_PosY + squareA_Height;

	float leftB = squareB_PosX;
	float rightB = squareB_PosX + squareB_Width;
	float topB = squareB_PosY;
	float bottomB = squareB_PosY + squareB_Height;

	if (rightA >= leftB && leftA <= rightB)
	{
		if (bottomA >= topB && topA <= bottomB)
		{
			return true;
		}
	}

	return false;
}

void CheckPlayerMap()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		BlockData* block = GetBlocks();

		for (int i = 0; i < BLOCK_MAX; i++, block++)
		{
			if (!block->active) continue;

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				PlayerHitBlock(i);
			}
		}
	}
}

void CheckFireMap()
{
	for (int i = 0; i < FIRE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_FIRE)) continue;

		BlockData* block = GetBlocks();

		for (int j = 0; j < BLOCK_MAX; j++, block++)
		{
			if (!block->active) continue;

			VECTOR firePos = GetElementPos(i, ELEMENT_TYPE_FIRE);

			if (CheckSquareSquare(firePos.x, firePos.y, FIRE_WIDTH, FIRE_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				FireDelete(i);
			}
		}
	}
}

void CheckIronMap()
{
	for (int i = 0; i < IRON_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_IRON)) continue;
		
		BlockData* block = GetBlocks();

		for (int j = 0; j < BLOCK_MAX; j++, block++)
		{
			if (!block->active) continue;

			VECTOR ironPos = GetElementPos(i, ELEMENT_TYPE_IRON);

			if (CheckSquareSquare(ironPos.x, ironPos.y, IRON_WIDTH, IRON_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				IronHitBlock(i, j);
			}
		}		
	}
}

void CheckWaterMap()
{
	for (int i = 0; i < WATER_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_WATER)) continue;

		BlockData* block = GetBlocks();

		for (int j = 0; j < BLOCK_MAX; j++, block++)
		{
			if (!block->active) continue;

			VECTOR waterPos = GetElementPos(i, ELEMENT_TYPE_WATER);

			if (CheckSquareSquare(waterPos.x, waterPos.y, WATER_WIDTH, WATER_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				WaterHitBlock(i, j);
			}
		}
	}
}


void CheckGroundMap()
{
	for (int i = 0; i < GROUND_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_GROUND)) continue;

		BlockData* block = GetBlocks();

		for (int j = 0; j < BLOCK_MAX; j++, block++)
		{
			if (!block->active) continue;

			VECTOR groundPos = GetElementPos(i, ELEMENT_TYPE_GROUND);

			if (CheckSquareSquare(groundPos.x, groundPos.y, GROUND_WIDTH, GROUND_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				GroundHitBlock(i, j);
			}
		}
	}
}

void CheckWoodBlockMap()
{
	for (int i = 0; i < WOODBLOCK_MAX; i++)
	{
		if (!IsGimmickActive(i, GIMMICK_TYPE_WOODBLOCK)) continue;

		BlockData* block = GetBlocks();

		for (int j = 0; j < BLOCK_MAX; j++, block++)
		{
			if (!block->active) continue;

			VECTOR woodBlockPos = GetGimmickPos(i, GIMMICK_TYPE_WOODBLOCK);

			if (CheckSquareSquare(woodBlockPos.x, woodBlockPos.y, WOODBLOCK_WIDTH, WOODBLOCK_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				WoodBlockHitBlock(i, j);
			}
		}
	}
}

void CheckAirBalloonMap()
{
	for (int i = 0; i < AIRBALLOON_MAX; i++)
	{
		if (!IsGimmickActive(i, GIMMICK_TYPE_AIRBALLOON)) continue;

		BlockData* block = GetBlocks();

		for (int j = 0; j < BLOCK_MAX; j++, block++)
		{
			if (!block->active) continue;

			VECTOR airBalloonPos = GetGimmickPos(i, GIMMICK_TYPE_AIRBALLOON);

			if (CheckSquareSquare(airBalloonPos.x, airBalloonPos.y, AIRBALLOON_WIDTH, AIRBALLOON_HEIGHT,
				block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				AirBalloonHitBlock(i);
			}
		}
	}
}


void CheckPlayerIron()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < IRON_MAX; i++)
		{
			if (!IsElementActive(i, ELEMENT_TYPE_IRON)) continue;

			VECTOR ironPos = GetElementPos(i, ELEMENT_TYPE_IRON);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				ironPos.x, ironPos.y, IRON_WIDTH, IRON_HEIGHT))
			{
				PlayerHitIron(i);
			}
		}
	}
}

void CheckPlayerGround()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < GROUND_MAX; i++)
		{
			if (!IsElementActive(i, ELEMENT_TYPE_GROUND)) continue;

			VECTOR groundPos = GetElementPos(i, ELEMENT_TYPE_GROUND);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				groundPos.x, groundPos.y, GROUND_WIDTH, GROUND_HEIGHT))
			{
				PlayerHitGround(i);
			}
		}
	}
}

void CheckPlayerWater()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < WATER_MAX; i++)
		{
			if (!IsElementActive(i, ELEMENT_TYPE_WATER)) continue;

			VECTOR waterPos = GetElementPos(i, ELEMENT_TYPE_WATER);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				waterPos.x, waterPos.y, WATER_WIDTH, WATER_HEIGHT))
			{
				PlayerHitWater(i);
			}
		}
	}
}

void CheckPlayerTree()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < TREE_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_TREE)) continue;

			VECTOR treePos = GetGimmickPos(i, GIMMICK_TYPE_TREE);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				treePos.x, treePos.y, TREE_WIDTH, TREE_HEIGHT))
			{
				PlayerHitTree(i);
			}
		}
	}
}

void CheckPlayerAirBalloon()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < AIRBALLOON_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_AIRBALLOON)) continue;

			VECTOR airballoonPos = GetGimmickPos(i, GIMMICK_TYPE_AIRBALLOON);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				airballoonPos.x, airballoonPos.y, AIRBALLOON_WIDTH, AIRBALLOON_HEIGHT))
			{
				PlayerHitAirBalloon(i);
			}
		}
	}
}

void CheckPlayerWarp()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < WARP_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_WARP)) continue;

			VECTOR warpPos = GetGimmickPos(i, GIMMICK_TYPE_WARP);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				warpPos.x, warpPos.y, WARP_WIDTH, WARP_HEIGHT))
			{
				PlayerHitWarp();
			}
		}
	}
}

void CheckPlayerGoal()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < GOAL_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_GOAL)) continue;

			VECTOR goalPos = GetGimmickPos(i, GIMMICK_TYPE_GOAL);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				goalPos.x, goalPos.y, GOAL_WIDTH, GOAL_HEIGHT))
			{
				PlayerHitGoal();
			}
		}
	}
}

void CheckPlayerWoodBlock()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < WOODBLOCK_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_WOODBLOCK)) continue;

			VECTOR woodBlockPos = GetGimmickPos(i, GIMMICK_TYPE_WOODBLOCK);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				woodBlockPos.x, woodBlockPos.y, WOODBLOCK_WIDTH, WOODBLOCK_HEIGHT))
			{
				PlayerHitWoodBlock(i);
			}
		}
	}
}

void CheckPlayerMoveBlock()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < MOVEBLOCK_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_MOVEBLOCK)) continue;

			VECTOR moveBlockPos = GetGimmickPos(i, GIMMICK_TYPE_MOVEBLOCK);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				moveBlockPos.x, moveBlockPos.y, MOVEBLOCK_WIDTH, MOVEBLOCK_HEIGHT))
			{
				PlayerHitMoveBlock(i);
			}
		}
	}
}

void CheckPlayerFireGimmick()
{
	PlayerData player = GetPlayer();

	if (player.active)
	{
		for (int i = 0; i < FIREGIMMICK_MAX; i++)
		{
			if (!IsGimmickActive(i, GIMMICK_TYPE_FIRE)) continue;

			VECTOR firePos = GetGimmickPos(i, GIMMICK_TYPE_FIRE);

			if (CheckSquareSquare(player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
				firePos.x, firePos.y, FIREGIMMICK_WIDTH, FIREGIMMICK_HEIGHT))
			{
				PlayerHitFireGimmick();
			}
		}
	}
}

void CheckGroundGround()
{
	for (int i = 0; i < GROUND_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_GROUND)) continue;

		for (int j = i + 1; j < GROUND_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_GROUND)) continue;

			VECTOR groundAPos = GetElementPos(i, ELEMENT_TYPE_GROUND);
			VECTOR groundBPos = GetElementPos(j, ELEMENT_TYPE_GROUND);

			if (CheckSquareSquare(groundAPos.x, groundAPos.y, GROUND_WIDTH, GROUND_HEIGHT,
				groundBPos.x, groundBPos.y, GROUND_WIDTH, GROUND_HEIGHT))
			{
				GroundHitGround(i, j);
			}
		}
	}
}

void CheckIronIron()
{
	for (int i = 0; i < IRON_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_IRON)) continue;

		for (int j = i + 1; j < IRON_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_IRON)) continue;

			VECTOR ironAPos = GetElementPos(i, ELEMENT_TYPE_IRON);
			VECTOR ironBPos = GetElementPos(j, ELEMENT_TYPE_IRON);

			if (CheckSquareSquare(ironAPos.x, ironAPos.y, IRON_WIDTH, IRON_HEIGHT,
				ironBPos.x, ironBPos.y, IRON_WIDTH, IRON_HEIGHT))
			{
				IronHitIron(i,j);
			}
		}
	}
}

void CheckIronWater()
{
	for (int i = 0; i < IRON_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_IRON)) continue;

		for (int j = 0; j < WATER_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_WATER)) continue;

			VECTOR ironPos = GetElementPos(i, ELEMENT_TYPE_IRON);
			VECTOR waterPos = GetElementPos(j, ELEMENT_TYPE_WATER);

			if (CheckSquareSquare(ironPos.x, ironPos.y, IRON_WIDTH, IRON_HEIGHT,
				waterPos.x, waterPos.y, WATER_WIDTH, WATER_HEIGHT))
			{
				IronHitWater(i, j);
			}
		}
	}
}

void CheckFireIron()
{
	for (int i = 0; i < FIRE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_FIRE)) continue;

		for (int j = 0; j < IRON_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_IRON)) continue;

			VECTOR firePos = GetElementPos(i, ELEMENT_TYPE_FIRE);
			VECTOR ironPos = GetElementPos(j, ELEMENT_TYPE_IRON);

			if (CheckSquareSquare(firePos.x, firePos.y, FIRE_WIDTH, FIRE_HEIGHT,
				ironPos.x, ironPos.y, IRON_WIDTH, IRON_HEIGHT))
			{
				FireDelete(i);
			}
		}
	}
}

void CheckFireWater()
{

	for (int i = 0; i < FIRE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_FIRE)) continue;

		for (int j = 0; j < WATER_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_WATER)) continue;

			VECTOR firePos = GetElementPos(i, ELEMENT_TYPE_FIRE);
			VECTOR waterPos = GetElementPos(i, ELEMENT_TYPE_WATER);

			if (CheckSquareSquare(firePos.x, firePos.y, FIRE_WIDTH, FIRE_HEIGHT,
				waterPos.x, waterPos.y, WATER_WIDTH, WATER_HEIGHT))
			{
				FireDelete(i);
				WaterHitFire(j);
			}
		}
	}
}

void CheckFireTree()
{
	for (int i = 0; i < FIRE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_FIRE)) continue;

		for (int j = 0; j < TREE_MAX; j++)
		{
			if (!IsGimmickActive(j, GIMMICK_TYPE_TREE)) continue;

			VECTOR firePos = GetElementPos(i, ELEMENT_TYPE_FIRE);
			VECTOR treePos = GetGimmickPos(i, GIMMICK_TYPE_TREE);

			if (CheckSquareSquare(firePos.x, firePos.y, FIRE_WIDTH, FIRE_HEIGHT,
				treePos.x, treePos.y, TREE_WIDTH, TREE_HEIGHT))
			{
				FireDelete(i);
				TreeHitFire(j);
			}
		}
	}
}

void CheckFireAirBalloon()
{
	for (int i = 0; i < FIRE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_FIRE)) continue;

		for (int j = 0; j < AIRBALLOON_MAX; j++)
		{
			if (!IsGimmickActive(j, GIMMICK_TYPE_AIRBALLOON)) continue;

			VECTOR firePos = GetElementPos(i, ELEMENT_TYPE_FIRE);
			VECTOR airBalloonPos = GetGimmickPos(i, GIMMICK_TYPE_AIRBALLOON);

			if (CheckSquareSquare(firePos.x, firePos.y, FIRE_WIDTH, FIRE_HEIGHT,
				airBalloonPos.x, airBalloonPos.y, TREE_WIDTH, TREE_HEIGHT))
			{
				FireDelete(i);
				AirBalloonHitFire(j);
			}
		}
	}
}

void CheckWaterWater()
{
	for (int i = 0; i < WATER_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_WATER)) continue;

		for (int j = i + 1; j < WATER_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_WATER)) continue;

			VECTOR waterAPos = GetElementPos(i, ELEMENT_TYPE_WATER);
			VECTOR waterBPos = GetElementPos(j, ELEMENT_TYPE_WATER);

			if (CheckSquareSquare(waterAPos.x, waterAPos.y, WATER_WIDTH, WATER_HEIGHT,
				waterBPos.x, waterBPos.y, WATER_WIDTH, WATER_HEIGHT))
			{
				WaterHitWater(i, j);
			}
		}
	}
}

void CheckWaterIce()
{
	for (int i = 0; i < WATER_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_WATER)) continue;

		for (int j = 0; j < ICE_MAX; j++)
		{
			if (!IsElementActive(j, ELEMENT_TYPE_ICE)) continue;

			VECTOR waterPos = GetElementPos(i, ELEMENT_TYPE_WATER);
			VECTOR icePos = GetElementPos(j, ELEMENT_TYPE_ICE);

			float icePosX = icePos.x - ICE_WIDTH / 2;
			float icePosY = icePos.y - ICE_HEIGHT / 2;

			if (CheckSquareSquare(waterPos.x, waterPos.y, WATER_WIDTH, WATER_HEIGHT,
				icePosX, icePosY, ICE_WIDTH, ICE_HEIGHT))
			{
				WaterHitIce(i);
			}
		}
	}
}

void CheckWindWoodBlock()
{
	for (int i = 0; i < WIND_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_WIND)) continue;

		for (int j = 0; j < WOODBLOCK_MAX; j++)
		{
			if (!IsGimmickActive(j, GIMMICK_TYPE_WOODBLOCK)) continue;

			VECTOR windPos = GetElementPos(i, ELEMENT_TYPE_WIND);
			VECTOR woodBlockPos = GetGimmickPos(j, GIMMICK_TYPE_WOODBLOCK);

			if (CheckSquareSquare(windPos.x, windPos.y, WIND_WIDTH, WIND_HEIGHT,
				woodBlockPos.x, woodBlockPos.y, WOODBLOCK_WIDTH, WOODBLOCK_HEIGHT))
			{
				WindDelete(i);
				WoodBlockHitWind(i,j);
			}
		}
	}
}

void CheckWaterFireGimmick()
{
	for (int i = 0; i < WATER_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_WATER)) continue;

		for (int j = 0; j < FIREGIMMICK_MAX; j++)
		{
			if (!IsGimmickActive(j, GIMMICK_TYPE_FIRE)) continue;

			VECTOR waterPos = GetElementPos(i, ELEMENT_TYPE_WATER);
			VECTOR firePos = GetGimmickPos(j, GIMMICK_TYPE_FIRE);

			if (CheckSquareSquare(waterPos.x, waterPos.y, WATER_WIDTH, WATER_HEIGHT,
				firePos.x, firePos.y, FIREGIMMICK_WIDTH, FIREGIMMICK_HEIGHT))
			{
				FireGimmickHitWater(j);
			}
		}
	}
}

void CheckThunderBattery()
{
	for (int i = 0; i < THUNDER_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_THUNDER)) continue;

		for (int j = 0; j < BATTERY_MAX; j++)
		{
			if (!IsGimmickActive(j, GIMMICK_TYPE_BATTERY)) continue;

			VECTOR thunderPos = GetElementPos(i, ELEMENT_TYPE_THUNDER);
			VECTOR batteryPos = GetGimmickPos(j, GIMMICK_TYPE_BATTERY);

			if (CheckSquareSquare(thunderPos.x, thunderPos.y, THUNDER_WIDTH, THUNDER_HEIGHT,
				batteryPos.x, batteryPos.y, BATTERY_WIDTH, BATTERY_HEIGHT))
			{
				BatteryHitThunder(j);
			}
		}
	}
}

void CheckWindWindmill()
{
	for (int i = 0; i < WIND_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_WIND)) continue;

		for (int j = 0; j < WINDMILL_MAX; j++)
		{
			if (!IsGimmickActive(j, GIMMICK_TYPE_WINDMILL)) continue;

			VECTOR windPos = GetElementPos(i, ELEMENT_TYPE_WIND);
			VECTOR windmillPos = GetGimmickPos(j, GIMMICK_TYPE_WINDMILL);

			if (CheckSquareSquare(windPos.x, windPos.y, WIND_WIDTH, WIND_HEIGHT,
				windmillPos.x, windmillPos.y, WINDMILL_WIDTH, WINDMILL_HEIGHT))
			{
				WindmillHitWind(j);
			}
		}
	}
}

void CheckPlayerEnemyFlyCircle()
{
	PlayerData player = GetPlayer();

	if (!player.active) return;

	for (int i = 0; i < ENEMY_CIRCLE_MAX; i++)
	{
		float enemyX = GetEnemyFlyCircleX(i);
		float enemyY = GetEnemyFlyCircleY(i);

		int width = GetEnemyFlyCircleWidth(i);
		int height = GetEnemyFlyCircleHeight(i);

		if (CheckSquareSquare(
			player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
			enemyX, enemyY, width, height))
		{
			PlayerHitEnemy();
		}
	}
}

void CheckPlayerEnemyFlyCircle2()
{
	PlayerData player = GetPlayer();

	if (!player.active) return;

	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		float enemyX = GetEnemyFlyCircle2X(i);
		float enemyY = GetEnemyFlyCircle2Y(i);

		int width = GetEnemyFlyCircle2Width(i);
		int height = GetEnemyFlyCircle2Height(i);

		if (CheckSquareSquare(
			player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
			enemyX, enemyY, width, height))
		{
			PlayerHitEnemy();
		}
	}
}

void CheckPlayerEnemyTurret()
{
	PlayerData player = GetPlayer();

	if (!player.active) return;

	for (int i = 0; i < TURRET_MAX; i++)
	{
		float ex = GetEnemyTurretX(i);
		float ey = GetEnemyTurretY(i);
		int ew = GetEnemyTurretWidth(i);
		int eh = GetEnemyTurretHeight(i);

		if (CheckSquareSquare(
			player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
			ex, ey, ew, eh))
		{
			PlayerHitEnemy();
		}
	}
}

void CheckPlayerEnemyTurretBullet()
{
	PlayerData player = GetPlayer();

	if (!player.active) return;

	int max = GetEnemyTurretBulletNum();

	for (int i = 0; i < max; i++)
	{
		if (!GetEnemyTurretBulletUse(i)) continue;

		float bx = GetEnemyTurretBulletX(i);
		float by = GetEnemyTurretBulletY(i);
		int size = GetEnemyTurretBulletSize(i);

		if (CheckSquareSquare(
			player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
			bx, by, size, size))
		{
			PlayerHitEnemy();
		}
	}
}

void CheckPlayerEnemyFlyStraight()
{
	PlayerData player = GetPlayer();

	if (!player.active) return;

	for (int i = 0; i < ENEMY_STRAIGHT_MAX; i++)
	{
		float enemyX = GetEnemyFlyStraightX(i);
		float enemyY = GetEnemyFlyStraightY(i);

		int width = GetEnemyFlyStraightWidth(i);
		int height = GetEnemyFlyStraightHeight(i);

		if (CheckSquareSquare(
			player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
			enemyX, enemyY, width, height))
		{
			PlayerHitEnemy();
		}
	}
}

void CheckPlayerEnemyWalk()
{
	PlayerData player = GetPlayer();

	if (!player.active) return;

	for (int i = 0; i < ENEMY_WALK_MAX; i++)
	{
		float enemyX = GetEnemyWalkX(i);
		float enemyY = GetEnemyWalkY(i);

		int width = GetEnemyWalkWidth(i);
		int height = GetEnemyWalkHeight(i);

		if (CheckSquareSquare(
			player.posX, player.posY, PLAYER_WIDTH, PLAYER_HEIGHT,
			enemyX, enemyY, width, height))
		{
			int type = GetEnemyWalkType(i);

			// ノックバックだけ

			if (player.posX < enemyX)
			{
				// 左から当たった
				PlayerDamage();
			}
			else
			{
				// 右から当たった
				PlayerDamage();
			}

			// 踏み判定

			if (type == TYPE_STOMPABLE)
			{
				if (player.posY + PLAYER_HEIGHT <= enemyY + 10)
				{
					KillEnemyWalk(i);
				}
				else
				{
					PlayerHitEnemy();
				}
			}
			else
			{
				PlayerHitEnemy();
			}
		}
	}
}
void CheckElementEnemyWalk()
{
	// 火
	for (int i = 0; i < FIRE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_FIRE)) continue;

		VECTOR pos = GetElementPos(i, ELEMENT_TYPE_FIRE);

		for (int e = 0; e < ENEMY_WALK_MAX; e++)
		{
			float ex = GetEnemyWalkX(e);
			float ey = GetEnemyWalkY(e);

			int w = GetEnemyWalkWidth(e);
			int h = GetEnemyWalkHeight(e);

			if (CheckSquareSquare(pos.x, pos.y, FIRE_WIDTH, FIRE_HEIGHT,
				ex, ey, w, h))
			{
				if (GetEnemyWalkAttr(e) == ELEMENT_TYPE_NONE ||
					GetEnemyWalkAttr(e) == ELEMENT_TYPE_FIRE)
				{
					KillEnemyWalk(e);
					FireDelete(i);
				}
			}
		}
	}

	// 雷
	for (int i = 0; i < THUNDER_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_THUNDER)) continue;

		VECTOR pos = GetElementPos(i, ELEMENT_TYPE_THUNDER);

		for (int e = 0; e < ENEMY_WALK_MAX; e++)
		{
			float ex = GetEnemyWalkX(e);
			float ey = GetEnemyWalkY(e);

			int w = GetEnemyWalkWidth(e);
			int h = GetEnemyWalkHeight(e);

			if (CheckSquareSquare(pos.x, pos.y, THUNDER_WIDTH, THUNDER_HEIGHT,
				ex, ey, w, h))
			{
				if (GetEnemyWalkAttr(e) == ELEMENT_TYPE_NONE ||
					GetEnemyWalkAttr(e) == ELEMENT_TYPE_THUNDER)
				{
					KillEnemyWalk(e);
				}
			}
		}
	}

	// 氷
	for (int i = 0; i < ICE_MAX; i++)
	{
		if (!IsElementActive(i, ELEMENT_TYPE_ICE)) continue;

		VECTOR pos = GetElementPos(i, ELEMENT_TYPE_ICE);

		for (int e = 0; e < ENEMY_WALK_MAX; e++)
		{
			float ex = GetEnemyWalkX(e);
			float ey = GetEnemyWalkY(e);

			int w = GetEnemyWalkWidth(e);
			int h = GetEnemyWalkHeight(e);

			if (CheckSquareSquare(pos.x, pos.y, ICE_WIDTH, ICE_HEIGHT,
				ex, ey, w, h))
			{
				if (GetEnemyWalkAttr(e) == ELEMENT_TYPE_NONE ||
					GetEnemyWalkAttr(e) == ELEMENT_TYPE_ICE)
				{
					KillEnemyWalk(e);
				}
			}
		}
	}
}

void CheckCollision()
{
	CheckMapPlayerCollision();

	CheckPlayerMap();

	CheckFireMap();

	CheckIronMap();

	CheckWaterMap();

	CheckGroundMap();

	CheckGroundGround();

	CheckWoodBlockMap();

	CheckAirBalloonMap();

	CheckPlayerIron();

	CheckPlayerWater();

	CheckPlayerGround();

	CheckPlayerTree();

	CheckPlayerAirBalloon();

	CheckPlayerWoodBlock();

	CheckPlayerMoveBlock();

	CheckPlayerFireGimmick();

	CheckPlayerWarp();

	CheckPlayerGoal();

	CheckIronIron();

	CheckIronWater();

	CheckFireIron();

	CheckFireWater();

	CheckFireTree();

	CheckFireAirBalloon();

	CheckWaterWater();

	CheckWaterIce();

	CheckWindWoodBlock();

	CheckWaterFireGimmick();

	CheckThunderBattery();

	CheckWindWindmill();

	CheckPlayerEnemyFlyCircle();

	CheckPlayerEnemyFlyCircle2();
	
	CheckPlayerEnemyTurret();
	
	CheckPlayerEnemyTurretBullet();
	
	CheckPlayerEnemyFlyStraight();
	
	CheckPlayerEnemyWalk();
	
	CheckElementEnemyWalk();
}