#include<iostream>

// �����������ǵ�����:
// ���ຯ���������麯��(ʹ��virtual�ؼ��ֽ�������)
// �������ǵ�������������Ҫ�ֱ�λ��������ͻ�����
// �������ƺͲ����б������ȫ��ͬ

class Animal
{
public:
	Animal(){}
	~Animal(){}
	virtual void breath()
	{
		std::cout << "animal breath " << std::endl;
	}
};

class Fish
{
public:
	Fish(){}
	~Fish(){}
	void breath()
	{
		std::cout << "fish breath" << std::endl;
	}
};

int main (int argc, char** argv)
{
	return 0;
};
