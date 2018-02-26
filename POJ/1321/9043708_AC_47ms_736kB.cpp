#include<iostream>
using namespace std;

char maze[10][10];
int col[10];
int n,m;

int res=0;

void dfs(int ceng,int num){
	
	if(num==0){
		res++;
		return;
	}
	
	if(ceng>n){
	return;
	}
	
	
	for(int i=1;i<=n;i++){
		if(maze[ceng][i]=='#'&&col[i]==0){
			col[i]=1;
			dfs(ceng+1,num-1);
			col[i]=0;	
		}
	}
	
	dfs(ceng+1,num);
	
}


int main(){
	
	
	while(cin>>n>>m){
		
		res=0;
		
		if(n==-1&&m==-1)
		break;
		
		
		for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		maze[i][j]='.';
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>maze[i][j];
		
		dfs(1,m);
		
		cout<<res<<endl;
		
	}
	
	return 0;
}