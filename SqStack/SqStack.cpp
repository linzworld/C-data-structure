#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
typedef int Status;
typedef char ElemType;
typedef struct{  //do：完成类型定义
	ElemType* elem;//指向存放数据的地方
	ElemType* top;//栈顶指针
	int size;//当前分配的存储容量
	int increment;//扩容时增加的存储的容量
} SqStack;

Status InitStack_Sq(SqStack &S, int size, int increment){ // do: 初始化空的顺序栈S
	if (size < 1 || incremnet < 1) return ERROR;
	S.elem = (ElemType* )malloc( size * sizeof( ElemType ) );//分配内存空间
	if (NULL == S.elem) return ERROR;//申请内存空间失败
	S.top = S.elem;//置S为空栈
	S.size = size;//初始化的容量值
	S.increment = increment;//扩容的数量
	return OK;
}
 
Status StackEmpty_Sq(SqStack S){  // do: 判空，若为空则返回TURE，否则返回FALSE 
	if ( S.top == S.elem )return ERROR;//S.top指向为0时，表示栈空
	else return FALSE;
}

Status Push_Sq(SqStack &S, ElemType e) { // do:元素e入栈
	ElemType* newbase;//转化的中间站
	if (S.top - S.elem >= S.size) { 
		newbase = (ElemType* )realloc( S.elem, ( S.size + S.increment ) * sizeof( ElemType ) );

		if (NULL == newbase)return ERROR;
		S.top = newbase + ( S.top - S.elem );//栈顶指针
		S.elem = newbase;
		S.size += S.increment;
	}
	*S.top++ = e;//e入栈，并且将栈顶指针+1
	return OK;
}

Status ClearStack_Sq(SqStack &S){ // do:清空栈S 
    
}

Status GetTop_Sq(SqStack S, ElemType &e) { // do:取栈S的栈顶元素，用e返回
	if (S.top == S.elem) return ERROR;
	e = S.top - 1;
	return OK;
}

Status Pop_Sq(SqStack &S, ElemType &e) { // do:栈S的栈顶元素出栈，并用e返回
	if (S.top == S.elem ) return ERROR;
	e = *--S.top;//S.top为栈顶指针
	return OK;
}

Status DestroyStack_Sq(SqStack &S) {   //do:销毁栈    
	free(S.size);
	S.size = NULL;
    S.top = NULL;
	S.size = 0;
	S.increment = 0;
    return OK;
      
}

void Converstion(int N) { //do:借助栈将十进制数N转化为八进制数并输出
	SqStack S;
	ElemType e;
	InitStack_Sq( S, 10, 5 );
	while (N != 0) { 
		Push_Sq( S, N % 8 );//余数入栈
		N /= 8;
	} 
	while (FALSE == StackEmpty_Sq( S )) { 
		Pop_Sq( S, e );
		printf( "%d", e );
	}
}

Status Matching(char *exp, int n) { //do:判断括号匹配，若匹配返回TURE，否则返回FLASE
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
	//do:测试栈的初始化操作

   //do:测试数据的生成,构造一个空栈、满栈和非空非满的栈,并完成输出栈的工作

   //do:测试进栈出栈操作

   //do:测试数值转换和括号串的匹配
	char flag;
	//do:测试进栈出栈操作
	while (TRUE) {
		ElemType c;
		printf( "入栈:" );
		scanf( "%c", &c );
		getchar( );
		getchar( );
		Push_Sq( S, c );
		printf( "停止?(y|n)" );
		scanf( "%c", &flag );
		getchar( );
		getchar( );
		if (flag == 'y' || flag == 'Y')
			break;
	}
	while (TRUE) {
		ElemType c;
		printf( "是否出栈?(y|n)" );
		scanf( "%c", &flag );
		getchar( );
		getchar( );
		if (flag == 'y' || flag == 'Y')
		{
			Pop_Sq( S, c );
			printf( "pop:%c", c );
		}
		printf( "\n继续?(y|n)" );
		scanf( "%c", &flag );
		getchar( );
		getchar( );
		if (flag == 'y' || flag == 'Y')
			break;
	}

}

