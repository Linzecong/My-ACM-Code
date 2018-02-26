#include<iostream>
#include<math.h>
#include<deque>
#include<stdio.h>

using namespace std;

int n,m;

struct point{
	int val;
	int step;
};

bool visit[200050];

int main(){
	
	while(cin>>n>>m){
	
	int res=99999999;
	point a;
	a.val=n;
	a.step=0;
	
	deque<point> que;
	que.push_back(a);
	
	for(int i=0;i<200050;i++)
	visit[i]=0;
	

	
	while(!que.empty()){
		
		point temp=que.front();
		que.pop_front();
		
		if(temp.val==m){
			res=min(res,temp.step);
			continue;
		}
		
		if(temp.val-1>=0&&visit[temp.val-1]==0){
			point tt=temp;
			tt.val--;
			tt.step++;
			que.push_back(tt);
			visit[temp.val-1]=1;
		}
		
		if(temp.val<m&&visit[temp.val+1]==0){
			point tt=temp;
			tt.val++;
			tt.step++;
			que.push_back(tt);
			visit[temp.val+1]=1;
		}
		
		if(temp.val<m&&visit[temp.val*2]==0){
			point tt=temp;
			tt.val*=2;
			tt.step++;
			que.push_back(tt);
			visit[temp.val*2]=1;
		}
		
		
	}
	
	
	cout<<res<<endl;
	
	
	
	
		
	}
	
	return 0;
}