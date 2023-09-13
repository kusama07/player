#include "EnemyBullet.h"

EnemyBullet::EnemyBullet() {}

EnemyBullet::~EnemyBullet() {}

void EnemyBullet::Initialize(Model* model, Vector3& position, const Vector3& velocity) {

	model_ = Model::CreateFromOBJ("PlayerBullet");
		model;
	worldTransform_.Initialize();
	    worldTransform_.translation_ = position;
	
	float velocityXZ = sqrt(velocity.x * velocity.x + velocity.z * velocity.z);
	float heightY = -velocity.y;
	worldTransform_.rotation_.y = std::atan2(velocity.x, velocity.z);
	worldTransform_.rotation_.x = std::atan2(heightY, velocityXZ);
	
	
	Velocity_ = velocity;
	Velocity_.x = Velocity_.x * 0.5f;
	Velocity_.y = Velocity_.y * 0.5f;
	Velocity_.z = Velocity_.z * 0.5f;

	BulletDrawFlag = true;

	SetCollosionAttribute(kCollisionAttributeEnemy);
	SetCollisionMask(kCollisionAttributePlayer);
}

void EnemyBullet::Update() {

	worldTransform_.translation_ = VectorTransform::Add(worldTransform_.translation_, Velocity_);

	if (--deathTimer_ <= 0) {

		isDead_ = true;
	}

	worldTransform_.UpdateMatrix();
}

void EnemyBullet::Draw(const ViewProjection& viewProjection) {

	if (BulletDrawFlag) {

		model_->Draw(worldTransform_, viewProjection);
	}
}

void EnemyBullet::OnCollision() { isDead_ = true; }

Vector3 EnemyBullet::GetWorldPosition() {

	Vector3 result;

	result.x = worldTransform_.matWorld_.m[3][0];
	result.y = worldTransform_.matWorld_.m[3][1];
	result.z = worldTransform_.matWorld_.m[3][2];

	return result;
}
