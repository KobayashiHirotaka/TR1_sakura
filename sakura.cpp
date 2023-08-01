#include "sakura.h"
#include "ImGuiManager.h"
#include <cassert>
#include <cstdlib> 

void sakura::Initialize(Model* model)
{
	assert(model);
	model_ = model;
}

void sakura::Update() 
{ 
	for (int i = 0; i < MaxSakura; i++)
	{
		if (isAlive[i] == 0) {
			isAlive[i] = 1;
			worldTransform_[i].translation_.x = RandomTX();
			worldTransform_[i].translation_.y = RandomTY();
			worldTransform_[i].translation_.z = RandomTZ();

			SpeedX[i] = RandomSpeedX();
			SpeedY[i] = RandomSpeedY();

			RotateX[i] = RandomRotate();
			RotateY[i] = RandomRotate();

			worldTransform_[i].Initialize();
		}
	}

	for (int i = 0; i < MaxSakura; i++)
	{
		if (isAlive[i] == 1)
		{
			worldTransform_[i].translation_.x -= SpeedX[i];
			worldTransform_[i].translation_.y += SpeedY[i];
			worldTransform_[i].rotation_.x += RotateX[i];
			worldTransform_[i].rotation_.y += RotateY[i];
			worldTransform_[i].UpdateMatrix(); 

			if (worldTransform_[i].translation_.x < -30)
			{
				timer[i]+=1;

				if (timer[i] >= 250)
				{
					isAlive[i] = 0;
				}
			}
		}
	}
}

void sakura::Draw(ViewProjection& viewProjection) 
{
	for (int i = 0; i < MaxSakura; i++)
	{
		if (isAlive[i] == 1)
		{
			model_->Draw(worldTransform_[i], viewProjection);
		}
	}
}

float sakura::RandomTX()
{
	float min = 40.0f;
	float max = 120.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float sakura::RandomTY() 
{
	float min = -35.0f;
	float max = 35.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float sakura::RandomTZ() 
{
	float min = -28.0f;
	float max = 40.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float sakura::RandomSpeedX() {
	float min = 0.04f;
	float max = 0.09f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float sakura::RandomSpeedY()
{
	float min = -0.01f;
	float max = 0.01f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float sakura::RandomRotate() 
{
	float min = 0.01f;
	float max = 0.1f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}