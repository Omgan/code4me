/** 
 * ���ؼ̳�
 * ���﷨��ʽ��
 class ��������: ����Ȩ�� ��������,����Ȩ�� ��������,����Ȩ�� ��������
 {

 }
 */

// ��ʼ˳��
// ��ʼ���ǰ�����̳б���˵��˳����г�ʼ�ġ�

// ����˳��
// �����ǰ��ջ���̳б��е�˵����˳����������ġ�

#include<iostream>

class B1
{
public:
	B1()
	{
		std::cout<< "B1()" << std::endl;
	}
	~B1()
	{
		std::cout<< "~B1()" << std::endl;
	}
	void output()
	{
		std::cout<< "B1::output()" << std::endl;
	}
};

class B2
{
public:
	B2()
	{
		std::cout<< "B2()" << std::endl;
	}
	~B2()
	{
		std::cout<< "~B2()" << std::endl;
	}
	void output()
	{
		std::cout<< "B2::output()" << std::endl;
	}
};

class A : public B1, public B2
{
public:
	A()
	{
		std::cout<<"A()" << std::endl;
	}
	~A()
	{
		std::cout<<"~A()"<<std::endl;
	}
};

int main (int argc, char** argv)
{
	A a;
	a.output(); // error:����output()��������ȷ
};