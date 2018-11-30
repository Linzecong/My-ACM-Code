
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>
 
using namespace std;
 
#define LL long long
const int INF = 0x3f3f3f3f;
 
int n, a[1009], x[1009], ma[1009];
int vis[100009], ans;
 
int main()
{
	int t, cas = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int l = 1, r = 1;
		while (l <= n)
		{
			while (!vis[a[r]] && r <= n) vis[a[r]] = 1, r++;
			x[l] = r - l;
			vis[a[l]] = 0, l++;
		}
		ma[n + 1] = 0;
		for (int i = n; i >= 1; i--) ma[i] = max(ma[i + 1], x[i]);
		ans = ma[1];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= i + x[i] - 1; j++)
			{
				vis[a[j]] = 1;
				//if (j - i + 1 + ma[j + 1]<ans) continue;
				int l = j + 1, r = j + 1;
				while (l <= n)
				{
					//if (ans>j - i + 1 + ma[l]) break;
					r = max(l, r);
					while (!vis[a[r]] && r <= l + x[l] - 1) r++;
					ans = max(ans, j - i + 1 + r - l);
					l++;
				}
			}
			for (int j = i; j <= i + x[i] - 1; j++) vis[a[j]] = 0;
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}