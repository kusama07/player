#pragma once
#include"utility/Collider.h"
#include "Vector3.h"
#include <list>
#include"Audio.h"

class CollisionManager {
public:
	void CheckAllCollision();

	void ClliderPush(Collider* collider) { colliders_.push_back(collider); }

	void ClliderClear() { colliders_.clear(); }

private:
	void CheckCollisionPair(Collider* cA, Collider* cB);

	bool CheckBallCollosion(Vector3 v1, float v1Radious, Vector3 v2, float v2Radious);

	std::list<Collider*> colliders_;
};