#pragma once
#include"Model.h"
#include"WorldTransform.h"
#include"MatrixTransform.h"
#include"VectorTransform.h"
#include "utility/Collider.h"
#include"utility/CollisionConfig.h"

class PlayerBullet : public Collider
{
public:
	PlayerBullet();
	~PlayerBullet();


	void Initialize(Model* model, Vector3& position, const Vector3& velocity);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	static const int32_t kLifeTime = 60 * 5;

	Vector3 GetWorldPosition() override;

	void OnCollision() override;


	/// Getter
	bool IsDead() const { return isDead_; }

	WorldTransform GetWorldTransform() { return worldTransform_; }


private:

	uint32_t modeltexHandle;
	Model* model_;
	WorldTransform worldTransform_;

	Vector3 velocity_;

	int32_t deathTimer_ = kLifeTime;
	bool isDead_ = false;


};
