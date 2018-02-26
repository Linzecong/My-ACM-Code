#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
using namespace std;

char str[105][105];
char ans[105][105];

int dx[4]={1,-1,0,1};
int dy[4]={0,1,1,-1};

int dx2[4]={0,-1,1,1};
int dy2[4]={1,1,0,-1};

int dx3[4]={1,0,-1,0};
int dy3[4]={0,1,0,-1};

int main(){
	
	int N;
	while(~scanf("%d",&N)){
	
	char temp[105];
	for(int i=1;i<=N;i++){
		scanf("%s",temp);
		for(int j=1;j<=N;j++)
			str[i][j]=temp[j-1];
	}
	
	string ss;
	int dir=0;
	int x=1,y=1;
	bool re=0;
	
	while(!(x==N&&y==N)){
		
		if(x==N&&y==1&&N%2==1){
			re=1;
			dir=0;
		}
		if(x==1&&y==N&&N%2==0){
			re=1;
			dir=2;
		}	
		
		ss.push_back(str[y][x]);
		if(re==0){
			x+=dx[dir];
			y+=dy[dir];
		
		if(y==1)
			dir=(dir+1)%4;
		if(x==1)
			dir=(dir+1)%4;
		}
		else{
			x+=dx2[dir];
			y+=dy2[dir];
		
		if(y==N)
			dir=(dir+1)%4;
		if(x==N)
			dir=(dir+1)%4;
		}
	}
	
	ss.push_back(str[x][y]);
	
	int xx=1,yy=1;
	int dd=0;
	memset(ans,0,sizeof(ans));
	for(int i=0;i<=N+1;i++)
	{
		ans[0][i]='a';
		ans[N+1][i]='a';
		ans[i][0]='a';
		ans[i][N+1]='a';
	}
	
	for(int i=0;i<ss.size();i++){
		ans[yy][xx]=ss[i];
		if(ans[yy+dy3[dd]][xx+dx3[dd]]!=0)
			dd=(dd+1)%4;
		
		xx+=dx3[dd];
		yy+=dy3[dd];
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
		printf("%c",ans[i][j]);
		printf("\n");
	}
}
	
	
	return 0;
}