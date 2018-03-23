#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int maxn = 30005;
typedef long long int ll;

ll tree[maxn << 2]; //线段树数组，看你要存什么
ll A[maxn];         //原数组，下标1~n

//更新节点信息，这里是求最值
void pushup(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1]; //<<1为*2.<<1|1为*2+1，即左子树和右子树
}

//建树
void build(int l, int r, int rt)
{ //l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    if (l == r)
    {                    //若到达叶子结点
        tree[rt] = A[l]; //将该位置存原数组的值
        return;
    }
    int m = (l + r) >> 1; //>>1等于/2
    //递归建树
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt); //建完左右子树后，更新当前节点的值
}

//点修改，即A[L]=C，要同时修改相关区间的值，与建树同理，其实就是建树的过程
void update(int L, int C, int l, int r, int rt)
{
    if (l == r)
    { //若到达叶节点，则修改叶节点的值
        tree[rt] = C;
        return;
    }
    int m = (l + r) >> 1;

    //根据L判断是往哪个子树递归修改
    if (L <= m)
        update(L, C, l, m, rt << 1); //左子树
    else
        update(L, C, m + 1, r, rt << 1 | 1); //右子树

    pushup(rt); //子节点更新完了，那么可以更新自己了，即从下而上修改，建树同理
}

//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) //如果当前区间在查询区间内，直接返回当前存的值
        return tree[rt];

    int m = (l + r) >> 1;

    //累加求答案
    ll ANS = 0;
    if (L <= m) //如果左子区间与[L,R]有重叠，就递归左子树，右子树同理。
        ANS += query(L, R, l, m, rt << 1);
    if (R > m)
        ANS += query(L, R, m + 1, r, rt << 1 | 1);
    return ANS;
}

struct ask
{
    int l;
    int r;
    int i;
    ll ans;
} qry[100005];
bool cmp1(ask a, ask b)
{
    return a.r < b.r;
}
bool cmp2(ask a, ask b)
{
    return a.i < b.i;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        map<ll, int> vis;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &A[i]);
        build(1, n, 1);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &qry[i].l, &qry[i].r);
            qry[i].i = i;
        }

        sort(qry, qry + q, cmp1);
        int cur = 1;
        for (int i = 0; i < q; i++)
        {

            for (cur; cur <= qry[i].r; cur++)
            {
                if (vis[A[cur]])
                    update(vis[A[cur]], 0, 1, n, 1);
                vis[A[cur]] = cur;
            }
            qry[i].ans = query(qry[i].l, qry[i].r, 1, n, 1);
        }

        sort(qry, qry + q, cmp2);

        for (int i = 0; i < q; i++)
            printf("%lld\n", qry[i].ans);
    }

    return 0;
}
