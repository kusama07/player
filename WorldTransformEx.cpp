#include "WorldTransform.h"
#include"math/MatrixTransform.h"

void WorldTransform::UpdateMatrix() {
	matWorld_ =MatrixTransform::MakeAffineMatrix(scale_, rotation_, translation_);
	if (parent_) {
		matWorld_ = MatrixTransform::Multiply(matWorld_, parent_->matWorld_);
		//matWorld_ = parent_->matWorld_;
	}
	TransferMatrix();
}