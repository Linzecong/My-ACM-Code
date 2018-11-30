#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 400010;
typedef long long ll;

int sta[MAXN];
int ch[MAXN][2];
int fa[MAXN];
int rev[MAXN];
int v[MAXN];
int N, M, T;
int mn[MAXN];
int et[MAXN];
int tp;
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

inline int isr(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
inline int isl(int x){return ch[fa[x]][1]==x;}

inline void upd(int x){
  if(!x) return; mn[x]=x; v[x]=x>N;
  if(ch[x][0]) v[x]+=v[ch[x][0]],mn[x]=et[mn[x]]<et[mn[ch[x][0]]]?mn[x]:mn[ch[x][0]];
  if(ch[x][1]) v[x]+=v[ch[x][1]],mn[x]=et[mn[x]]<et[mn[ch[x][1]]]?mn[x]:mn[ch[x][1]];
}

inline void pushdown(int x){
  if(!(x&&rev[x])) return;
  swap(ch[x][0],ch[x][1]);
  if(ch[x][0]) rev[ch[x][0]]^=1;
  if(ch[x][1]) rev[ch[x][1]]^=1;
  rev[x]=0;
}

inline void rot(int x){
  int y=fa[x],z=fa[y],lor=isl(x);
  if(!isr(y)) ch[z][ch[z][1]==y]=x; fa[x]=z;
  if(ch[y][lor]=ch[x][lor^1]) fa[ch[y][lor]]=y;
  fa[ch[x][lor^1]=y]=x; upd(y); upd(x);
}

inline void splay(int x){
  sta[tp=1]=x;
  for(int i=x;!isr(i);i=fa[i]) sta[++tp]=fa[i];
  for(;tp;--tp) pushdown(sta[tp]);
  for(;!isr(x);rot(x))if(!isr(fa[x])) rot(isl(fa[x])^isl(x)?x:fa[x]);
}

inline void access(int x){
  int t=0;
  for(;x;x=fa[x])
    splay(x),ch[x][1]=t,t=x,upd(x);
}

inline void reverse(int x){
  access(x); splay(x); rev[x]^=1;
}

inline void link(int x,int y){
  reverse(x);fa[x]=y; access(x);
}

inline void cut(int x,int y){
  reverse(x); access(y); splay(y);
  fa[x]=ch[y][0]=0; 
}

//找到原树上的根
//具体实现：首先Access这个点，然后在Splay树中将这个点转到根
//由于Splay树按照深度为关键字排序，所以不断地向左子树寻找，就可以找到深度最小的根。
int find_root(int x)
{
    access(x);
    splay(x);
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
    reverse(x);
    access(y);
    splay(y);
    return w ? v[ch[y][0]] : mn[ch[y][0]];
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
            cut(in[x - N].u, in[x - N].id);
            cut(in[x - N].v, in[x - N].id);
            link(k.u, k.id);
            link(k.v, k.id);
        }
    }
    else
    {
        link(k.u, k.id);
        link(k.id, k.v);
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
            cut(k.u, k.id);
            cut(k.v, k.id);
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