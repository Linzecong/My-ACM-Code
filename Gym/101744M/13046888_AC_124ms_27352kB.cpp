#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;

char maze[5005][5005];
char str[1005005];
int main(){
	
	int N,M;
	cin>>N>>M;
	string temp;
	int cnt=0;
	for(int i=0;i<N;i++){
		cin>>temp;
		if(i%2==0){
			for(int i=0;i<M;i++)
				str[cnt++]=temp[i];
		}
		else{
			for(int i=0;i<M;i++)
				str[cnt++]=temp[M-i-1];
		}
	}
	
	
	//cout<<str<<endl;
	
	int ans=0;
	int cur=0;
	for(int i=0;i<cnt;i++){
		if(str[i]=='.'){
			cur++;
			ans=max(ans,cur);
		}
		else{
			if(str[i]=='L'){
				cur=0;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

