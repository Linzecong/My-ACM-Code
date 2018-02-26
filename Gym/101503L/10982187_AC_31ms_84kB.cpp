#include<iostream>
#include<bitset>
#include<queue>
using namespace std;
typedef long long int ll;
const ll INF=(1LL<<62);

bool ok[15];
bool vis[1000];

struct point{
	int num;
	int step;
	point(int a=0,int b=0){
		num=a;
		step=b;
	}
};

int ans=10000;

void bfs(int s,int e){
	
	queue<point> que;
	
	que.push(point(s,0));
	
	vis[s]=1;
	
	while(!que.empty()){
		
		point tp=que.front();
		que.pop();
		vis[tp.num]=1;
		vis[e]=0;
		
		if(tp.num==e){
			ans=min(tp.step,ans);
			continue;
		}
			
			
		for(int i=1;i<=10;i++)
		if(ok[i]&&vis[i%10]==0){
			que.push(point(i%10,tp.step+1));
		//	vis[i%10]=1;
		}	
		
		
		int temp=0;
		if(tp.num+1==100)
		temp=0;
		else
		temp=tp.num+1;
		
		if(ok[11]&&vis[temp]==0){
			que.push(point(temp,tp.step+1));
		//	vis[temp]=1;
		}
		
	    temp=0;
		if(tp.num-1==-1)
		temp=99;
		else
		temp=tp.num-1;
		
		if(ok[12]&&vis[temp]==0){
			que.push(point(temp,tp.step+1));
		//	vis[temp]=1;
		}
		
		if(ok[13]){
			
			for(int i=1;i<=10;i++)
			for(int j=1;j<=10;j++){
				int x=i%10;
				int y=j%10;
				
				if(ok[i]&&ok[j]&&vis[x*10+y]==0){
					que.push(point(x*10+y,tp.step+3));
		//			vis[x*10+y]=1;
				}	
			}
			
		}
		
		
	}
	
	
	if(ans==10000)
	ans= -1;
}


int main(){

	for(int i=1;i<=3;i++)
		cin>>ok[i];
		
	cin>>ok[11];
	for(int i=4;i<=6;i++)
		cin>>ok[i];
	cin>>ok[12];
	for(int i=7;i<=9;i++)
		cin>>ok[i];
	cin>>ok[13];
	cin>>ok[10];
		
	int X,Y;
	cin>>X>>Y;
	
	bfs(X,Y);
	cout<<ans<<endl;
		
	
	return 0;
}