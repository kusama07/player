#pragma once

#include"Matrix4x4.h"
#include"Vector3.h"
#include<cmath>
#include<cassert>

class MatrixTransform {
public:


	static Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	static Matrix4x4 Subract(const Matrix4x4& m1, const Matrix4x4& m2);

	static Matrix4x4 Multiply(Matrix4x4 m1, Matrix4x4 m2);


	static Matrix4x4 MakeScaleMatrix(const Vector3 scale);


	static Matrix4x4 MakeTranslateMatrix(Vector3 translate);

	static Matrix4x4 MakeRotateXMatrix(float radian);

	static Matrix4x4 MakeRotateYMatrix(float radian);

	static Matrix4x4 MakeRotateZMatrix(float radian);

	static Matrix4x4 MakeRotateXYZMatrix(float radianX, float radianY, float radianZ);

    static Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

	static Matrix4x4 Inverse(const Matrix4x4& m);


	static Matrix4x4 MakeViewportMatrix(
	    float left, float top, float width, float height, float minDepth, float maxDepth);


private:
};

