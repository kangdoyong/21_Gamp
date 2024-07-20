#include "Player.h"
#include "AbstractFactory.h"

void Player::CheckKey()
{
	if (GetAsyncKeyState(VK_LEFT))
		info.posX -= speed;

	if (GetAsyncKeyState(VK_RIGHT))
		info.posX += speed;

	if (GetAsyncKeyState(VK_SPACE) && !isJump)
	{
		isJump = true;
		time = 0;
	} 
}

void Player::Jump()
{
	// 점프 상태가 아니라면 리턴
	if (!isJump)
		return;

	time += 0.1f;
	// 방향 * 최대 높이 + 중력가속도
	//info.posY += -sinf(90.f * PI / 180.f) * 6.f + (0.98f * time * time * 0.5f);
	info.posY += -6.f + (0.98f * time * time * 0.5f);
}

void Player::BoxColl()
{
	// 사각형 영역끼리 충돌 시, 겹치는 부분에 대한 정보를 받을 수 있는 메서드
	// -> IntersectRect()

	// 플레이어와 장애물의 사각형 영역에 대한 정보를 가져옴
	RECT playerRC = GetRect();
	RECT obstacleRC = obstacle->GetRect();
	// 겹치는 부분에 대한 정보를 받을 RECT 선언
	RECT collRC;

	// 충돌했다면
	if (IntersectRect(&collRC, &playerRC, &obstacleRC))
	{
		// 겹친 부분에 대한 정보 중, 위치는 제거하고 크기만 남김
		SetRect(&collRC, 0, 0, collRC.right - collRC.left, collRC.bottom - collRC.top);

		// 조건식을 통해 어느 방향에서 플레이어가 부딪혔는지 확인
		auto sizeX = collRC.right;
		auto sizeY = collRC.bottom;

		// 겹친 부분의 너비가 겹친 부분의 높이보다 작다면
		if (sizeX < sizeY) // 양 옆에서 부딪힐 경우
		{
			// 겹친 너비만큼 빼거나 더함
			info.posX += sizeX * (info.posX < obstacle->GetInfo().posX ? -1 : 1);
		} 
		else // 위 아래에서 부딪힐 경우
		{
			// 겹친 높이만큼 빼거나 더함
			info.posY += sizeY * (info.posY > obstacle->GetInfo().posY ? 1 : -1);
		}
	}
}

void Player::LineColl()
{
	// 플레이어가 복수의 라인 중, 어느 라인에 있는지 확인

	// 현재 플레이어가 있는 라인 객체를 담아둘 변수
	LINE* currentLine = nullptr;

	for (auto i = lineList->begin(); i != lineList->end(); ++i)
	{
		// 플레이어와 라인의 x 좌표를 통해, 현재 라인을 확인
		if (info.posX >= (*i)->lPoint.x &&
			info.posX <= (*i)->rPoint.x)
		{
			// 현재 라인을 갱신
			currentLine = *i;
			break;
		}
	}

	// 현재 라인이 없다면 리턴
	if (currentLine == nullptr)
	{
		if (!isJump)
		{
			time += 0.1f;
			info.posY += 0.98f * time * time * .5f;
		}

		return;
	}

	// 현재 라인의 너비와 높이를 구함
	float width = currentLine->rPoint.x - currentLine->lPoint.x;
	float height = currentLine->rPoint.y - currentLine->lPoint.y;

	// 새로운 y 지점 =
	// 높이와 너비 비율 * (현재 라인의 시작점을 기준으로한 플레이어의 x 위치) + (라인 초기 위치 y)
	float y = (height / width) * (info.posX - currentLine->lPoint.x) + currentLine->lPoint.y;
	y -= info.sizeY;

	// 점프 상태가 아닐 때만 플레이어 y 위치 보정
	if (!isJump)
	{
		info.posY = y;
	}

	// 플레이어가 점프 후, 라인에 닿았을 때 위에 구한 보정된 y 값으로
	// y값 덮어쓰고 점프 종료
	if (info.posY >= y)
	{
		time = 0;
		isJump = false;
		info.posY = y;
	}
}

void Player::Initialize()
{
	info.posX = 100;
	info.posY = 500;

	speed = 10;

	info.sizeX = 25;
	info.sizeY = 25;

	isJump = false;
	time = 0;
}

void Player::Update()
{
	CheckKey();
	Jump();
	BoxColl();
	LineColl();
}

void Player::Render(HDC hdc)
{
	Ellipse(hdc, info.posX - info.sizeX, 
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);
}

void Player::Release()
{
}

Player::Player()
{
}

Player::~Player()
{
}
