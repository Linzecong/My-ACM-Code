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

int L[100005];
ll sum[100005];

int main()
{
	IOS;
	int T;
	cin>>T;
	for(int qqq=1;qqq<=T;qqq++){
		ll A,B,N;
		cin>>A>>B>>N;
		for(int i=1;i<=A;i++){
			cin>>L[i];
			sum[i]=sum[i-1]+L[i];
		}
			
		
		ll curA=A;
		ll curB=B;
		
		ll la=0;
		ll lb=0;
		
		while((curA!=la||curB!=lb)&&N){
			N--;
			//cout<<curA<<" "<<curB<<endl;
			la=curA;
			lb=curB;
			
			int i=upper_bound(sum+1,sum+A+1,curA)-sum-1;
			//cout<<i<<endl;
			
			curB=curA-sum[i];
			if(curB==0){
				curB=sum[i]-sum[i-1];
				curA=i;
			}
			else
				curA=i+1;	
		}
		cout<<"Case #"<<qqq<<": "<<curA<<"-"<<curB<<endl;
		
		
		
		
	}
	
	
	return 0;
}














