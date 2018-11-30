#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Query
{
	int type;
	int id;
	int val;
	bool operator<(const Query &b) const
	{
		if (id == b.id)
			return type < b.type;
		return id < b.id;
	}
} q[200005];
int qn;

int ans[200005];
int an;

Query tmp[200005];
void CDQ(int l, int r)
{
	if (r <= l + 1)
		return;
	int m = (l + r) / 2;
	CDQ(l, m);
	CDQ(m, r);
	int sum = 0;
	int i = l, j = m, k = 0;
	while (i < m && j < r)
	{
		if (q[i] < q[j])
		{
			if (q[i].type == 1)
				sum += q[i].val;
			tmp[k++] = q[i++];
		}
		else
		{
			if (q[j].type == 2)
				ans[q[j].val] -= sum;
			else if (q[j].type == 3)
				ans[q[j].val] += sum;
			tmp[k++] = q[j++];
		}
	}

	while (i < m)
		tmp[k++] = q[i++];
	while (j < r)
	{
		if (q[j].type == 2)
			ans[q[j].val] -= sum;
		else if (q[j].type == 3)
			ans[q[j].val] += sum;
		tmp[k++] = q[j++];
	}
	for (int i = 0; i < k; i++)
		q[i + l] = tmp[i];
}

char str[200];
int main()
{
	int T;
	scanf("%d", &T);
	int N;
	int ttt=1;
	while (T--)
	{
		memset(ans,0,sizeof(ans));
		qn=0;
		an=0;
		printf("Case %d:\n",ttt++);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			q[qn].id = i;
			q[qn].type = 1;
			scanf("%d", &q[qn].val);
			qn++;
		}

		while(1){
			
			scanf("%s", str);
			if(str[0]=='E')
				break;
			if(str[0]=='A'){
				q[qn].type = 1;
				scanf("%d%d", &q[qn].id, &q[qn].val);
			}
			else if(str[0]=='S'){
				q[qn].type = 1;
				scanf("%d%d", &q[qn].id, &q[qn].val);
				q[qn].val=-q[qn].val;
			}
				
			else if(str[0]=='Q')
			{
				int l, r;
				scanf("%d%d", &l, &r);
				q[qn].type=2;
				q[qn].id = l - 1;
				q[qn].val = an;
				qn++;
				q[qn].type = 3;
				q[qn].id = r;
				q[qn].val = an;
				an++;
			}
			qn++;
		}


		CDQ(0, qn);
		for (int i = 0; i < an; i++)
			printf("%d\n", ans[i]);
			
	}

	return 0;
}
