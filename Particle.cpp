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

	const float centerX = 0.0f;
	const float centerY = 0.0f; 

	for (int i = 0; i < maxParticle; i++)
	{
		if (isAlive[i] == 0)
		{
			isAlive[i] = 1;

			worldTransform_[i].Initialize();

			float radius = RandomRotateSpeed2();                                            
			float angle = static_cast<float>(i) / maxParticle * 2.0f * 3.14f; 
			float x = radius * cos(angle);
			float y = radius * sin(angle);

			worldTransform_[i].translation_ = {x, y, 0.0f};

			particleSpeed_[i].x = RandomSpeed();
			particleSpeed_[i].y = RandomSpeed();
			particleSpeed_[i].z = RandomSpeed();

			particleRotate_[i].x = RandomRotateSpeed();
			particleRotate_[i].y = RandomRotateSpeed();

			worldTransform_[i].UpdateMatrix();
		}
	}

	for (int i = 0; i < maxParticle; i++)
	{
		if (isAlive[i] == 1)
		{
			particleTimer--;
			
		
			float speed = 0.1f; 

		
			float deltaX = centerX - worldTransform_[i].translation_.x;
			float deltaY = centerY - worldTransform_[i].translation_.y;

			float length = sqrt(deltaX * deltaX + deltaY * deltaY);
			if (length > 0) {
				deltaX /= length;
				deltaY /= length;

				worldTransform_[i].translation_.x += deltaX * speed;
				worldTransform_[i].translation_.y += deltaY * speed;
			}

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
	float min = 0.3f;
	float max = 0.6f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomRotateSpeed()
{
	float min = 0.01f;
	float max = 0.1f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float Particle::RandomRotateSpeed2() {
	float min = 8.0f;
	float max = 15.0f;

	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}