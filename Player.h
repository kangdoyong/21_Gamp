#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	bool isJump; // ���� ���� ��������
	float time; // ���� ��, ���ӵ� ǥ���� ���� ���
	// �̵� �ӷ�
	float speed;
	// ���ΰ��� ��ü�� �ִ� ��ֹ� ��ü�� �ּҸ� ���� �ʵ�
	Object* obstacle;
	// ���ΰ��� ��ü�� �ִ� ���θ���Ʈ�� �ּҸ� ���� �ʵ�
	list<LINE*>* lineList;

private:
	void CheckKey(); // Ű �Է� üũ
	void Jump();     // ���� ���
	void BoxColl();  // �ڽ� �浹 üũ
	void LineColl(); // ���� �浹 üũ

public:
	// Object��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	void SetObstacle(Object* obstacle) { this->obstacle = obstacle; }
	void SetLineList(list<LINE*>* lineList)
	{
		this->lineList = lineList;
	}

	Player();
	virtual ~Player();
};


