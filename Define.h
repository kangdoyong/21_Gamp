#pragma once
#include "framework.h"

#define WIN_SIZE_X 800
#define WIN_SIZE_Y 600

#define PI 3.141592f

extern HWND g_hWnd;

// 특정 객체를 그릴 때, 위치와 사이즈가 필요
// 그럼 그 때마다, 위치와 사이즈에 관련된 변수를
// 새로 선언하기 번거로우므로 자주 사용되는 데이터를 구조체화
typedef struct tagInfo
{
	int posX;
	int posY;
	int sizeX;
	int sizeY;
}INFO;

typedef struct tagLine
{
	// 왼쪽 점
	POINTFLOAT lPoint;
	// 오른쪽 점
	POINTFLOAT rPoint;

	tagLine() {}
	tagLine(POINTFLOAT lp, POINTFLOAT rp)
		: lPoint(lp), rPoint(rp) {}
}LINE;