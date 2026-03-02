#include "DxLib.h"
#include "UIImage.h"

#define UI_IMAGE_MAX 32

UIImageData g_UIImageData[UI_IMAGE_MAX] = { 0 };

int g_UIImageHandle[UI_IMAGE_TYPE_MAX] = { 0 };

void InitUIImage()
{
	UIImageData* ui = g_UIImageData;
	for (int i = 0; i < UI_IMAGE_MAX; i++, ui++)
	{
		ui->active = false;
		ui->handle = 0;
		ui->posX = 0.0f;
		ui->posY = 0.0f;
	}
}

void LoadUIImage()
{
	g_UIImageHandle[UI_IMAGE_LIFE] = LoadGraph("Data/UI/Heart.png");
	g_UIImageHandle[UI_IMAGE_LIFETEXT] = LoadGraph("Data/UI/LifeText.png");
}

void StartUIImage()
{

}

void StepUIImage()
{

}

void UpdateUIImage()
{

}

void DrawUIImage()
{
	UIImageData* ui = g_UIImageData;
	for (int i = 0; i < UI_IMAGE_MAX; i++, ui++)
	{
		if (!ui->active) continue;

		DrawGraph((int)ui->posX, (int)ui->posY, ui->handle, TRUE);
	}
}

void FinUIImage()
{
	for (int i = 0; i < UI_IMAGE_TYPE_MAX; i++)
	{
		DeleteGraph(g_UIImageHandle[i]);
	}
}

void CreateUIImage(UIIMageType type, float posX, float posY)
{
	UIImageData* ui = g_UIImageData;
	for (int i = 0; i < UI_IMAGE_MAX; i++, ui++)
	{
		if (!ui->active)
		{
			ui->active = true;

			ui->handle = g_UIImageHandle[type];

			ui->posX = posX;
			ui->posY = posY;

			break;
		}
	}
}

void ResetUIImage()
{
	UIImageData* ui = g_UIImageData;
	for (int i = 0; i < UI_IMAGE_MAX; i++, ui++)
	{
		ui->active = false;
	}
}

