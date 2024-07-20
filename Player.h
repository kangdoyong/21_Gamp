#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	bool isJump; // 현재 점프 상태인지
	float time; // 점프 시, 가속도 표현을 위해 사용
	// 이동 속력
	float speed;
	// 메인게임 객체에 있는 장애물 객체의 주소를 담을 필드
	Object* obstacle;
	// 메인게임 객체에 있는 라인리스트의 주소를 담을 필드
	list<LINE*>* lineList;

private:
	void CheckKey(); // 키 입력 체크
	void Jump();     // 점프 기능
	void BoxColl();  // 박스 충돌 체크
	void LineColl(); // 라인 충돌 체크

public:
	// Object을(를) 통해 상속됨
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


