#include "BoxType.h"


void BoxType::Initialize(Model* model, Vector3& position, uint32_t textureHandle) {
	model_ = model;
	Box_ = textureHandle ;
	worldTransform_.Initialize();
	worldTransform_.translation_.x = 64;
	worldTransform_.translation_ = position;
	
	worldTransform_.UpdateMatrix();
}

void BoxType::Update(Vector3 move) { 
	// 移動量を保存
	movement_ = move;

	worldTransform_.UpdateMatrix();
	worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

}

void BoxType::Draw(const ViewProjection& viewProjection_) {

	model_->Draw(worldTransform_, viewProjection_, Box_); 

}

AABB BoxType::GetAABB() {
	// 箱の位置と寸法に基づいてAABBを計算
	Vector3 min = {
	    worldTransform_.translation_.x - (boxWidth_ * 0.5f),
	    worldTransform_.translation_.y - (boxHeight_ * 0.5f),
	    worldTransform_.translation_.z - (boxDepth_ * 0.5f)};
	Vector3 max = {
	    worldTransform_.translation_.x + (boxWidth_ * 0.5f),
	    worldTransform_.translation_.y + (boxHeight_ * 0.5f),
	    worldTransform_.translation_.z + (boxDepth_ * 0.5f)};

	AABB aabb;
	aabb.min = min;
	aabb.max = max;

	return aabb;
}

// BoxTypeクラスに以下の関数を追加します。
Vector3 BoxType::GetMovement() const { return movement_; }