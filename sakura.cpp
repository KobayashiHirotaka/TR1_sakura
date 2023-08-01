#include "sakura.h"
#include <cassert>

void sakura::Initialize(Model* model) {
	assert(model);
	model_ = model;

	worldTransform_[0].Initialize();
	worldTransform_[0].translation_.x = 40;
	worldTransform_[0].translation_.y = static_cast<float>(rand() % 70 - 35);
	worldTransform_[0].translation_.z = 40;

	worldTransform_[1].Initialize();
	worldTransform_[1].translation_.x = 40;
	worldTransform_[1].translation_.z = -28;
}

void sakura::Update() 
{ 
	worldTransform_[0].translation_.x -= 0.01f;
	worldTransform_[0].translation_.y -= 0.01f;
	worldTransform_[0].rotation_.x += 0.03f;
	/*worldTransform_[0].rotation_.y += 0.03f;*/
	worldTransform_[0].UpdateMatrix(); 

	worldTransform_[1].translation_.x -= 0.08f;
	worldTransform_[1].rotation_.x += 0.03f;
	worldTransform_[1].rotation_.y += 0.03f;
	worldTransform_[1].UpdateMatrix(); 
}

void sakura::Draw(ViewProjection& viewProjection) {
	model_->Draw(worldTransform_[0], viewProjection);

	model_->Draw(worldTransform_[1], viewProjection);
}