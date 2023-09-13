#pragma once

#include"GameObject/Player/Player.h"
#include "3d/Model.h"
#include"WorldTransform.h"
#include"ViewProjection.h"
#include"Input.h"
#include"MatrixTransform.h"
#include"VectorTransform.h"

#include<Xinput.h>
#include"Sprite.h"
#include"WinApp.h"
#include"GameObject/Player/Bullet/PlayerBullet.h"
#include"utility/CollisionConfig.h"
#include"utility/Collider.h"
#include"utility/GameConfig.h"
#include"ImGuiManager.h"
#include"Audio.h"

class Player : public Collider
{
public:

	Player();
	~Player();

	void Initialize();

	void Update(ViewProjection view);

	void Draw(ViewProjection view);

	void ReticleUpdate(ViewProjection view);

	void ReticleDraw();

	void SetParent(const WorldTransform* parent) { worldTransform_.parent_ = parent; }

	Vector3 Getvelocity() {return velocity_;}

	Vector3 GetWorldPosition() override;

	void OnCollision() override;
	
	const std::list<PlayerBullet*>& GetBullets() const { return bullets_; }

	GAMEMODE GetMode() { return game; }

	void Reset();


private:

    void Move();

	void Attak(Vector3 position);


	WorldTransform worldTransform_ = {};
	Vector3 velocity_ = {};
	Model* model_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	int32_t shotSound = {};
	XINPUT_STATE joystate = {};


	Sprite* sprite_ = nullptr;
	Vector2 anchor_ = {0.5f, 0.5f};
	Vector4 color_ = {1, 1, 1, 1};
	Vector2 SpritePos_ = {640, 360};
	WorldTransform worldTransform3DReticle_ = {};

	std::list<PlayerBullet*> bullets_;
	int bulletCoolTimer = 0;

	int HitInvincibeTime = 0;
	;
	int HPCount = 2;

	GAMEMODE game = PLAY;

	int32_t ClearRequirementTex = {};
	Sprite* ClearRequirement = nullptr;

	int32_t HP_BarTex = {};
	Sprite* HP_Bar[2] = {nullptr};

	int32_t HPTex = {};
	Sprite* HP = nullptr;

	

};



