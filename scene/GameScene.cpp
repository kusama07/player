#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() { 
	for (BoxType* box : boxs_) {
		delete box;
	}

}

void GameScene::Initialize() {
	
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	
	
	model_.reset(Model::Create());
	worldTransform_.Initialize();
	viewProjection_.Initialize();
	
	playerModel_.reset(Model::CreateFromOBJ("player", true));

	// プレイヤー
	player_ = std::make_unique<Player>();
	player_->Initialize(playerModel_.get());
}

void GameScene::Update() {

	player_->Update();
	//CheckAllCollisions();

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	player_->Draw(viewProjection_);
		
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
//
//void GameScene::CheckAllCollisions() {
//
//	// プレイヤーのAABBを取得
//	playerAABB = player_->GetAABB();
//
//	for (BoxType* box : boxs_) {
//
//		// 箱のAABBを取得
//		boxAABB = box->GetAABB();
//
//		// プレイヤーと箱のAABBが重なっているかチェック
//		if (IsCollision(playerAABB, boxAABB)) {
//			// 重なっている場合の処理をここに追加
//			player_->SetVelocity(Vector3(0.0f, 0.0f, 0.0f));
//			player_->AdjustPositionOnBox(boxAABB.max.y + player_->GetPlayerHeight() / 2.0f);
//		}
//	}
//
//}