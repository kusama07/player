#pragma once

#include "GameObject/enemy/bullet/EnemyBullet.h"
#include "GameObject/Player/Player.h"
#include <Model.h>
#include <WorldTransform.h>
#include"utility/Collider.h"
#include"utility/GameConfig.h"

class Player;

class GameScene;

class Enemy :public Collider
{
public:
	enum class Phase {
		Approach,
		Leave,
	};

	Enemy();
	~Enemy();

	void Initialize(Vector3 v);

	void Update();

	void Draw(ViewProjection ViewProjection_);

	void SetPlayer(Player* player) { player_ = player; }

	void OnCollision()override;

	Vector3 GetWorldPosition()override;

	Vector3 LerpFanc(Vector3 v1, Vector3 v2);

	const std::list<EnemyBullet*>& GetBullets() const { return bullets_; }

	void SetGameScene(GameScene* gameScene) { gameScene_ = gameScene; }

	bool IsDead() const { return isDead_; }

private:
	void Fire();

	uint32_t modeltexHandle;
	Model* model_;
	WorldTransform worldTransform_;

	static const int kFireInterval = 60;
	int32_t FireTimer = 90;
	std::list<EnemyBullet*> bullets_;
	
	Player* player_ = nullptr;
	GameScene* gameScene_ = nullptr;

	bool isDead_ = false;
};