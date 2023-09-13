#include"PlayerBullet.h"



PlayerBullet::PlayerBullet() {
	model_ = nullptr;
	velocity_ = {0, 0, 0};
}

PlayerBullet::~PlayerBullet() {}

void PlayerBullet::Initialize(Model* model, Vector3& position, const Vector3& velocity)
{
	model;
	SetCollosionAttribute(kCollisionAttributePlayer);
	SetCollisionMask(~kCollisionAttributePlayer);

	model_ = Model::CreateFromOBJ("PlayerBullet");
	worldTransform_.Initialize();

	float velocityXZ = sqrt(velocity.x * velocity.x + velocity.z * velocity.z);

	float heightY = -velocity.y;

	worldTransform_.rotation_.y = std::atan2(velocity.x, velocity.z);

	worldTransform_.rotation_.x = std::atan2(heightY, velocityXZ);
	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransform_.translation_ = position;
	velocity_ = velocity;
	velocity_.x = velocity_.x * 1.2f;
	velocity_.y = velocity_.y * 1.2f;
	velocity_.z = velocity_.z * 1.2f;

	SetCollosionAttribute(kCollisionAttributePlayer);
	SetCollisionMask(kCollisionAttributeEnemy);
}

void PlayerBullet::Update() {
	if (--deathTimer_ <= 0) {

		isDead_ = true;
	}

	worldTransform_.translation_ = VectorTransform::Add(worldTransform_.translation_, velocity_);

	// worldTransform_.UpdateMatrix();
	worldTransform_.matWorld_ = MatrixTransform::MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection);
}

Vector3 PlayerBullet::GetWorldPosition() {
	Vector3 result;

	result.x = worldTransform_.matWorld_.m[3][0];
	result.y = worldTransform_.matWorld_.m[3][1];
	result.z = worldTransform_.matWorld_.m[3][2];

	return result;
}
void PlayerBullet::OnCollision() { isDead_ = true; }




