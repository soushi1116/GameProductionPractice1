#pragma once
#include "AnimationEffectParameter.h"

void InitAnimationEffect();
void LoadAnimationEffect();
void StepAnimationEffect();
void UpdateAnimationEffect();
void DrawAnimationEffect();
void FinAnimationEffect();

void StartAnimationEffect(AnimationEffectType type, float posX, float posY, int interval);