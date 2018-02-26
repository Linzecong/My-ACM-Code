#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long int ll;

vector<int> chs[2000005];
int num[2000005];
int num2[2000005];

int vis[2000005];

int main(){
	
	int C,P,X,L;
	
	cin>>C>>P>>X>>L;
	
	int a,b;
	for(int i=0;i<P;i++){
		scanf("%d%d",&a,&b);
		
		
		num[a]++;
		num[b]++;
		
		num2[a]++;
		num2[b]++;
		chs[a].push_back(b);
		chs[b].push_back(a);
	}
	
	queue<int> leave;
	leave.push(L);
	
	while(!leave.empty()){
		int tp=leave.front();
		leave.pop();
		if(vis[tp])
		continue;
		
		num[tp]=0;
		vis[tp]=1;
		for(int i=0;i<chs[tp].size();i++){
			num[chs[tp][i]]--;
			
			if(num[chs[tp][i]]*2<=num2[chs[tp][i]])
			leave.push(chs[tp][i]);	
		}	
	}
	
	
	if(vis[X]==0)
	cout<<"stay"<<endl;
	else
	cout<<"leave"<<endl;
	
	
	return 0;
}



