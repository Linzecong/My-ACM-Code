#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX_N=1e5+10;
map<int,int> m;
void init(){
	ll sum=0;
	for(int i=1;i<MAX_N;i++){
		sum+=i;
		m[sum]=i+1;
	}
} 
int a,b,c,d,pos[MAX_N];
int main(){
	init();
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==0&&b==0&&c==0&&d==0){
		puts("1");
		return 0;
	}
	ll cnt0=m[a],cnt1=m[d];
	if(cnt0==0){
		if(b||c){
			cnt0=1;
		}
	}
	if(cnt1==0){
		if(b||c){
			cnt1=1;
		}
	}
	if(cnt1==cnt0&&cnt0==0){
		puts("impossible");
		return 0;
	}
	if(cnt0*cnt1<b||cnt0*cnt1<c){
		puts("impossible");
		return 0;
	}
	string s;
	if(cnt0){
		int left=cnt1-b/cnt0;
		if(b%cnt0){
			left--;
		}
		for(int i=0;i<left;i++){
			s.push_back('1');
		}
		for(int i=1;i<=cnt0;i++){
			s.push_back('0');
			if(i==b%cnt0){
				s.push_back('1');
			}
		}
		for(int i=0;i<b/cnt0;i++){
			s.push_back('1');
		}
		ll cc=0,cnt=0;
		for(auto x:s){
			if(x=='0'){
				cc+=cnt;
			}else{
				cnt++;
			}
		}
		//cout<<s<<endl;
		if(cc!=c){
			puts("impossible");
			return 0;
		}
		cout<<s<<endl;
	}else{
		for(int i=0;i<cnt1;i++){
			putchar('1');
		}
	}
	return 0;
}