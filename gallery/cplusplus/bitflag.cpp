// bitflag.cpp
// Demonstrate C++ binary operation

#include <stdio.h>

#define BIT_LSHIFT(v, n)	((v) << (n))
#define BIT_RSHIFT(v, n)	((v) >> (n))
#define BIT_FLAG(n)		BIT_LSHIFT(1, n)
#define BIT_CHECK_FLAG(m, n)	((m & BIT_FLAG(n))?1:0)
#define BIT_SET_FLAG(m, n)	(m |= BIT_FLAG(n))
#define BIT_CLEAR_FLAG(m, n)	(m &= ~BIT_FLAG(n))


// λ��
// �ܳ�Ϊ32λ,4���ֽ�
struct packed_data
{
	unsigned a:2; // ռ2λ
	unsigned b:6; // ռ6λ
	unsigned c:4;
	unsigned d:4;
	int i;
}data;


//����λ�εĶ��������,�м���˵��
/*
 (1)λ�γ�Ա�����ͱ���ָ��Ϊunsigned int ����
 (2)��ĳһλ��Ҫ����һ���ֿ�ʼ���.������������ʽ����:
	unsigned a : 1;(һ���洢��Ԫ)
	unsigned b : 2;()
	unsigned   : 0;
	unsigned c : 3 (��һ���洢��Ԫ)

 (3)һ��λ�α���洢��ͬһ�洢��Ԫ��,���ܿ�������Ԫ.�����һ����Ԫ�ռ䲻������
    ��һ��λ��,��ÿռ䲻��,������һ����Ԫ���Ÿ�λ�Ρ�

 (4)���Զ��������ֶ�
    unsigned a : 1;
	unsigned b : 2
	unsigned   : 3; (����λ�ռ䲻��)
	unsigned c : 4;

 (5)λ�ο��������͸�ʽ�����
    printf("%d,%d,%d",data.a, data.b,data.c)

 (6)λ�ο�������ֵ���ʽ�����ã����ᱻϵͳ�Զ���ת������������
    data.a + 5/data.b
*/


int main(int argc, char** argv)
{
	int i =1;
	i = BIT_LSHIFT(i,10);
	printf("left shift %d\n", i);

	int k= BIT_FLAG(-2);
	printf("bit flag %d\n", k);

	data.a = 2; // ע��λ��a����ʾֵ���Χ.
	data.a = 8; // error:��ʱdata.a=0;ȡ����8�ĵ�2λ1000.

	data.i = 1<<20;
	printf("%d,%d,%d,%d,%d\n", data.a, data.b, data.c, data.d, data.i);

	// ����λ������Ϊ2���ֽ�,iΪ4���ֽ�.���尴˵Ӧ����6���ֽ�.
	// �����ǵ��ֽڶ��������,�������8���ֽ�.
	printf("data size: %d\n", sizeof(data)); // surprise: size = 8;

	return 0;
}
