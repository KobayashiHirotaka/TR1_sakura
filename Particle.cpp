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

			worldTransform_[i].translation_ = {0.0f, 0.0f, 0.0f};

			particleSpeed_[i].x = RandomSpeed();
			particleSpeed_[i].y = RandomSpeed();
			particleSpeed_[i].z = RandomSpeed();

			particleRotate_[i].x = RandomRotateSpeed();
			particleRotate_[i].y = RandomRotateSpeed();
		}
	}

	for (int i = 0; i < maxParticle; i++)
	{
		if (isAlive[i] == 1)
		{
			particleTimer--;
			worldTransform_[i].translation_.x -= particleSpeed_[i].x;
			worldTransform_[i].translation_.y += particleSpeed_[i].y;
			worldTransform_[i].translation_.z += particleSpeed_[i].z;
			worldTransform_[i].rotation_.x += particleRotate_[i].x;
			worldTransform_[i].rotation_.y += particleRotate_[i].y;
			worldTransform_[i].UpdateMatrix(); 

			if (particleTimer < 0)
			{
				isAlive[i] = 0;
				particleTimer = 150;
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

void Particle::Finalize()
{

}

float Particle::RandomSpeed() 
{
	float min = -0.3f;
	float max = 0.3f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomRotateSpeed()
{
	float min = 0.01f;
	float max = 0.1f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}