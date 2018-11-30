#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
struct query
{
	int l;
	int r;
	int id;

} q[MAXN];
int block[MAXN];
bool cmp(query a, query b)
{
	if (block[a.l] == block[b.l])
		return a.r < b.r;
	return block[a.l] < block[b.l];
}

int a[MAXN];
int res[MAXN];
ll num[MAXN];
ll len[MAXN];
int N, M;

ll add(int a)
{
	ll temp = num[a] * num[a];
	num[a]++;
	return num[a] * num[a] - temp;
}
ll remove(int a)
{
	ll temp = num[a] * num[a];
	num[a]--;
	return num[a] * num[a] - temp;
}

void solve()
{
	int l = 1;
	int r = 1;
	num[a[1]] = 1;
	int ans = 1;

	for (int i = 0; i < M; i++)
	{
		while (q[i].r > r)
			r++, ans += add(a[r]);
		while (q[i].r < r)
			ans += remove(a[r]), r--;
		while (q[i].l > l)
			ans += remove(a[l]), l++;
		while (q[i].l < l)
			l--, ans += add(a[l]);
		res[q[i].id] = ans;
	}
}

int main()
{

	scanf("%d%d", &N, &M);
	int blocksize = sqrt(N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		num[a[i]] = 0;
		block[i] = (i - 1) / blocksize + 1;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
		len[i] = q[i].r - q[i].l + 1;
	}
	sort(q, q + M, cmp);
	solve();
	for (int i = 0; i < M; i++)
	{
		ll g = gcd(res[i] - len[i], len[i] * (len[i] - 1));
		printf("%lld/%lld\n", (res[i] - len[i]) / g, len[i] * (len[i] - 1) / g);
	}
	return 0;
}
