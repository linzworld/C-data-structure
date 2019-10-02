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
	ElemType data;     // 数据域
	struct LNode* next;     // 指针域
} LNode, * LinkList;
LinkList  L; // L 为单链表的头指针
LinkList  R;

//函数声明
/********************************************************************/
LNode* MakeNode_L( ElemType e );
Status InsertAfter_L( LNode* p, LNode* q );
/********************************************************************/


//含有头节点的单链表
/********************************************************************/
Status InitList_L( LinkList& L ) { // 初始化一个只含头结点的空单链表L
	if (NULL == ( L = (LNode* )malloc( sizeof( struct LNode ) ) )) // 生成新结点
		return OVERFLOW;
	L->next = NULL;
	return OK;
}

Status CreatList_L( LinkList& L, int n, ElemType* A ) {
	// 建立一个长度为n的单链表，数组A[]提供n个元素值
	LinkList p, q;
	int i;
	p = L;
	printf( "链表初始化操作\n" );
		for( i=0; i<n; i++  )
		{
			q = (LinkList )malloc( sizeof( LNode ) );
			q->data = A [i];
			q->next = NULL;
			p->next = q;
			//移动指针到最新的一个节点
			p = q; 
		}
	return OK;
}

int ListLength_L( LinkList L ) { // 求单链表L的表长
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
	// 遍历单链表L 
	LNode* p;
	if (L != NULL) {
		//排除头节点
		p = L->next;
		while (p != NULL) {
			visit( p->data );
			p = p->next;
		}
	}
	
}

Status EnFirst_L( LinkList& L, ElemType e ) {
	//完成功能：带头结点单链表中 插入首元素，在头节点的后面
	if (NULL == L ) return ERROR;//参数的验证
	//新建一个数据域为e的一个节点,并且插入
	InsertAfter_L( L,MakeNode_L(e) );
	return OK;
}

Status DelFirst_L( LinkList& L, ElemType& e ) {
	//完成功能：带头结点单链表中 删除首元素
	LNode* q;
	if (NULL == L || NULL == L->next) return ERROR;

	q = L->next;//被删除的节点
	L->next = q->next;
	e = q->data;
	free( q );//释放节点
	return OK;
}

LNode* MakeNode_L( ElemType e ) { // 构造数据域为e的单链表结点
	LNode* p;
	p = (LNode* )malloc( sizeof( struct LNode ) ); // 分配结点空间
	if (p != NULL) p->data = e;
	p->next = NULL;
	return p;
}

Status InsertAfter_L( LNode* p, LNode* q ) {  // 在p结点之后插入q结点
	if (NULL == p || NULL == q) return ERROR;  // 参数不合理
	q->next = p->next;    // 修改q结点的指针域
	p->next = q;            //  修改p结点的指针域
	return OK;
}

Status ClearList_L( LinkList& L ) {
	// 将单链表Ｌ重置为空表
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

//不含有头节点的单链表
/********************************************************************/
Status CreatList_L1( LinkList& L, int n, ElemType* A ) {
	// 建立一个长度为n的单链表，数组A[]提供n个元素值 L仍为头指针
	LinkList q, temp = NULL;
	int i;
	printf( "链表初始化操作\n" );
	for (i = 0; i < n; i++)
	{
		q = (LinkList )malloc( sizeof( LNode ) );
		//内存空间不足
		if (NULL == q) return ERROR;
		q->data = A [i];
		q->next = NULL;
		//首元节点
		if (i == 0) { 
			L = q;
		}
		else if( i == 1 ){ 
			//移动指针到最新的一个节点
			L->next = q;
			temp = L->next;
		}
		else{
			temp->next = q;
			//指针后移
			temp = temp->next;
		}
	}
	return OK;
}

int ListLength_L1( LinkList L ) { // 求不带头结点单链表L的表长
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
	// 遍历不带头结点的单链表L 
	LNode* p;
	p = L;
	while (p != NULL) {
		visit( p->data );
		p = p->next;
	}
}

Status EnFirst_L1( LinkList& L, ElemType e ) {
	//完成功能：不带头结点单链表 插入首元素
	if (NULL == L) return ERROR;//参数的验证
	//新建一个数据域为e的一个节点,并且插入
	LNode* temp;
	temp = MakeNode_L( e );
	temp ->next= L;
	//新的头指针
	L = temp;
	return OK;
}

Status DelFirst_L1( LinkList& L, ElemType e ) {
	//完成功能：不带头结点单链表 删除首元素
	LNode* q;
	if (NULL == L ) return ERROR;

	q = L;//被删除的节点
	e = L->data;
	L = L->next;

	free( q );//释放节点
	return OK;
}

LNode* Search_L( LinkList L, ElemType e ) {
	LNode* p;
	if (NULL == L->next) return NULL; // L是空表
	p = L->next;
	while (p->data != e && p->next != NULL) p = p->next; // 查找值为e的结点
	if (p->data == e) return p;
	return NULL; //未找到
}

Status  printElement( ElemType e ) {//打印元素
	printf("%c ", e );
	return OK;
}


void testWithHeadNode( char A[], ElemType e ) {	//构造带头结点的单链表L
	printf( "/********************************************************************/\n" );
	printf( "带头结点：\n" );
	InitList_L( L );
	//构造带头结点的单链表L
	CreatList_L( L, 5, A );

	//输出新建链表的长度
	printf( "单链表的长度为：%d\n", ListLength_L( L ) );
	//完成操作并测试：带头结点单链表 插入首元素 （值为 T）
	printf( "插入前：\n" );
	//遍历链表中的所有元素
	ListTraverse_L( L, printElement );
	//插入元素
	EnFirst_L( L, 'T' );
	printf( "\n插入后：\n" );
	//遍历链表中的所有元素
	ListTraverse_L( L, printElement );
	//完成操作并测试测试：带头结点单链表 删除首元素
	DelFirst_L( L, e );
	printf( "\n删除后：\n" );
	ListTraverse_L( L, printElement );
}

void testNoWithHeadNode( char A[], ElemType e ) {
	//构造不带头结点的单链表L
	printf( "\n\n/********************************************************************/" );
	printf( "\n不带头结点：\n" );

	ClearList_L( L );
	CreatList_L1( L, 5, A );
	ListTraverse_L1( L, printElement );

	printf( "\n不带头节点的链表长度：%d\n ", ListLength_L1( L ) );

	//完成操作并测试：不带头结点单链表 插入首元素 （值为 T）
	printf( "\n插入前：\n" );
	ListTraverse_L1( L, printElement );

	EnFirst_L1( L, 'T' );
	printf( "\n插入后：\n" );
	ListTraverse_L1( L, printElement );
	//完成操作并测试测试：不带头结点单链表 删除首元素
	
	DelFirst_L1( L, e );
	printf( "\n删除后：\n" );
	ListTraverse_L1( L, printElement );


	LNode* p;
	p = Search_L( L, 'A' );
	printf( "\n查找结果：\n%c ", p->data );

}


int main( ) {

	ElemType e = NULL;
	char A[] = { 'D', 'C', 'A', 'F', 'E' };
	testWithHeadNode(A, e );
	testNoWithHeadNode( A, e );
}
