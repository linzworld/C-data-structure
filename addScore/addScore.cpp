#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include <malloc.h>

char* addScore( char* a, char* b );
int charToInt( char* temp );
void simplify( int* a, int* b );

//分数相加，结果以分数的形式输出
int main( ) {
	
	char str1 [60], str2 [60] ;
	printf( "请输入要进行相加的分数：输入0则代表运算结束\n" );
	scanf( "%s", str1 );
	while ( strcmp( str1, "0" ) != 0 )
	{
		scanf( "%s", str2 );
		if (strcmp( str2, "0" ) == 0) break;//若str2为0，则循环结束
		strcpy( str2, addScore( str1, str2 ) );
		strcpy( str1, str2 );
	}
	printf("\n以上全部分数的计算结果为：\n");
	puts( str1 );
}

//两个分数相加的函数,将一个分数化为一个字符串进行处理
char* addScore( char *a, char* b){
	char* numeratorA,* numeratorB;//两个分数的分子
	char* denominatorA, * denominatorB;//分母
	int numerator,  denominator;//结果的分子和分母
	char retStr[100] ;
	numeratorA = strtok( a, "/" );
	denominatorA = strtok( NULL, "/" );

	numeratorB = strtok( b, "/" );
	denominatorB = strtok( NULL, "/" );
	
	numerator = charToInt( denominatorB ) * charToInt( numeratorA ) + charToInt( denominatorA ) * charToInt( numeratorB );//分子的结果
	denominator = charToInt( denominatorA ) * charToInt( denominatorB );//分母

	simplify( &numerator, &denominator );

	sprintf( retStr, "%d", numerator );//将分子从数字转化为字符串
	sprintf( denominatorA, "%d", denominator );//将分子从数字转化为字符串

	strcat( retStr, "/" );//拼接为结果
	strcat( retStr, denominatorA );
	printf( "\t当前计算结果为：" );
	puts( retStr );

	return retStr;
}

//将一个字符串数组转化为数字
int charToInt( char* temp  ) {
	int num = 0 ;//转化后的数字
	while (*temp != '\0')
	{
		num = num * 10 + ( *temp - '0' );
		temp++;
	}
	return num;
}

//化简为最简分式
void simplify( int *a,int *b ) {
	int i;
	for (i = *b; i >= 2; i--) {
		if (*a % i == 0 && *b % i == 0) {
			*a = *a / i;
			*b = *b / i;
		}
	}

}