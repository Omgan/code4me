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
	void breath()
	{
		std::cout<<"animal breath"<<std::endl;
	}
	virtual void add(int a, int b)
	{

	}
};

class Fish : public Animal
{
public:
	Fish(){}
	~Fish(){}
	void breath() //���ػ����breath����,ԭ������breath���������麯��
	{
		std::cout<<"fish breath"<<std::endl;
	}

	// ��������л���ͬ���������ǲ�ͬ�����б�ĺ���,���ܻ���ĺ��������Ƿ���
	// virtual�ؼ���,���ຯ������������.
	void add(int a, int b, int c)
	{
		std::cout<<"fish add()"<<std::endl;
		// �������Ҫ�����ڴ˵��û����ͬ������ͬ�����б�ĺ���.
		Animal::add(a, b);
	}
};


// ���Ƿ����ڻ����������֮��,�һ��ຯ���������麯��.
// ����֮���������
int main (int argc, char** argv)
{
	Fish fish;
	fish.breath();
	fish.add(1,2,3);
	return 0;
};
