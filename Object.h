#pragma once
#include "Define.h"

// ��� �ΰ��� ���͵��� ���̽��� �߻� Ŭ����
class Object abstract
{
protected:
	INFO info;

public:
	INFO GetInfo() { return info; }
	void SetPos(int x, int y) { info.posX = x; info.posY = y; }
	RECT GetRect();

public:
	virtual void Initialize() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
	virtual void Release() abstract;

	Object();
	virtual ~Object();
};

