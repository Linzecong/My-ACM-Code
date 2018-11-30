#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 100010;
typedef long long ll;

int Q[MAXN];
int ch[MAXN][2];
int fa[MAXN];
int rev[MAXN];
int siz[MAXN];


bool isroot(int rt)
{
    return ch[fa[rt]][0] != rt && ch[fa[rt]][1] != rt;
}

bool get(int x) { return ch[fa[x]][1] == x; }

void pushup(int rt)
{
    if (!rt)
        return;
    siz[rt] = siz[ch[rt][0]] + siz[ch[rt][1]] + 1;
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

int pre[20][MAXN],a[MAXN],n;
 
int go(int x,int len) {
     for (int i = 19; i >= 0; i--) {
          if ((len>>i)&1) x = pre[i][x];
     }
     return x ? x :n+1; //已经课跳出去，连接n+1
}
 
int main() {
    int t;
    scanf ("%d",&t);
    while(t--) {
        memset(ch,0,sizeof(ch));
           memset(fa,0,sizeof(fa));
           memset(siz,0,sizeof(siz));
           memset(rev,0,sizeof(rev));

        scanf ("%d",&n);
        for (int i  = 2; i <= n; i++) scanf ("%d",&pre[0][i]);
        for (int i = 1; i < 20; i++)
            for (int j = 1; j <= n; j++)
               pre[i][j] = pre[i-1][pre[i-1][j]];
        for (int i = 1; i <= n+1; i++) siz[i] = 1;
        for (int i = 1; i <= n; i++) {
            scanf ("%d",&a[i]);
            Link(i,go(i,a[i]));
        }
        int q;
        scanf ("%d",&q);
        while(q--) {
            int op,x,y;
            scanf ("%d%d",&op,&x);
            if (op == 1) {
                split(x,n+1);
                printf ("%d\n",siz[x]-1);
            }
            else{
                scanf ("%d",&y);
                Cut(x,go(x,a[x]));
                a[x] = y;
                Link(x,go(x,a[x]));
            }
        }
    }
    return 0;
}