#include "sakura.h"
#include <cassert>

void sakura::Initialize(Model* model) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_.z = 40;
	worldTransform_.rotation_.y = 100;
}

void sakura::Update() 
{ 
	/*worldTransform_.translation_.x += 0.03f;*/
	worldTransform_.rotation_.x += 0.03f;
	worldTransform_.rotation_.y += 0.03f;
	worldTransform_.UpdateMatrix(); 
}

void sakura::Draw(ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}