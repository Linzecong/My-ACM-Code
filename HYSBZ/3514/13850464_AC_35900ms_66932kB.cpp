#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long int ll;
const int MAXN = 400095;

struct edge
{
    int x, y;
} e[MAXN];

int Q[MAXN];	 //Splay用栈
int ch[MAXN][2]; //树节点
int fa[MAXN];	//节点的父亲

int val[MAXN]; //边的值
int mn[MAXN];  //最小值所在的边的编号

int A[MAXN];   //每一个节点的值
int rev[MAXN]; //翻转标记，维护Splay用

//判断是否是某个Splay的根节点，旋转用
bool isroot(int rt)
{
    return ch[fa[rt]][0] != rt && ch[fa[rt]][1] != rt;
}
bool get(int x) { return ch[fa[x]][1] == x; }

//上传函数，维护节点信息
void pushup(int x)
{
    int l = ch[x][0];
    int r = ch[x][1];

    mn[x] = x;
    if (val[mn[l]] < val[mn[x]])
        mn[x] = mn[l];
    if (val[mn[r]] < val[mn[x]])
        mn[x] = mn[r];
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
    fa[x] = y;
}
//剪断函数，根据Splay原理，可以把x变为y的左节点，然后删除即可
void Cut(int x, int y)
{
    Makeroot(x);
    Access(y);
    Splay(y);
    if (ch[y][0] == x)
        fa[x] = ch[y][0] = 0;
}
//分割函数，即把x到y这条路径变为一颗Splay树，从而把区间查询变为树上节点查询（Splay原理）
void split(int x, int y)
{
    Makeroot(y);
    Access(x);
    Splay(x);
}
int find_root(int x)
{
    int now = x;
    while (ch[now][0])
        now = ch[now][0];
    return now;
}
//查询x到y之间是否已经有路径，直接查询所在的LCT的根是否相等即可
int isconnected(int x, int y)
{
    int rx, ry;
    Access(x);
    Splay(x);
    rx = find_root(x);
    Access(y);
    Splay(y);
    ry = find_root(y);
    return rx == ry;
}

void query(int x, int y, int &b)
{
    split(x, y);
    b = mn[x];
}

int num[MAXN];
int sum[MAXN*10], rs[MAXN*10], ls[MAXN*10];
int root[MAXN];
int sz = 0;
void update(int l,int r,int x,int &y,int val)
{
    y=++sz;
    sum[y]=sum[x]+1;
    if(l==r)return;
    ls[y]=ls[x];rs[y]=rs[x];
    int mid=(l+r)>>1;
    if(val<=mid)update(l,mid,ls[x],ls[y],val);
    else update(mid+1,r,rs[x],rs[y],val);
}
int query(int l,int r,int x,int y,int val)
{
    if(r==val)return sum[y]-sum[x];
    int mid=(l+r)>>1;
    if(val<=mid)return query(l,mid,ls[x],ls[y],val);
    else return sum[ls[y]]-sum[ls[x]]+query(mid+1,r,rs[x],rs[y],val);
}

int main()
{

    int N, M, Q, T;
    scanf("%d%d%d%d", &N, &M, &Q, &T);
    for (int i = 1; i <= M; i++)
        scanf("%d%d", &e[i].x, &e[i].y);

    for (int i = 1; i <= N; i++)
        mn[i] = i, val[i] = 0x3f3f3f3f;
    val[0]=0x3f3f3f3f;

    int tot = N;

    for (int i = 1; i <= M; i++)
    {
        int b;
        int x = e[i].x;
        int y = e[i].y;
        if (x == y)
        {
            num[i] = i;
            continue;
        }
        if (isconnected(x, y))
        {
            query(x, y, b);
            int temp = val[b];
            num[i] = temp;
            Cut(b, e[temp].x); //相当于把边删除
            Cut(b, e[temp].y);
        }

        tot++;
        mn[tot] = tot;
        val[tot] = i;
        Link(tot, x);
        Link(tot, y);

    }
    for(int i=1;i<=M;i++)
        update(0,M,root[i-1],root[i],num[i]);

    int l, r;
    int lans = 0;
    while (Q--)
    {
        scanf("%d%d", &l, &r);
        if (T)
        {
            l ^= lans;
            r ^= lans;
        }
        lans = N - query(0, M, root[l - 1], root[r], l - 1);
        printf("%d\n", lans);
    }

    return 0;
}
