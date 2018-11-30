#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 400010;
typedef long long ll;

int Q[MAXN];
int ch[MAXN][2];
int fa[MAXN];
int rev[MAXN];
int siz[MAXN];
int N, M, T;
int mn[MAXN];
int et[MAXN];
struct edge
{
    int u, v;
    int b, e;
    int id;
    friend bool operator<(edge a, edge b)
    {
        return a.b < b.b;
    }
} in[MAXN << 2], out[MAXN << 2];

bool cmp(edge a, edge b)
{
    return a.e < b.e;
}

bool isroot(int rt)
{
    return ch[fa[rt]][0] != rt && ch[fa[rt]][1] != rt;
}

bool get(int x) { return ch[fa[x]][1] == x; }

void pushup(int x)
{
    if (!x)
        return;

    mn[x] = x;
    siz[x] = x > N;
    if (ch[x][0])
        siz[x] += siz[ch[x][0]], mn[x] = et[mn[x]] < et[mn[ch[x][0]]] ? mn[x] : mn[ch[x][0]];
    if (ch[x][1])
        siz[x] += siz[ch[x][1]], mn[x] = et[mn[x]] < et[mn[ch[x][1]]] ? mn[x] : mn[ch[x][1]];
}

//下推函数
void pushdown(int x)
{
    if (rev[x])
    {
        rev[ch[x][0]] ^= 1;
        rev[ch[x][1]] ^= 1;
        rev[x] ^= 1;
        swap(ch[x][0], ch[x][1]);
    }
}

//Splay旋转函数，通常无需修改
void Rotate(int x)
{
    int old = fa[x], oldf = fa[old], op = get(x);
    if (!isroot(old))
        ch[oldf][ch[oldf][1] == old] = x; //这一条一定要放在改变父子关系之前！在纯Splay中是放在后面的，因为直接看oldf是否为0可知old是否为根。
    ch[old][op] = ch[x][op ^ 1];
    fa[ch[x][op ^ 1]] = old; //但这里使用isroot，改变之后就不能判断了！
    ch[x][op ^ 1] = old;
    fa[old] = x;
    fa[x] = oldf;
    pushup(old);
    pushup(x);
}

//Splay函数，将rt变为某棵Splay树的根节点，通常无需修改
void Splay(int x)
{
    int tp = 1;
    Q[1] = x;
    for (int i = x; !isroot(i); i = fa[i])
        Q[++tp] = fa[i]; //对于LCT的判断是否是根节点，需要使用isroot，在纯Splay中使用的是fa，不要搞混！
    for (int i = tp; i; i--)
        pushdown(Q[i]);
    for (int FA; !isroot(x); Rotate(x))
    {
        FA = fa[x];
        if (!isroot(FA))
            Rotate(get(x) == get(FA) ? FA : x);
    }
}

//打通x到整个LCT的根的路径，即fa和ch都是正确的
void Access(int x)
{
    int t = 0;
    while (x)
    {
        Splay(x);
        ch[x][1] = t;
        pushup(x);
        t = x;
        x = fa[x];
    }
}
//把x变为整个LCT的根，先打通路径，然后把他变为他的Splay的根即可。
void Makeroot(int x)
{
    Access(x);
    Splay(x);
    rev[x] ^= 1;
}
//链接函数，先把x变为整个LCT的根（这时x才没有父亲，所以不能用Splay），然后再设置一个父亲即可
void Link(int x, int y)
{
    Makeroot(x);
    Makeroot(y);
    fa[x] = y;
    pushup(y);
}

//剪断函数，根据Splay原理，可以把x变为y的左节点，然后删除即可
void Cut(int x, int y)
{
    Makeroot(x);
    Access(y);
    Splay(y);
    if (ch[y][0] == x)
    {
        fa[x] = ch[y][0] = 0;
        pushup(y);
    }
}
//分割函数，即把x到y这条路径变为一颗Splay树，从而把区间查询变为树上节点查询（Splay原理）
void split(int x, int y)
{
    Makeroot(y);
    Access(x);
    Splay(x);
}

//找到原树上的根
//具体实现：首先Access这个点，然后在Splay树中将这个点转到根
//由于Splay树按照深度为关键字排序，所以不断地向左子树寻找，就可以找到深度最小的根。
int find_root(int x)
{
    Access(x);
    Splay(x);
    int now = x;
    while (ch[now][0])
        now = ch[now][0];
    return now;
}

//查询x到y之间是否已经有路径，直接查询所在的LCT的根是否相等即可
int isconnected(int x, int y)
{
    int rx, ry;
    rx = find_root(x);
    ry = find_root(y);
    return rx == ry;
}

int query(int x, int y, bool w)
{
    Makeroot(x);
    Access(y);
    Splay(y);
    return w ? siz[ch[y][0]] : mn[ch[y][0]];
}

int cnt = 0;
bool vis[MAXN];
void insert(edge k)
{
    if (k.u == k.v)
    {
        vis[k.id] = 1;
        cnt++;
        return;
    }
    et[k.id] = k.e;
    mn[k.id] = k.id;

    if (isconnected(k.u, k.v))
    {
        int x = query(k.u, k.v, 0);
        if (et[x] > et[k.id])
        {
            if (query(k.u, k.v, 1) & 1 ^ 1)
            {
                vis[k.id] = 1;
                cnt++;
            }
            else
                return;
        }
        else
        {
            if (query(k.u, k.v, 1) & 1 ^ 1)
            {
                vis[x] = 1;
                cnt++;
            }
            Cut(in[x - N].u, in[x - N].id);
            Cut(in[x - N].v, in[x - N].id);
            Link(k.u, k.id);
            Link(k.v, k.id);
        }
    }
    else
    {
        Link(k.u, k.id);
        Link(k.id, k.v);
    }
}

void del(edge k)
{
    if (vis[k.id])
    {
        vis[k.id] = 0;
        cnt--;
    }
    else
    {
        if (isconnected(k.u, k.id))
        {
            Cut(k.u, k.id);
            Cut(k.v, k.id);
        }
    }
}


int main()
{

    scanf("%d%d%d", &N, &M, &T);

    for (int i = 0; i <= N; i++)
        et[i] = 1 << 30;

    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d%d%d", &in[i].u, &in[i].v, &in[i].b, &in[i].e);
    }
    sort(in + 1, in + 1 + M);
    for (int i = 1; i <= M; i++)
        in[i].id = N + i;
    for (int i = 1; i <= M; i++)
        out[i] = in[i];

    sort(out + 1, out + 1 + M, cmp);

    int k = 1, j = 1;
    for (int i = 1; i <= T; i++)
    {
        while (in[j].b < i && j <= M)
            insert(in[j++]);
        while (out[k].e < i && k <= M)
            del(out[k++]);
        if (cnt)
            puts("No");
        else
            puts("Yes");
    }

    return 0;
}