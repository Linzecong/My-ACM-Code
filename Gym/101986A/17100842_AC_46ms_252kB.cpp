#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define EPS 1e-8
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
const double pi = acos(-1.0);
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
inline void write(ll a){
    if (a<0) putchar('-'),a=-a;
    if (a>=10) write(a/10); putchar(a%10+'0');
}
const int MAX_N=55;
const ll mod=6597069766657;
ll C(int n,int m){
	ll res1=1,res2=1,t=1;
	while(t<=m){
		res1*=(n-t+1);
		res2*=t;
		t++;
		ll g=__gcd(res1,res2);
		res1/=g,res2/=g;
	}
	return res1;
}
ll l,k,ans=0;
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	scanf("%lld%lld",&l,&k);
	for(int i=1;2*i-1<=l;i++){
		for(int j=0;j<=i;j++){
			if(j*k+(i-j)+i-1>l){
				break;
			}else{
				ans+=C(i,j);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

