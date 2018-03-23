#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int T;
int n;
int a[100005];
ll res[100005];
int main(){
	scanf("%d",&T);while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		/*
		t [] = 0
        t (x:xs) = x * (1 + t xs) + t xs
        */
        res[n] = 0;
        for(int i=n-1;i>=0;i--){
        	ll p1 = (1 + res[i+1])%MOD;
        	res[i] = ((a[i]*p1)%MOD+res[i+1])%MOD;
        }
        printf("%lld\n",res[0]);
	}
}