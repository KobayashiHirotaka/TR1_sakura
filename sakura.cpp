#include "sakura.h"
#include <cassert>
#include <cstdlib> 

void sakura::Initialize(Model* model) {
	assert(model);
	model_ = model;

	for (int i = 0; i < MaxSakura; i++)
	{
		worldTransform_[i].Initialize();
		worldTransform_[i].translation_.x = RandomTX();
		worldTransform_[i].translation_.y = RandomTY();
		worldTransform_[i].translation_.z = RandomTZ();
	}

}

void sakura::Update() 
{ 

	for (int i = 0; i < MaxSakura; i++)
	{
		worldTransform_[i].translation_.x -= RandomSpeed();
		worldTransform_[i].rotation_.x += RandomRotate();
		worldTransform_[i].rotation_.y += RandomRotate();
		worldTransform_[i].UpdateMatrix(); 
	}
}

void sakura::Draw(ViewProjection& viewProjection) 
{
	for (int i = 0; i < MaxSakura; i++)
	{
		model_->Draw(worldTransform_[i], viewProjection);
	}
}

float sakura::RandomTX()
{
	float minY = 40.0f;
	float maxY = 120.0f;


}

float sakura::RandomTY() 
{
	float minY = -35.0f;
	float maxY = 35.0f;

	return minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));
}

float sakura::RandomTZ() 
{
	float minY = -28.0f;
	float maxY = 40.0f;

	return minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));
}

float sakura::RandomSpeed() {
	float minY = 0.01f;
	float maxY = 0.08f;

	return minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));
}

float sakura::RandomRotate() {
	float minY = 0.01f;
	float maxY = 0.05f;

	return minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));
}