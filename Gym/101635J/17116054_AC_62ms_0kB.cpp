#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long cnt1[3];
long long cnt2[3];
int p,n;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&p);
		cnt1[i%3]+=p;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&p);
		cnt2[i%3]+=p;
	}
	long long w=cnt1[0]*cnt2[0]+cnt1[1]*cnt2[2]+cnt1[2]*cnt2[1];
	long long p=cnt1[1]*cnt2[1]+cnt1[0]*cnt2[2]+cnt1[2]*cnt2[0];
	long long y=cnt1[2]*cnt2[2]+cnt1[1]*cnt2[0]+cnt1[0]*cnt2[1];
	printf("%lld %lld %lld",y,p,w);
} 