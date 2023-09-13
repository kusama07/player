#pragma once
#include"model.h"



class SpaceBack {
public:
	SpaceBack();
	~SpaceBack();

	void Initialize();

	void Update();

	void Draw(ViewProjection view);

private:
	WorldTransform worldTransform_;
	Model* modelSkydome_ = nullptr;
};
