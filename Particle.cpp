#include "Particle.h"
#include "ImGuiManager.h"
#include <cassert>
#include <cstdlib> 

void Particle::Initialize(Model* model)
{
	assert(model);
	model_ = model;
}

void Particle::Update() 
{ 
	for (int i = 0; i < maxParticle; i++)
	{
		if (isAlive[i] == 0)
		{
			isAlive[i] = 1;

			worldTransform_[i].Initialize();
			worldTransform_[i].translation_.x = RandomTX();
			worldTransform_[i].translation_.y = RandomTY();
			worldTransform_[i].translation_.z = RandomTZ();

			particleSpeed_[i].x = RandomSpeedX();
			particleSpeed_[i].y = RandomSpeedY();

			particleRotate_[i].x = RandomRotateSpeed();
			particleRotate_[i].y = RandomRotateSpeed();
		}
	}

	for (int i = 0; i < maxParticle; i++)
	{
		if (isAlive[i] == 1)
		{
			worldTransform_[i].translation_.x -= particleSpeed_[i].x;
			worldTransform_[i].translation_.y += particleSpeed_[i].y;
			worldTransform_[i].rotation_.x += particleRotate_[i].x;
			worldTransform_[i].rotation_.y += particleRotate_[i].y;
			worldTransform_[i].UpdateMatrix(); 

			if (worldTransform_[i].translation_.x < -30)
			{
				isAlive[i] = 0;
			}
		}
	}
}

void Particle::Draw(ViewProjection& viewProjection)
{
	for (int i = 0; i < maxParticle; i++)
	{
		if (isAlive[i] == 1)
		{
			model_->Draw(worldTransform_[i], viewProjection);
		}
	}
}

float Particle::RandomTX()
{
	float min = 40.0f;
	float max = 120.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomTY() 
{
	float min = -35.0f;
	float max = 35.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomTZ()
{
	float min = -28.0f;
	float max = 40.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomSpeedX() 
{
	float min = 0.04f;
	float max = 0.09f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomSpeedY() 
{
	float min = -0.01f;
	float max = 0.01f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomRotateSpeed()
{
	float min = 0.01f;
	float max = 0.1f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}