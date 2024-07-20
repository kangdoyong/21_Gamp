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
	// ���� ���°� �ƴ϶�� ����
	if (!isJump)
		return;

	time += 0.1f;
	// ���� * �ִ� ���� + �߷°��ӵ�
	//info.posY += -sinf(90.f * PI / 180.f) * 6.f + (0.98f * time * time * 0.5f);
	info.posY += -6.f + (0.98f * time * time * 0.5f);
}

void Player::BoxColl()
{
	// �簢�� �������� �浹 ��, ��ġ�� �κп� ���� ������ ���� �� �ִ� �޼���
	// -> IntersectRect()

	// �÷��̾�� ��ֹ��� �簢�� ������ ���� ������ ������
	RECT playerRC = GetRect();
	RECT obstacleRC = obstacle->GetRect();
	// ��ġ�� �κп� ���� ������ ���� RECT ����
	RECT collRC;

	// �浹�ߴٸ�
	if (IntersectRect(&collRC, &playerRC, &obstacleRC))
	{
		// ��ģ �κп� ���� ���� ��, ��ġ�� �����ϰ� ũ�⸸ ����
		SetRect(&collRC, 0, 0, collRC.right - collRC.left, collRC.bottom - collRC.top);

		// ���ǽ��� ���� ��� ���⿡�� �÷��̾ �ε������� Ȯ��
		auto sizeX = collRC.right;
		auto sizeY = collRC.bottom;

		// ��ģ �κ��� �ʺ� ��ģ �κ��� ���̺��� �۴ٸ�
		if (sizeX < sizeY) // �� ������ �ε��� ���
		{
			// ��ģ �ʺ�ŭ ���ų� ����
			info.posX += sizeX * (info.posX < obstacle->GetInfo().posX ? -1 : 1);
		} 
		else // �� �Ʒ����� �ε��� ���
		{
			// ��ģ ���̸�ŭ ���ų� ����
			info.posY += sizeY * (info.posY > obstacle->GetInfo().posY ? 1 : -1);
		}
	}
}

void Player::LineColl()
{
	// �÷��̾ ������ ���� ��, ��� ���ο� �ִ��� Ȯ��

	// ���� �÷��̾ �ִ� ���� ��ü�� ��Ƶ� ����
	LINE* currentLine = nullptr;

	for (auto i = lineList->begin(); i != lineList->end(); ++i)
	{
		// �÷��̾�� ������ x ��ǥ�� ����, ���� ������ Ȯ��
		if (info.posX >= (*i)->lPoint.x &&
			info.posX <= (*i)->rPoint.x)
		{
			// ���� ������ ����
			currentLine = *i;
			break;
		}
	}

	// ���� ������ ���ٸ� ����
	if (currentLine == nullptr)
	{
		if (!isJump)
		{
			time += 0.1f;
			info.posY += 0.98f * time * time * .5f;
		}

		return;
	}

	// ���� ������ �ʺ�� ���̸� ����
	float width = currentLine->rPoint.x - currentLine->lPoint.x;
	float height = currentLine->rPoint.y - currentLine->lPoint.y;

	// ���ο� y ���� =
	// ���̿� �ʺ� ���� * (���� ������ �������� ���������� �÷��̾��� x ��ġ) + (���� �ʱ� ��ġ y)
	float y = (height / width) * (info.posX - currentLine->lPoint.x) + currentLine->lPoint.y;
	y -= info.sizeY;

	// ���� ���°� �ƴ� ���� �÷��̾� y ��ġ ����
	if (!isJump)
	{
		info.posY = y;
	}

	// �÷��̾ ���� ��, ���ο� ����� �� ���� ���� ������ y ������
	// y�� ����� ���� ����
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
