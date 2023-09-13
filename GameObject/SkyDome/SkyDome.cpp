#include "Skydome.h"

Skydome::Skydome() {}

Skydome::~Skydome() {}

void Skydome::Initialize() {

	modelSkydome_ = Model::CreateFromOBJ("Skydome", true);
	worldTransform_.Initialize();

	worldTransform_.scale_ = {2.0f, 2.0f, 2.0f};
}

void Skydome::Update() {

	// 更新処理
	worldTransform_.UpdateMatrix();
}

void Skydome::Draw(ViewProjection view) {
	
	// 更新処理
	worldTransform_.UpdateMatrix();
	modelSkydome_->Draw(worldTransform_, view); }
