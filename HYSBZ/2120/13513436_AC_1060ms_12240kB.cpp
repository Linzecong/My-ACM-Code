#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

struct Query
{
	int l;
	int r;
	int id;
	int cti;
} q[MAXN];
int qn;

struct Change
{
	int x;
	int val;
} cha[MAXN];
int cn;

int block[MAXN], blocksize;
bool cmp(Query a, Query b)
{
	if (block[a.l] != block[b.l])
		return a.l < b.l;
	//if (block[a.r] != block[b.r])
	//	return a.r < b.r;
	return a.cti < b.cti;
}

int a[MAXN];
int N, M;
int ans[MAXN];
int res = 0;
int vis[1000005];
void add(int num)
{
	if (vis[a[num]] == 0)
		res++;
	vis[a[num]]++;
}
void remove(int num)
{
	if (vis[a[num]] == 1)
		res--;
	vis[a[num]]--;
}
void change(int ti, int l, int r)
{
	if (cha[ti].x >= l && cha[ti].x <= r)
		remove(cha[ti].x);
	swap(cha[ti].val, a[cha[ti].x]);
	if (cha[ti].x >= l && cha[ti].x <= r)
		add(cha[ti].x);
}

void solve()
{
	int r = 0;
	int l = 0;
	int now = 0;
	for (int i = 0; i < qn; i++)
	{
		while (q[i].r > r)
			r++, add(r);
		while (q[i].r < r)
			remove(r), r--;
		while (q[i].l > l)
			remove(l), l++;
		while (q[i].l < l)
			l--, add(l);

		while (now > q[i].cti)
			change(now, l, r), now--;
		while (now < q[i].cti)
			now++, change(now, l, r);

		ans[q[i].id] = res;
	}
}

int main()
{

	scanf("%d%d", &N, &M);
	blocksize = sqrt(N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		block[i] = (i - 1) / blocksize + 1;
	}

	char op[5];
	int x, y;

	for (int i = 0; i < M; i++)
	{
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'Q')
		{
			q[qn].l = x;
			q[qn].r = y;
			q[qn].cti = cn;
			q[qn].id = qn;
			qn++;
		}
		else
		{
			cn++;
			cha[cn].x = x;
			cha[cn].val = y;
		}
	}

	sort(q, q + qn, cmp);

	solve();
	for (int i = 0; i < qn; i++)
		printf("%d\n", ans[i]);

	return 0;
}
