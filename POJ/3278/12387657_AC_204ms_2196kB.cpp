#include<iostream>
#include<queue>
#include<memory.h>
using  namespace std;

struct point{
	int tp;
	int ceng;
	point(int a,int b){
		tp=a;
		ceng=b;
	}
};

bool vis[1000005];

int main(){
	
	int x,y;
	while(cin>>x>>y){
	
	memset(vis,0,sizeof(vis));
	
	queue<point> que;
	que.push(point(x,0));
	int ans=0;
	vis[x]=1;
	while(!que.empty()){
		point pp=que.front();
		que.pop();	
		if(pp.tp<0)
			continue;
		
		if(pp.tp==y){
			ans = pp.ceng;
			break;
		}
		else{
			
			if(pp.tp>y){
				if(!vis[pp.tp-1]){
					que.push(point(pp.tp-1,pp.ceng+1));
					vis[pp.tp-1]=1;
				}
			}
			else{

				if(!vis[pp.tp-1]){
					que.push(point(pp.tp-1,pp.ceng+1));
					vis[pp.tp-1]=1;
				}
				
				if(!vis[pp.tp+1]){
					que.push(point(pp.tp+1,pp.ceng+1));
					vis[pp.tp+1]=1;
				}
				if(!vis[pp.tp*2]){
					que.push(point(pp.tp*2,pp.ceng+1));
					vis[pp.tp*2]=1;
				}
			}
			
		}
	}
	cout<<ans<<endl;
	
}
	
	
	return 0;
}
 