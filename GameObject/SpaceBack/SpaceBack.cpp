#include "SpaceBack.h"

SpaceBack::SpaceBack() {}

SpaceBack::~SpaceBack() {}

void SpaceBack::Initialize()
{
	modelSkydome_ = Model::CreateFromOBJ("SpaceBack", true);
	worldTransform_.Initialize();

	worldTransform_.scale_ = {0.5f, 0.5f, 1.0f};

}

void SpaceBack::Update() {}

void SpaceBack::Draw(ViewProjection view) {
	worldTransform_.UpdateMatrix();
 modelSkydome_->Draw(worldTransform_, view);

}
