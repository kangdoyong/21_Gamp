#pragma once
#include "Object.h"
class Obstacle :
    public Object
{
public:
	// Object을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	Obstacle();
	virtual ~Obstacle();
};

