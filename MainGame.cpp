#include "MainGame.h"
#include "Player.h"
#include "Obstacle.h"
#include "MathUtil.h"

void MainGame::Initialize()
{
	hdc = GetDC(g_hWnd);

	player = new Player();
	player->Initialize();

	obstacle = new Obstacle();
	obstacle->Initialize();

	POINTFLOAT points[4] =
	{
		{ 100, 500 }, // 0
		{ 300, 500 }, // 1
		{ 500, 300 }, // 2
		{ 700, 300 }, // 3
	};

	lineList.push_back(new LINE(points[0], points[1]));
	lineList.push_back(new LINE(points[1], points[2]));
	lineList.push_back(new LINE(points[2], points[3]));

	((Player*)player)->SetLineList(&lineList);
	((Player*)player)->SetObstacle(obstacle);
}

void MainGame::Update()
{
	player->Update();

	
}

void MainGame::Render()
{
	Rectangle(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	player->Render(hdc);
	obstacle->Render(hdc);

	// 라인 시작점 설정
	MoveToEx(hdc, lineList.front()->lPoint.x,
		lineList.front()->lPoint.y, NULL);

	// 시작점을 기준으로 라인을 이어서 그리기
	for (auto i = lineList.begin(); i != lineList.end(); ++i)
	{
		LineTo(hdc, (*i)->rPoint.x, (*i)->rPoint.y);
	}
}

void MainGame::Release()
{
	if (player)
	{
		delete player;
		player = nullptr;
	}

	if (obstacle)
	{
		delete obstacle;
		obstacle = nullptr;
	}

	for (auto i = lineList.begin(); i != lineList.end(); ++i)
	{
		if (*i)
		{
			delete* i;
			*i = nullptr;
		}
	}
	lineList.clear();

	ReleaseDC(g_hWnd, hdc);
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
