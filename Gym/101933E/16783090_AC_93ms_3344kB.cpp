#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,m,d,k;
int cnta[10],cntb[10];
double dp[500][500];
int num[500][500];
map<int,bool>M;
vector<int>b,c;
void get(int w)
{
//	cout << w << endl;
	for (int cnt=0;cnt<=6;cnt++)
	{
		cnta[cnt]=w%6;
		w/=6;
	}
}
int getidb(int w){return lower_bound(b.begin(),b.end(),w)-b.begin();}
int getidc(int w){return lower_bound(c.begin(),c.end(),w)-c.begin();}
int trans(int *a)
{
	int u=0;
	for (int i=6;i>=0;i--)
		u=u*6+a[i];
	return u;
}
void done()
{
	int sum=0;
	dp[b.size()-1][c.size()-1]=1;
	num[b.size()-1][c.size()-1]=d;
	for (int i=b.size()-1;i>=0;i--)
		for (int j=c.size()-1;j>=0;j--)
		{
			sum=0;
			if (num[i][j]==0) continue;
			get(b[i]);
			for (int k=1;k<=6;k++)
				sum+=cnta[k];
			get(c[j]);
			for (int k=1;k<=6;k++)
				sum+=cnta[k];
			get(b[i]);
			for (int k=1;k<=6;k++)
				if (cnta[k])
				{
					cnta[k]--;
					cnta[k-1]++;
					int u=trans(cnta);
					dp[getidb(u)][j]+=dp[i][j]*(cnta[k]+1)/sum;
					num[getidb(u)][j]=num[i][j]-1;
					cnta[k-1]--;
					cnta[k]++;
				}
			get(c[j]);
			for (int k=1;k<=6;k++)
				if (cnta[k])
				{
					cnta[k]--;
					cnta[k-1]++;
					int u=trans(cnta);
					dp[i][getidc(u)]+=dp[i][j]*(cnta[k]+1)/sum;
					num[i][getidc(u)]=num[i][j]-1;
					cnta[k-1]--;
					cnta[k]++;
				}
		}
}
void dfs(int *a)
{
	int u=trans(a);
	if (M[u]) return;
	b.push_back(u);
	M[u]=true;
	for (int i=1;i<=6;i++)
		if (a[i]>0)
		{
			a[i]--;
			a[i-1]++;
			dfs(a);
			a[i]++;
			a[i-1]--;
		}
}
int C;
double ans;
int main()
{
	cin >> n >> m >> d;
	for (int i=1;i<=n;i++)
		cin >> k,cnta[k]++,C+=k;
	for (int j=1;j<=m;j++)
		cin >> k,cntb[k]++,C+=k;
	if (d>=C)
	{
		cout << 1;
		return 0;
	}
	dfs(cnta);
	sort(b.begin(),b.end());
	c=b;
	b.clear();
	M.clear();
	dfs(cntb);
	sort(b.begin(),b.end());
	done();
	for (int j=0;j<c.size();j++){
		if (num[0][j]==0){
			ans+=dp[0][j];
		}
	}
	printf("%.7f",ans);
}