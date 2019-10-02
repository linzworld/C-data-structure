#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include <malloc.h>

char* addScore( char* a, char* b );
int charToInt( char* temp );
void simplify( int* a, int* b );

//������ӣ�����Է�������ʽ���
int main( ) {
	
	char str1 [60], str2 [60] ;
	printf( "������Ҫ������ӵķ���������0������������\n" );
	scanf( "%s", str1 );
	while ( strcmp( str1, "0" ) != 0 )
	{
		scanf( "%s", str2 );
		if (strcmp( str2, "0" ) == 0) break;//��str2Ϊ0����ѭ������
		strcpy( str2, addScore( str1, str2 ) );
		strcpy( str1, str2 );
	}
	printf("\n����ȫ�������ļ�����Ϊ��\n");
	puts( str1 );
}

//����������ӵĺ���,��һ��������Ϊһ���ַ������д���
char* addScore( char *a, char* b){
	char* numeratorA,* numeratorB;//���������ķ���
	char* denominatorA, * denominatorB;//��ĸ
	int numerator,  denominator;//����ķ��Ӻͷ�ĸ
	char retStr[100] ;
	numeratorA = strtok( a, "/" );
	denominatorA = strtok( NULL, "/" );

	numeratorB = strtok( b, "/" );
	denominatorB = strtok( NULL, "/" );
	
	numerator = charToInt( denominatorB ) * charToInt( numeratorA ) + charToInt( denominatorA ) * charToInt( numeratorB );//���ӵĽ��
	denominator = charToInt( denominatorA ) * charToInt( denominatorB );//��ĸ

	simplify( &numerator, &denominator );

	sprintf( retStr, "%d", numerator );//�����Ӵ�����ת��Ϊ�ַ���
	sprintf( denominatorA, "%d", denominator );//�����Ӵ�����ת��Ϊ�ַ���

	strcat( retStr, "/" );//ƴ��Ϊ���
	strcat( retStr, denominatorA );
	printf( "\t��ǰ������Ϊ��" );
	puts( retStr );

	return retStr;
}

//��һ���ַ�������ת��Ϊ����
int charToInt( char* temp  ) {
	int num = 0 ;//ת���������
	while (*temp != '\0')
	{
		num = num * 10 + ( *temp - '0' );
		temp++;
	}
	return num;
}

//����Ϊ����ʽ
void simplify( int *a,int *b ) {
	int i;
	for (i = *b; i >= 2; i--) {
		if (*a % i == 0 && *b % i == 0) {
			*a = *a / i;
			*b = *b / i;
		}
	}

}