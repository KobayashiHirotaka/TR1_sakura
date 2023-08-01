#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class sakura 
{
public:
	void Initialize(Model* model);

	void Update();

	void Draw(ViewProjection& viewProjection);

	float RandomTX();

	float RandomTY();

	float RandomTZ();

	float RandomSpeedX();

	float RandomSpeedY();

	float RandomRotate();

private:
	WorldTransform worldTransform_[150];

	Model* model_;

	const int MaxSakura = 150;

	float SpeedX[150];
	float SpeedY[150];
	float RotateX[150];
	float RotateY[150];
	int isAlive[150];
	int timer[150];
};
