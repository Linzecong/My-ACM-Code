#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=2e3+5;
struct node{
	int l,r,id,c;
	bool operator <(const node&a)const{
		return l<a.l;
	}
}a[maxn];
vector<int>b;
int dp[maxn][1025];
int n,l;
int main()
{
	int cnt=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&l);
		for (int j=1;j<=l;j++)
		{
			cnt++;
			scanf("%d%d%d",&a[cnt].l,&a[cnt].r,&a[cnt].c);
			b.push_back(a[cnt].l);
			b.push_back(a[cnt].r);
			a[cnt].id=i-1;
		}
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	int M=b.size();
	for (int i=1;i<=cnt;i++)
	{
		a[i].l=lower_bound(b.begin(),b.end(),a[i].l)-b.begin()+1;
		a[i].r=lower_bound(b.begin(),b.end(),a[i].r)-b.begin()+1;
		//cout << a[i].l << ' ' << a[i].r << endl;
	}
	int u=(1<<n)-1,index=1,ans=0;
	sort(a+1,a+1+cnt);
	int w,o;
	for (int i=1;i<=M;i++)
	{
		for (int j=0;j<=u;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j]);
			if (!dp[i][j]&&j!=0) continue;
		/*	if (dp[i][j])
				cout << i << ' ' << j <<  ' ' << dp[i][j] << endl;*/
			w=index;
			while (a[index].l==i)
			{
				dp[a[index].r][j|(1<<a[index].id)]=max(dp[a[index].r][j|(1<<a[index].id)],dp[i][j]+a[index].c);
				index++;
			}
			o=index;
			index=w;
		}
		index=o;
		ans=max(ans,dp[i][u]);
	}
	if (ans==0) cout << -1 ;
	else cout << ans ;
}/*
3
4 1 3 100 4 6 90 7 8 95 9 10 90
1 7 8 13
2 2 5 231 6 7 525*/