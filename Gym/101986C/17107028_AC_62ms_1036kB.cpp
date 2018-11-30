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
const int MAX_N=1e5+10;
ll a[MAX_N],t;
int n;
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	ll ma=0;
	scanf("%d%lld",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
		ma=max(ma,a[i]);
		t-=a[i];
		if(t>=0)
			printf("%lld\n",t/ma+2);
		else
			puts("1");
	}
	return 0;
}

