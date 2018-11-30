#include <iostream>
#include <cstring>
#include <map>
using namespace std;
long long u,v;
map<long long,int>M;
long long cnt;
void gcd(long long a,long long b){
	if (b==0){
		cnt++;
		return;
	}
	long long c=a/b;
	cnt+=c;
	gcd(b,a%b);
}
int main(){
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		scanf("%lld%lld",&u,&v);
		if (u<v) swap(u,v);
		if (u==0||v==0){
			if (u==0&&v==0)
				printf("Case #%d: 1\n",Case);
			else printf("Case #%d: 2\n",Case);
			continue;
		}
		cnt=0;
		gcd(u,v);/*
		M.clear();
		M[u]=1;M[v]=1;
		while (u!=0&&v!=0){
			long long w=abs(u-v);
			u=v;
			v=w;
			M[w]=1;
		}
		cout << M.size() << endl;*/
		printf("Case #%d: %lld\n",Case,cnt);
	}
}