#include<iostream>
#include<math.h>
#include<deque>

using namespace std;

char maze[35][35][35];
bool map[35][35][35];

int l,n,m;

struct point{
	int l;
	int n;
	int m;
	int step;
};



int bfs(int ml,int mn,int mm,int eml,int emn,int emm){
	
	
	deque<point>  que;
	
	point start;
	start.l=ml;
	start.n=mn;
	start.m=mm;
	start.step=0;
	
	que.push_back(start);
	
	while(!que.empty()){
		point tmp=que.front();
		
		que.pop_front();
		
		map[tmp.l][tmp.n][tmp.m]=1;
		
		if(tmp.l==eml&&tmp.n==emn&&tmp.m==emm){
			return tmp.step;
		}
		
		if(maze[tmp.l+1][tmp.n][tmp.m]!='#'&&map[tmp.l+1][tmp.n][tmp.m]==0){
			point p;
	        p.l=tmp.l+1;
	        p.n=tmp.n;
	        p.m=tmp.m;
	        p.step=tmp.step+1;
	        
	        map[tmp.l+1][tmp.n][tmp.m]=1;
	        
	        que.push_back(p);
		}
		if(maze[tmp.l-1][tmp.n][tmp.m]!='#'&&map[tmp.l-1][tmp.n][tmp.m]==0){
			point p;
	        p.l=tmp.l-1;
	        p.n=tmp.n;
	        p.m=tmp.m;
	        p.step=tmp.step+1;
	        
	        map[tmp.l-1][tmp.n][tmp.m]=1;
	        
	        que.push_back(p);
		}
		if(maze[tmp.l][tmp.n+1][tmp.m]!='#'&&map[tmp.l][tmp.n+1][tmp.m]==0){
			point p;
	        p.l=tmp.l;
	        p.n=tmp.n+1;
	        p.m=tmp.m;
	        p.step=tmp.step+1;
	        map[tmp.l][tmp.n+1][tmp.m]=1;
	        
	        que.push_back(p);
		}
		if(maze[tmp.l][tmp.n-1][tmp.m]!='#'&&map[tmp.l][tmp.n-1][tmp.m]==0){
			point p;
	        p.l=tmp.l;
	        p.n=tmp.n-1;
	        p.m=tmp.m;
	        p.step=tmp.step+1;
	        
	        map[tmp.l][tmp.n-1][tmp.m]=1;
	        
	        que.push_back(p);
		}
		if(maze[tmp.l][tmp.n][tmp.m+1]!='#'&&map[tmp.l][tmp.n][tmp.m+1]==0){
			point p;
	        p.l=tmp.l;
	        p.n=tmp.n;
	        p.m=tmp.m+1;
	        p.step=tmp.step+1;
	        
	        map[tmp.l][tmp.n][tmp.m+1]=1;
	        
	        que.push_back(p);
		}
		if(maze[tmp.l][tmp.n][tmp.m-1]!='#'&&map[tmp.l][tmp.n][tmp.m-1]==0){
			point p;
	        p.l=tmp.l;
	        p.n=tmp.n;
	        p.m=tmp.m-1;
	        p.step=tmp.step+1;
	        
	        map[tmp.l][tmp.n][tmp.m-1]=1;
	        que.push_back(p);
		}
			
	}
	 
	return 0;
	
}





int main(){
	
	
	while(cin>>l>>n>>m){
		
	
	
		
		if(n==0&&m==0&&l==0)
		break;
		
		
		for(int i=0;i<35;i++)
		for(int j=0;j<35;j++)
		for(int k=0;k<35;k++){
			maze[i][j][k]='#';
			map[i][j][k]=0;
		}
		
		
		int ll,nn,mm;
		int el,en,em;
		
		for(int i=1;i<=l;i++)
		for(int j=1;j<=n;j++)
		for(int k=1;k<=m;k++){
			cin>>maze[i][j][k];
			if(maze[i][j][k]=='S')
			{
				ll=i;
				nn=j;
				mm=k;
			}
			if(maze[i][j][k]=='E')
			{
				el=i;
				en=j;
				em=k;
			}
		}
		
		
		int res=bfs(ll,nn,mm,el,en,em);
		
		
		
		if(res>0)
		cout<<"Escaped in "<<res<<" minute(s)."<<endl;
		else
		cout<<"Trapped!"<<endl;
	}
	
	return 0;
}