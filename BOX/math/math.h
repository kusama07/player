#pragma once
#include <Matrix4x4.h>
#include <Vector3.h>
Vector3 Add(const Vector3& v1, const Vector3& v2);

Vector3 Multiply(const float& v1, const Vector3& v2);
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 MakeRotataXMatrix(float radian);
Matrix4x4 MakeRotataYMatrix(float radian);
Matrix4x4 MakeRotataZMatrix(float radian);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Vector3 Normalize(const Vector3& v);

struct AABB{
	Vector3 min;
	Vector3 max;
};

bool IsCollision(const AABB& aabb1, const AABB& aabb2);
