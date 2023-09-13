#include"BOX/math/math.h"
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>

Vector3 Multiply(const float& v1, const Vector3& v2) {
	Vector3 result{};

	result.x = v1 * v2.x;
	result.y = v1 * v2.y;
	result.z = v1 * v2.z;

	return result;
}

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float Term = 0;
			for (int k = 0; k < 4; k++) {

				Term = Term + m1.m[i][k] * m2.m[k][j];
				result.m[i][j] = Term;
			}
		}
	}

	return result;
}
// X軸の回転
Matrix4x4 MakeRotataXMatrix(float radian) {
	Matrix4x4 result{};

	result.m[0][0] = 1;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = std::sin(radian);
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = -(std::sin(radian));
	result.m[2][2] = std::cos(radian);
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}

// Y軸の回転

Matrix4x4 MakeRotataYMatrix(float radian) {
	Matrix4x4 result{};

	result.m[0][0] = std::cos(radian);
	result.m[0][1] = 0;
	result.m[0][2] = -(std::sin(radian));
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 1;
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = std::sin(radian);
	result.m[2][1] = 0;
	result.m[2][2] = std::cos(radian);
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;
	return result;
}

// Z軸の回転

Matrix4x4 MakeRotataZMatrix(float radian) {
	Matrix4x4 result{};
	result.m[0][0] = std::cos(radian);
	result.m[0][1] = std::sin(radian);
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = -(std::sin(radian));
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1;
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result{};
	Matrix4x4 RotateX{};
	Matrix4x4 RotateY{};
	Matrix4x4 RotateZ{};
	Matrix4x4 RotateXYZ{};
	RotateX = MakeRotataXMatrix(rotate.x);
	RotateY = MakeRotataYMatrix(rotate.y);
	RotateZ = MakeRotataZMatrix(rotate.z);
	RotateXYZ = Multiply(RotateX, Multiply(RotateY, RotateZ));

	result.m[0][0] = scale.x * RotateXYZ.m[0][0];
	result.m[0][1] = scale.x * RotateXYZ.m[0][1];
	result.m[0][2] = scale.x * RotateXYZ.m[0][2];
	result.m[0][3] = 0;

	result.m[1][0] = scale.y * RotateXYZ.m[1][0];
	result.m[1][1] = scale.y * RotateXYZ.m[1][1];
	result.m[1][2] = scale.y * RotateXYZ.m[1][2];
	result.m[1][3] = 0;

	result.m[2][0] = scale.z * RotateXYZ.m[2][0];
	result.m[2][1] = scale.z * RotateXYZ.m[2][1];
	result.m[2][2] = scale.z * RotateXYZ.m[2][2];
	result.m[2][3] = 0;

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1;

	return result;
}

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result{};
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

Vector3 Normalize(const Vector3& v) {
	Vector3 result{};

	float date = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	if (date != 0) {
		result.x = v.x / date;
		result.y = v.y / date;
		result.z = v.z / date;
	}
	return result;
}

bool IsCollision(const AABB& aabb1, const AABB& aabb2) {
	// AABBがX軸、Y軸、Z軸に沿って重なっている
	return (aabb1.min.x <= aabb2.max.x && aabb1.max.x >= aabb2.min.x) &&
	       (aabb1.min.y <= aabb2.max.y && aabb1.max.y >= aabb2.min.y) &&
	       (aabb1.min.z <= aabb2.max.z && aabb1.max.z >= aabb2.min.z);
}