#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class sakura 
{
public:
	void Initialize(Model* model);

	void Update();

	void Draw(ViewProjection& viewProjection);

private:
	WorldTransform worldTransform_[20];

	Model* model_;
};
