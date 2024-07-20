#pragma once

class Object;

// ��ü ���� ��, �����ϰ��� �ϴ� ��ü�� Ÿ�Ը� �ٸ� ��
// �Ź� ������ ������ ����� -> (new, Initialize)
// �׷� �Ź� �޶����� Ÿ�Ը��� �Ϲ�ȭ�Ͽ�, ���� �ݺ��Ǵ� ������
// �� �� ���ϰ� �ذ��� �� ����
// ������ ���� �߿� ���� ���
// �߻� ���丮 ����
template<typename T>
class AbstractFactory
{
public:
	static Object* CreateObject()
	{
		Object* obj = new T();
		obj->Initialize();

		return obj;
	}

	static Object* CreateObject(int x, int y)
	{
		Object* obj = new T();
		obj->Initialize();
		obj->SetPos(x, y);

		return obj;
	}
};