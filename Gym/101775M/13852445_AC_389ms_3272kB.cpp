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
typedef pair<long,long> pll;
const double pi = acos(-1.0);
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
inline void write(ll a)
{
    if (a<0) putchar('-'),a=-a;
    if (a>=10) write(a/10); putchar(a%10+'0');
}
int main()
{
	IOS;
	int T;
	cin>>T;
	for(int qqq=1;qqq<=T;qqq++){
		int gp,ep,qp,sp,fp;
		cin>>gp>>ep>>qp>>sp>>fp;
		ll N;
		cin>>N;
		ll sum=0;
		ll num;
		for(int i=0;i<N;i++){
			cin>>num;
			
			if(num<=48)
				sum+=gp;
			else if(num<=48+8)
				sum+=ep;
			else if(num<=48+8+4)
				sum+=qp;
			else if(num<=48+8+4+2)
				sum+=sp;
			else if(num<=48+8+4+2+1)
				sum+=fp;
			
			
		}
		
		sum*=10000;
		cout<<"Case #"<<qqq<<": "<<sum<<endl;
		
	} 
	
	
	
	
	return 0;
}



























