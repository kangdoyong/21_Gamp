#pragma once
#include "Object.h"
class Obstacle :
    public Object
{
public:
	// Object��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	Obstacle();
	virtual ~Obstacle();
};

