// linktable.cpp
// Demonstration a link table usage:

// �����������͵Ķ���
typedef struct node{
	int data;
	struct node *link;
}NODE, *LinkList;

/* 
 *	�������������
 *	LΪ�����ͷָ��,�ڱ��в��ҵ�K��Ԫ��,���ظ�Ԫ�ؽ��ָ��,����,���ؿ�ָ��NULL
 */
LinkList Find_List(LinkList L, int k)
{
	LinkList p; int i;
	i = 1; p = L->link;
	while (p && k<i)
	{
		p = p->link;
		i++;
	}
	return (p && i==k) ? p : NULL;
}

/*
 * 	������Ĳ������� 
 *  LΪ�����ͷָ��,
 *  KΪ����������λ��
 *  elemΪԪ��ֵ
 */
int Insert_List(LinkList L, int k, int elem)
{
	LinkList p, q;
	if (k == 1) { 
		p = L;
	}
	else {
		// ���ұ��е�k-1��Ԫ��,ԭ����Ҫ��k-1��λ�ú������Ԫ��.
		p = Find_List(L, k-1);
	}
	
	if (p == NULL)
		return -1;
	
	q = (NODE*)malloc(sizeof(NODE));
	q->data = elem;
	q->link = p->link;
	p->link = q;
	return 0;
}

/*
 *	�������ɾ������
 *  LΪ����ͷָ��
 *  KΪԪ��λ��
 *  �ɹ�����0,ʧ�ܷ���-1.
 */
int Delete_List(LinkList L, int k)
{
	LinkList p, q;
	if (k==1) { 
		p = L;
	} else {
		p = Find_List(L, k-1);
	}

	if (p == NULL)
		return -1;

	q = p->link;
	p->link = q->link;
	free(q);
	return (0);
}

int main(int argc, char** argv)
{
	return (0);
}