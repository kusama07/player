#include"BOX/math/math.h"
#include <ImGuiManager.h>
#include <WorldTransform.h>
#include <cassert>
void WorldTransform::UpdateMatrix() {
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	TransferMatrix();
}