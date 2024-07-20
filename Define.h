#pragma once
#include "framework.h"

#define WIN_SIZE_X 800
#define WIN_SIZE_Y 600

#define PI 3.141592f

extern HWND g_hWnd;

// Ư�� ��ü�� �׸� ��, ��ġ�� ����� �ʿ�
// �׷� �� ������, ��ġ�� ����� ���õ� ������
// ���� �����ϱ� ���ŷο�Ƿ� ���� ���Ǵ� �����͸� ����üȭ
typedef struct tagInfo
{
	int posX;
	int posY;
	int sizeX;
	int sizeY;
}INFO;

typedef struct tagLine
{
	// ���� ��
	POINTFLOAT lPoint;
	// ������ ��
	POINTFLOAT rPoint;

	tagLine() {}
	tagLine(POINTFLOAT lp, POINTFLOAT rp)
		: lPoint(lp), rPoint(rp) {}
}LINE;