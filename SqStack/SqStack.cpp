#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
typedef int Status;
typedef char ElemType;
typedef struct{  //do��������Ͷ���
	ElemType* elem;//ָ�������ݵĵط�
	ElemType* top;//ջ��ָ��
	int size;//��ǰ����Ĵ洢����
	int increment;//����ʱ���ӵĴ洢������
} SqStack;

Status InitStack_Sq(SqStack &S, int size, int increment){ // do: ��ʼ���յ�˳��ջS
	if (size < 1 || incremnet < 1) return ERROR;
	S.elem = (ElemType* )malloc( size * sizeof( ElemType ) );//�����ڴ�ռ�
	if (NULL == S.elem) return ERROR;//�����ڴ�ռ�ʧ��
	S.top = S.elem;//��SΪ��ջ
	S.size = size;//��ʼ��������ֵ
	S.increment = increment;//���ݵ�����
	return OK;
}
 
Status StackEmpty_Sq(SqStack S){  // do: �пգ���Ϊ���򷵻�TURE�����򷵻�FALSE 
	if ( S.top == S.elem )return ERROR;//S.topָ��Ϊ0ʱ����ʾջ��
	else return FALSE;
}

Status Push_Sq(SqStack &S, ElemType e) { // do:Ԫ��e��ջ
	ElemType* newbase;//ת�����м�վ
	if (S.top - S.elem >= S.size) { 
		newbase = (ElemType* )realloc( S.elem, ( S.size + S.increment ) * sizeof( ElemType ) );

		if (NULL == newbase)return ERROR;
		S.top = newbase + ( S.top - S.elem );//ջ��ָ��
		S.elem = newbase;
		S.size += S.increment;
	}
	*S.top++ = e;//e��ջ�����ҽ�ջ��ָ��+1
	return OK;
}

Status ClearStack_Sq(SqStack &S){ // do:���ջS 
    
}

Status GetTop_Sq(SqStack S, ElemType &e) { // do:ȡջS��ջ��Ԫ�أ���e����
	if (S.top == S.elem) return ERROR;
	e = S.top - 1;
	return OK;
}

Status Pop_Sq(SqStack &S, ElemType &e) { // do:ջS��ջ��Ԫ�س�ջ������e����
	if (S.top == S.elem ) return ERROR;
	e = *--S.top;//S.topΪջ��ָ��
	return OK;
}

Status DestroyStack_Sq(SqStack &S) {   //do:����ջ    
	free(S.size);
	S.size = NULL;
    S.top = NULL;
	S.size = 0;
	S.increment = 0;
    return OK;
      
}

void Converstion(int N) { //do:����ջ��ʮ������Nת��Ϊ�˽����������
	SqStack S;
	ElemType e;
	InitStack_Sq( S, 10, 5 );
	while (N != 0) { 
		Push_Sq( S, N % 8 );//������ջ
		N /= 8;
	} 
	while (FALSE == StackEmpty_Sq( S )) { 
		Pop_Sq( S, e );
		printf( "%d", e );
	}
}

Status Matching(char *exp, int n) { //do:�ж�����ƥ�䣬��ƥ�䷵��TURE�����򷵻�FLASE
	int i = 0;
	ElemType e;
	SqStack S;
	InitStack_Sq( S, n, 5 );
	while( i<n ){
		switch (exp[i])
		{
			case "(":
			case "[":Push_Sq( S, exp [i] ); i++; break;
			case ")":
			case "]":
				if (TRUE == StackEmpty_Sq( S ))
					return ERROR;
				else{
					GetTop_Sq( S, e );
					if (( exp [i] == ')' && e == '(' ) || ( exp [i] == ']' && e == '[' )) {
						Pop_Sq( S.e ); i++;
					}
					else
						return ERROR;
				}
				break;
		}
	}
	if (TRUE == StackEmpty_Sq( S ))return OK;
	else return ERROR;
}


void main(){
	//do:����ջ�ĳ�ʼ������

   //do:�������ݵ�����,����һ����ջ����ջ�ͷǿշ�����ջ,��������ջ�Ĺ���

   //do:���Խ�ջ��ջ����

   //do:������ֵת�������Ŵ���ƥ��
	char flag;
	//do:���Խ�ջ��ջ����
	while (TRUE) {
		ElemType c;
		printf( "��ջ:" );
		scanf( "%c", &c );
		getchar( );
		getchar( );
		Push_Sq( S, c );
		printf( "ֹͣ?(y|n)" );
		scanf( "%c", &flag );
		getchar( );
		getchar( );
		if (flag == 'y' || flag == 'Y')
			break;
	}
	while (TRUE) {
		ElemType c;
		printf( "�Ƿ��ջ?(y|n)" );
		scanf( "%c", &flag );
		getchar( );
		getchar( );
		if (flag == 'y' || flag == 'Y')
		{
			Pop_Sq( S, c );
			printf( "pop:%c", c );
		}
		printf( "\n����?(y|n)" );
		scanf( "%c", &flag );
		getchar( );
		getchar( );
		if (flag == 'y' || flag == 'Y')
			break;
	}

}

