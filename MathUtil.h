#pragma once
#include "Object.h"

class MathUtil
{
public:
	// �Ķ���ͷ� ���� �� ��ü ������ �Ÿ��� ���� ��,
	// ��ȯ�ϴ� ���� �޼���
	static float GetDistance(Object* a, Object* b)
	{
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		return distance;
	}

	// �Ķ���ͷ� ���� �� ��ü ������ ������ ���� ��, ��ȯ�ϴ� ���� �޼���
	static float GetAngle(Object* a, Object* b)
	{
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		// ��ũ�ڻ��� (�غ� / ����) -> ���� �� ��Ÿ�� ����
		float angle = acosf(distanceX / distance) * 180.f / PI;

		// ��ũ �ڻ��� ���� ���� ������ 180���� �������� �ۿ� ǥ���� �ȵ�
		if (a->GetInfo().posY > b->GetInfo().posY)
		{
			angle = 360.f - angle;
		}

		return angle;
	}

	// �Ķ���ͷ� ���� �� ��ü�� �浹�� �����ϴ� ���
	static bool OnCollision(Object* a, Object* b)
	{
		// �浹 üũ�ϰ��� �ϴ� �� ���� �������� �� ��
		// -> �� �� ������ ���� �Ÿ��� �� ���� �������� �պ���
		// �۴ٸ� �浹�ߴٰ� ó��
		// �浹������ true, �ƴ϶�� false ��ȯ

		// �浹�� �����ϰ��� �ϴ� �� ��ü ������ �Ÿ��� ���Ѵ�
		// x�� �Ÿ�
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// y�� �Ÿ�
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// ���� x, y���� �Ÿ��� �ϳ��� �����ͷ� ǥ�� (�����Ÿ��� ����)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		// �� ���� �������� ���� ���� �Ÿ����� ũ�ٸ� �浹
		if (a->GetInfo().sizeX + b->GetInfo().sizeY > distance)
			return true;

		return false;
	}

};