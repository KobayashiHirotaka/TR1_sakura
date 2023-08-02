#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Particle
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

	Vector2 particleSpeed_[150];
	Vector2 particleRotate_[150];

	bool isAlive[150];

	const int maxParticle = 150;
};