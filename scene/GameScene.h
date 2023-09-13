#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <list>
#include <iostream>
#include "ImGui.h"
//
#include"BOX/BoxType.h"
#include"BOX/Pulayer/Player.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	//
	/*
	void CheckAllCollisions();
*/

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;
	std::unique_ptr<Model> model_;
	std::unique_ptr<Model> playerModel_;
	std::unique_ptr<Player> player_;
	
	std::list<BoxType*> boxs_;

	int32_t tr = 0;
	WorldTransform worldTransform_;
	ViewProjection viewProjection_;

	/*AABB playerAABB;
	AABB boxAABB;
	bool isHet = false;*/
	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
