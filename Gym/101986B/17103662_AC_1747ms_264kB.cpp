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
const int MAX_N=20;
int ans=0,n;
map<pii,int> mp;
struct node{
	int x,y;
}a[MAX_N];
bool vis[MAX_N];
pii get_pair(int i,int j){
	if(a[i].x==a[j].x){
		return pii{1,0};
	}else if(a[i].y==a[j].y){
		return pii{0,1};
	}else{
		ll A=a[i].x-a[j].x,B=a[j].y-a[i].y;
		ll g=__gcd(A,B);
		A/=g,B/=g;
		if(A<0){
			A=-A,B=-B;
		}
		return pii{A,B};
	}
}
void dfs(int pos,int step){
	
	for(int i=pos+1;i<n;i++){
		if(!vis[i]){
			vis[i]=true;
			pii tmp=get_pair(pos,i);
			mp[tmp]++;
			for(int j=pos+1;j<n;j++){
				if(!vis[j]){
					vis[j]=true;
					dfs(j,step+1);
					vis[j]=false;
					break;
				}
			}	
			if(step*2==n){
				int tmp=0;
				for(auto x:mp){
					tmp+=x.second*(x.second-1)/2;
					/*if(x.second!=0){
						cout<<x.first.first<<" test "<<x.first.second<<endl;
					}*/	
				}
				ans=max(ans,tmp);
				//cout<<endl;
			}
			vis[i]=false;
			mp[tmp]--;
			if(mp[tmp]==0){
				mp.erase(tmp);
			}
		}
	}

}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	mem(vis,0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	vis[0]=true;
	dfs(0,1);
	printf("%d\n",ans);
	return 0;
}

