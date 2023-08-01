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

	float RandomSpeed();

	float RandomRotate();

private:
	WorldTransform worldTransform_[100];

	Model* model_;

	const int MaxSakura = 100;
};
