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
	worldTransform_.UpdateMatrix();
	worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

}

void BoxType::Draw(const ViewProjection& viewProjection_) {

	model_->Draw(worldTransform_, viewProjection_, Box_); 

}

AABB BoxType::GetAABB() {
	// プレイヤーのAABBの最小座標と最大座標を計算
	Vector3 min = {
	    worldTransform_.translation_.x - boxWidth_ / 2,
	    worldTransform_.translation_.y - boxHeight_ / 2,
	    worldTransform_.translation_.z - boxDepth_ / 2};
	Vector3 max = {						 
	    worldTransform_.translation_.x + boxWidth_ / 2,
	    worldTransform_.translation_.y + boxHeight_ / 2,
	    worldTransform_.translation_.z + boxDepth_ / 2};

	// 計算した最小座標と最大座標からAABBを構築
	AABB aabb;
	aabb.min = min;
	aabb.max = max;

	return aabb;
}