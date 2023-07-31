#include "Player.h"
#include "ImGuiManager.h"
#include "Matrix.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include <random>
#include <cassert>

void Player::Initialize(Model* model, uint32_t textureHandle) {
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;

	worldTransform_.translation_.x = 40;

	std::random_device rd;
	gen_.seed(rd());

	std::uniform_real_distribution<float> dis(0.0f, 18.0f);
	worldTransform_.translation_.y = dis(gen_);

	worldTransform_.Initialize();

	input_ = Input::GetInstance();
}

void Player::Update() {
	worldTransform_.TransferMatrix();

	Vector3 move = {0, 0, 0};

	 float kCharacterSpeed = 0.2f;

	move.x -= kCharacterSpeed;
	
	float inputFloat3[3] = {kCharacterSpeed + 1, move.y + 1, move.z + 1};

	ImGui::Begin("Player");
	ImGui::SliderFloat3("SliderFloat3", inputFloat3, 0.0f, 2.0f);
	ImGui::Text("DebugCamera ENTER");
	ImGui::End();

	kCharacterSpeed = inputFloat3[0] - 1;
	move.y = inputFloat3[1] - 1;
	move.z = inputFloat3[2] - 1;


	worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
}

void Player::Draw(ViewProjection viewProjection) 
{
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}