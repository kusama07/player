#include "Enemy.h"
#include "GameScene.h"
#include "math/MatrixTransform.h"
Enemy::Enemy() {}

Enemy::~Enemy() {
	model_->~Model();
	
	for (EnemyBullet* bullet : bullets_) {
	    delete bullet;
	}
	
}

void Enemy::Initialize(Vector3 v) {

	worldTransform_.Initialize();
	worldTransform_.translation_ = v;
	worldTransform_.scale_ = {
	    5,
	    5,
	    5,
	};

	SetCollosionAttribute(kCollisionAttributeEnemy);
	SetCollisionMask(kCollisionAttributePlayer);
	SetRadious(7.0f);

	model_ = Model::CreateFromOBJ("Enemy");

}

void Enemy::Update() {

	bullets_.remove_if([](EnemyBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

	FireTimer--;
	if (FireTimer <= 0) {
		Fire();
		FireTimer = kFireInterval+std::rand()%300;
	}

    // worldTransform_.rotation_.y += 0.01f;
	for (EnemyBullet* bullet : bullets_) {
		bullet->Update();
	}

	worldTransform_.matWorld_ = MatrixTransform::MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Enemy::Draw(ViewProjection ViewProjection_) {

	model_->Draw(worldTransform_, ViewProjection_);
	for (EnemyBullet* bullet : bullets_)
	{
		bullet->Draw(ViewProjection_);
	}
}



void Enemy::OnCollision() { isDead_ = true; }

Vector3 Enemy::GetWorldPosition() {
	Vector3 worldPos;

	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];
	return worldPos;
}

Vector3 Enemy::LerpFanc(Vector3 v1, Vector3 v2) {
	Vector3 result;

	result.x = v2.x - v1.x;
	result.y = v2.y - v1.y;
	result.z = v2.z - v1.z;

	return result;
}

void Enemy::Fire() {

	Vector3 v;
	v.x = player_->GetWorldPosition().x;
	v.y = player_->GetWorldPosition().y;
	v.z = player_->GetWorldPosition().z;

	// ホーミング処理
	Vector3 PlayerPos = v;
	// player_->GetWorldPosition();
	Vector3 EnemyPos = GetWorldPosition();
	//worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};
	Vector3 PiEnLerp = LerpFanc(EnemyPos, PlayerPos);

	Vector3 PiEnNormalize = VectorTransform::Normalize(PiEnLerp);

	PiEnNormalize = VectorTransform::TransformNormal(PiEnNormalize, worldTransform_.matWorld_);
	
	


	// intealize
	EnemyBullet* newBullet = new EnemyBullet();

	newBullet->Initialize(model_, worldTransform_.translation_, PiEnNormalize);

	bullets_.push_back(newBullet);


}