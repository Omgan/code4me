#include <iostream>

class Animal
{
public:
	Animal(int a, int b){}
	~Animal(){}
};

class Fish : public Animal
{
public:
	
	// ԭ�����:�����ṩĬ�Ϲ��캯�������ǻ���û���ṩĬ�Ϲ��캯����
	// �����ڽ��ж���ʵ����ʱ����û����Ĭ�Ϲ��캯�������ԲŻ������������֡�
	// Fish(){}; // error C2512: ��Animal��: û�к��ʵ�Ĭ�Ϲ��캯������
	
	// �������:������������ָ�����û���������Ĺ��캯���� 
	Fish() : Animal(2, 3){}
	~Fish(){};
};

/**
 * ע�⣺
 * �����е�private��Ա�������������ʣ���˻����е�private��Ա���ܱ�����̳С�
 */

// Ĭ����private�̳�
// �������г�Ա����������private��Ա
class Cat : Animal
{
public:
	Cat() : Animal(2, 3){}
	~Cat();
};

// protected�̳�
// ������public��protected����������protected��Ա
class Bird : public Animal
{
public:
	Bird() : Animal(2,3){}
	~Bird();
};

// public�̳�
// ������public��protected��Ա����ԭ��Ȩ�����Ա�������Ա
class Dog : public Animal
{
public:
	Dog() : Animal(2, 3){}
	~Dog(){}
};



int main(int argc, char** argv)
{
	Fish fish; 
	return 0;
};