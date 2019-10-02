#include<stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
typedef int Status;

typedef char ElemType;

typedef struct LNode {
	ElemType data;     // ������
	struct LNode* next;     // ָ����
} LNode, * LinkList;
LinkList  L; // L Ϊ�������ͷָ��
LinkList  R;

//��������
/********************************************************************/
LNode* MakeNode_L( ElemType e );
Status InsertAfter_L( LNode* p, LNode* q );
/********************************************************************/


//����ͷ�ڵ�ĵ�����
/********************************************************************/
Status InitList_L( LinkList& L ) { // ��ʼ��һ��ֻ��ͷ���Ŀյ�����L
	if (NULL == ( L = (LNode* )malloc( sizeof( struct LNode ) ) )) // �����½��
		return OVERFLOW;
	L->next = NULL;
	return OK;
}

Status CreatList_L( LinkList& L, int n, ElemType* A ) {
	// ����һ������Ϊn�ĵ���������A[]�ṩn��Ԫ��ֵ
	LinkList p, q;
	int i;
	p = L;
	printf( "�����ʼ������\n" );
		for( i=0; i<n; i++  )
		{
			q = (LinkList )malloc( sizeof( LNode ) );
			q->data = A [i];
			q->next = NULL;
			p->next = q;
			//�ƶ�ָ�뵽���µ�һ���ڵ�
			p = q; 
		}
	return OK;
}

int ListLength_L( LinkList L ) { // ������L�ı�
	int length = 0;
	LinkList p;
	p = L->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

void ListTraverse_L( LinkList L, Status( *visit )( ElemType e ) ) {
	// ����������L 
	LNode* p;
	if (L != NULL) {
		//�ų�ͷ�ڵ�
		p = L->next;
		while (p != NULL) {
			visit( p->data );
			p = p->next;
		}
	}
	
}

Status EnFirst_L( LinkList& L, ElemType e ) {
	//��ɹ��ܣ���ͷ��㵥������ ������Ԫ�أ���ͷ�ڵ�ĺ���
	if (NULL == L ) return ERROR;//��������֤
	//�½�һ��������Ϊe��һ���ڵ�,���Ҳ���
	InsertAfter_L( L,MakeNode_L(e) );
	return OK;
}

Status DelFirst_L( LinkList& L, ElemType& e ) {
	//��ɹ��ܣ���ͷ��㵥������ ɾ����Ԫ��
	LNode* q;
	if (NULL == L || NULL == L->next) return ERROR;

	q = L->next;//��ɾ���Ľڵ�
	L->next = q->next;
	e = q->data;
	free( q );//�ͷŽڵ�
	return OK;
}

LNode* MakeNode_L( ElemType e ) { // ����������Ϊe�ĵ�������
	LNode* p;
	p = (LNode* )malloc( sizeof( struct LNode ) ); // ������ռ�
	if (p != NULL) p->data = e;
	p->next = NULL;
	return p;
}

Status InsertAfter_L( LNode* p, LNode* q ) {  // ��p���֮�����q���
	if (NULL == p || NULL == q) return ERROR;  // ����������
	q->next = p->next;    // �޸�q����ָ����
	p->next = q;            //  �޸�p����ָ����
	return OK;
}

Status ClearList_L( LinkList& L ) {
	// �������������Ϊ�ձ�
	if (L == NULL) return ERROR;
	LNode* p = L->next, * pt;
	while ( p!=NULL )
	{ 
		pt = p->next;
		free( p );
		p = pt;
	}
	L->next = NULL;
	return OK;
}

//������ͷ�ڵ�ĵ�����
/********************************************************************/
Status CreatList_L1( LinkList& L, int n, ElemType* A ) {
	// ����һ������Ϊn�ĵ���������A[]�ṩn��Ԫ��ֵ L��Ϊͷָ��
	LinkList q, temp = NULL;
	int i;
	printf( "�����ʼ������\n" );
	for (i = 0; i < n; i++)
	{
		q = (LinkList )malloc( sizeof( LNode ) );
		//�ڴ�ռ䲻��
		if (NULL == q) return ERROR;
		q->data = A [i];
		q->next = NULL;
		//��Ԫ�ڵ�
		if (i == 0) { 
			L = q;
		}
		else if( i == 1 ){ 
			//�ƶ�ָ�뵽���µ�һ���ڵ�
			L->next = q;
			temp = L->next;
		}
		else{
			temp->next = q;
			//ָ�����
			temp = temp->next;
		}
	}
	return OK;
}

int ListLength_L1( LinkList L ) { // �󲻴�ͷ��㵥����L�ı�
	int length = 0;
	LinkList p;
	p = L;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

void ListTraverse_L1( LinkList L, Status( *visit )( ElemType e ) ) {
	// ��������ͷ���ĵ�����L 
	LNode* p;
	p = L;
	while (p != NULL) {
		visit( p->data );
		p = p->next;
	}
}

Status EnFirst_L1( LinkList& L, ElemType e ) {
	//��ɹ��ܣ�����ͷ��㵥���� ������Ԫ��
	if (NULL == L) return ERROR;//��������֤
	//�½�һ��������Ϊe��һ���ڵ�,���Ҳ���
	LNode* temp;
	temp = MakeNode_L( e );
	temp ->next= L;
	//�µ�ͷָ��
	L = temp;
	return OK;
}

Status DelFirst_L1( LinkList& L, ElemType e ) {
	//��ɹ��ܣ�����ͷ��㵥���� ɾ����Ԫ��
	LNode* q;
	if (NULL == L ) return ERROR;

	q = L;//��ɾ���Ľڵ�
	e = L->data;
	L = L->next;

	free( q );//�ͷŽڵ�
	return OK;
}

LNode* Search_L( LinkList L, ElemType e ) {
	LNode* p;
	if (NULL == L->next) return NULL; // L�ǿձ�
	p = L->next;
	while (p->data != e && p->next != NULL) p = p->next; // ����ֵΪe�Ľ��
	if (p->data == e) return p;
	return NULL; //δ�ҵ�
}

Status  printElement( ElemType e ) {//��ӡԪ��
	printf("%c ", e );
	return OK;
}


void testWithHeadNode( char A[], ElemType e ) {	//�����ͷ���ĵ�����L
	printf( "/********************************************************************/\n" );
	printf( "��ͷ��㣺\n" );
	InitList_L( L );
	//�����ͷ���ĵ�����L
	CreatList_L( L, 5, A );

	//����½�����ĳ���
	printf( "������ĳ���Ϊ��%d\n", ListLength_L( L ) );
	//��ɲ��������ԣ���ͷ��㵥���� ������Ԫ�� ��ֵΪ T��
	printf( "����ǰ��\n" );
	//���������е�����Ԫ��
	ListTraverse_L( L, printElement );
	//����Ԫ��
	EnFirst_L( L, 'T' );
	printf( "\n�����\n" );
	//���������е�����Ԫ��
	ListTraverse_L( L, printElement );
	//��ɲ��������Բ��ԣ���ͷ��㵥���� ɾ����Ԫ��
	DelFirst_L( L, e );
	printf( "\nɾ����\n" );
	ListTraverse_L( L, printElement );
}

void testNoWithHeadNode( char A[], ElemType e ) {
	//���첻��ͷ���ĵ�����L
	printf( "\n\n/********************************************************************/" );
	printf( "\n����ͷ��㣺\n" );

	ClearList_L( L );
	CreatList_L1( L, 5, A );
	ListTraverse_L1( L, printElement );

	printf( "\n����ͷ�ڵ�������ȣ�%d\n ", ListLength_L1( L ) );

	//��ɲ��������ԣ�����ͷ��㵥���� ������Ԫ�� ��ֵΪ T��
	printf( "\n����ǰ��\n" );
	ListTraverse_L1( L, printElement );

	EnFirst_L1( L, 'T' );
	printf( "\n�����\n" );
	ListTraverse_L1( L, printElement );
	//��ɲ��������Բ��ԣ�����ͷ��㵥���� ɾ����Ԫ��
	
	DelFirst_L1( L, e );
	printf( "\nɾ����\n" );
	ListTraverse_L1( L, printElement );


	LNode* p;
	p = Search_L( L, 'A' );
	printf( "\n���ҽ����\n%c ", p->data );

}


int main( ) {

	ElemType e = NULL;
	char A[] = { 'D', 'C', 'A', 'F', 'E' };
	testWithHeadNode(A, e );
	testNoWithHeadNode( A, e );
}
