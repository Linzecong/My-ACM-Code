#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+5;
bool bulb[maxn];
int a[maxn][maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(bulb,false,sizeof(bulb));
	int l,w;
	scanf("%d",&l);
	for (int i=1;i<=l;i++)
	{
		scanf("%d",&w);
		bulb[w]=true;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		for (int j=1;j<=a[i][0];j++)
			scanf("%d",&a[i][j]);
	}
	int cnt=2;
	int ans=0;
	bool flag;
	while (cnt--)
	{
		for (int i=1;i<=n;i++)
		{
			ans++;
			for (int j=1;j<=a[i][0];j++)
				bulb[a[i][j]]^=1;
			flag=true;
			for (int j=1;j<=m;j++)
				if (bulb[j])
				{
					flag=false;
					break;
				}
			if (flag)
				break;
		}
		if (flag) break;
	}
	if (flag)
		cout << ans << endl;
	else
		cout << -1;
}/*
6 3
1 2 
3 1 2 3
2 1 3
2 1 2
2 2 3
1 2
3 1 2 3



*/