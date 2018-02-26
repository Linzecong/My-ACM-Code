#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N=550;
int G[MAX_N][MAX_N];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			G[i][j]+=max(G[i-1][j],G[i][j-1]);
		}
	}
	printf("%d\n",G[n][n]);
	return 0;
}