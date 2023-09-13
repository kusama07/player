#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"BOX/math/math.h"
#include "Input.h"

class GameScene;

class BoxType {
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, Vector3& position, uint32_t textureHandle);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(Vector3 move);

	/// <summary>
	/// 画像
	/// </summary>
	void Draw(const ViewProjection& viewProjection_);

	AABB GetAABB();

private:
	
	uint32_t Box_ = 0;
	Model* model_ = nullptr;
	WorldTransform worldTransform_;
	XINPUT_STATE joyState;

	float boxWidth_ = 2.0f;
	float boxHeight_ = 2.0f;
	float boxDepth_ = 2.0f;
};
