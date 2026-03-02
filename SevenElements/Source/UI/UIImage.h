#pragma once

enum UIIMageType
{
	UI_IMAGE_LIFETEXT,
	UI_IMAGE_LIFE,

	UI_IMAGE_TYPE_MAX,
};

struct UIImageData
{
	bool active;
	int handle;
	float posX;
	float posY;
};

void InitUIImage();
void LoadUIImage();
void StartUIImage();
void StepUIImage();
void UpdateUIImage();
void DrawUIImage();
void FinUIImage();

void CreateUIImage(UIIMageType type, float posX, float posY);

void ResetUIImage();