#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>
 
using namespace std;
 
#define LL long long
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int N = 50000 + 5;
const int demension = 5;//二维
 
struct node
{
	int pos[demension];
	int ma[demension], mi[demension];
	int l, r;
	LL dis;
	bool operator<(const node &a)const
	{
		return dis < a.dis;
	}
}a[N], x, pre, ans[15];
priority_queue<node>q;
int cmpDem;//以第cmpDem维作比较
int root, n, qq, K, m, Size;
 
bool cmp(const node &a, const node&b)
{
	return a.pos[cmpDem] < b.pos[cmpDem];
}
 
void Merge(int k)
{
	for (int i = 0; i < K; i++)
	{
		if (a[k].l)
		{
			a[k].ma[i] = max(a[k].ma[i], a[a[k].l].ma[i]);
			a[k].mi[i] = min(a[k].mi[i], a[a[k].l].mi[i]);
		}
		if (a[k].r)
		{
			a[k].ma[i] = max(a[k].ma[i], a[a[k].r].ma[i]);
			a[k].mi[i] = min(a[k].mi[i], a[a[k].r].mi[i]);
		}
	}
}
 
LL dis(int k)
{
	LL dis = 0;
	for (int i = 0; i < K; i++)
	{
		if (x.pos[i] < a[k].mi[i]) dis += 1LL * (a[k].mi[i] - x.pos[i])*(a[k].mi[i] - x.pos[i]);
		if (x.pos[i] > a[k].ma[i]) dis += 1LL * (x.pos[i] - a[k].ma[i])*(x.pos[i] - a[k].ma[i]);
	}
	return dis;
}
 
int build(int l, int r, int k)
{
	if (l > r) return 0;
	int mid = (l + r) / 2;
	//以第mid个元素为中心排序
	cmpDem = k;
	nth_element(a + l, a + mid, a + r + 1, cmp);
	//左右子树
	a[mid].l = build(l, mid - 1, (k + 1) % demension);
	a[mid].r = build(mid + 1, r, (k + 1) % demension);
	Merge(mid);
	return mid;
}
 
void query(int k)
{
	a[k].dis = 0;
	for (int i = 0; i < K; i++) a[k].dis += 1LL * (x.pos[i] - a[k].pos[i])*(x.pos[i] - a[k].pos[i]);
	if (Size < m) q.push(a[k]), Size++;
	else
	{
		pre = q.top();
		if (pre.dis > a[k].dis) q.pop(), q.push(a[k]);
	}
	LL dl = a[k].l ? dis(a[k].l) : INF, dr = a[k].r ? dis(a[k].r) : INF;
	if (min(dl, dr) >q.top().dis&&Size >= m) return;
	if (dl < dr)
	{
		if (Size < m || dl < q.top().dis) query(a[k].l);
		if (Size < m || dr < q.top().dis) query(a[k].r);
	}
	else
	{
		if (Size < m || dr < q.top().dis) query(a[k].r);
		if (Size < m || dl < q.top().dis) query(a[k].l);
	}
}
 
int main()
{
	while (~scanf("%d%d", &n, &K))
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < K; j++) scanf("%d", &a[i].pos[j]), a[i].mi[j] = a[i].ma[j] = a[i].pos[j];
			a[i].l = a[i].r = 0;
		}
		root = build(1, n, 0);
		scanf("%d", &qq);
		while (qq--)
		{
			for (int i = 0; i < K; i++) scanf("%d", &x.pos[i]);
			scanf("%d", &m);
			Size = 0;
			query(root);
			printf("the closest %d points are:\n", m);
			for (int j = m; j >= 1; j--)
			{
				ans[j] = q.top();
				q.pop();
			}
			for (int i = 1; i <= m; i++)
			{
				for (int j = 0; j < K - 1; j++) printf("%d ", ans[i].pos[j]);
				printf("%d\n", ans[i].pos[K - 1]);
			}
		}
	}
	return 0;
}
