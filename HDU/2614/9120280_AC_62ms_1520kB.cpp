#include<stdio.h>
#include<string.h>
int n,des[20],max;
int num[20][20];
void DFS( int p,int val,int nu )
{
	int flag = 0;
	for( int i = 1; i <= n; ++i )
	{
		if( !des[i] && ( num[p][i] >= val ) )
		{
			des[i] = 1;
			DFS( i,num[p][i],nu + 1 );
			des[i] = 0;
			flag = 1;
		}
	}
	if( !flag )
		if( nu > max )
			max = nu;
}
int main( )
{
	while( scanf( "%d",&n ) != EOF )
	{
		max = 0;
		memset( num,0,sizeof( num ) );
		memset( des,0,sizeof( des ) );
		for( int i = 1; i <= n; ++i )
			for( int j = 1; j <= n; ++j )
				scanf( "%d",&num[i][j] );
		des[1] = 1;
		DFS( 1,0,1);
		printf( "%d\n",max );
	}
	return 0;
}