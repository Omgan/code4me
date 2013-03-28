#include <iostream>

class Animal
{
public:	
	Animal(){};
	~Animal(){};
	virtual void breath()
	{
		std::cout << "animal breath" << std::endl;
	}

	// ���ع��ɵ�����:�����������͡�����������ͬ�����ܹ������ء�
	// ֻ�к�������ֵ��ͬ�ǲ��ܹ����ɵġ�
	void move();	
	void move(int a, int b);

	// ������������ǲ��ܹ��ɺ��������أ����������塣
	void add(int a){};
	void add(int a, int b=5){};
};

class Fish : public Animal
{
public:
	Fish(){};
	~Fish(){};
	void breath() // ��д����ĺ���
	{
		std::cout << "fish breath" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	Fish fish;
	Animal* pAn = &fish;
	pAn->breath(); // call class fish::breath()	
	return 0;
}

