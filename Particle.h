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

	void Finalize();

	float RandomSpeed();

	float RandomRotateSpeed();

	float RandomRotateSpeed2();

private:
	WorldTransform worldTransform_[150];

	Model* model_;

	Vector3 particleSpeed_[150];
	Vector2 particleRotate_[150];

	bool isAlive[150];
	int particleTimer = 150;

	const int maxParticle = 150;
};
