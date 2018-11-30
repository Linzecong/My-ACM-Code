#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define N 400010

using namespace std;

int n,m,t,tp,cnt;
int fa[N],ch[N][2],v[N],vis[N],rev[N],sta[N],mn[N],t1[N];
struct edge{
  int x,y,b,e,g;
  friend bool operator <(edge a,edge b){
    return a.b<b.b;
  }
}E[N<<2],D[N<<2];

inline bool cmp(edge a,edge b){return a.e<b.e;}

inline char C(){
  static char buf[100000],*p1=buf,*p2=buf;
  if(p1==p2){
    p2=(p1=buf)+fread(buf,1,100000,stdin);
    if(p1==p2) return EOF;
  }
  return *p1++;
}

inline void reaD(int &x){
  char Ch=C();x=0;
  for(;Ch>'9'||Ch<'0';Ch=C());
  for(;Ch>='0'&&Ch<='9';x=x*10+Ch-'0',Ch=C());
}

inline int isr(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
inline int isl(int x){return ch[fa[x]][1]==x;}

inline void upd(int x){
  if(!x) return; mn[x]=x; v[x]=x>n;
  if(ch[x][0]) v[x]+=v[ch[x][0]],mn[x]=t1[mn[x]]<t1[mn[ch[x][0]]]?mn[x]:mn[ch[x][0]];
  if(ch[x][1]) v[x]+=v[ch[x][1]],mn[x]=t1[mn[x]]<t1[mn[ch[x][1]]]?mn[x]:mn[ch[x][1]];
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

inline int query(int x,int y,int w){
  reverse(x); access(y); splay(y);
  return w?v[ch[y][0]]:mn[ch[y][0]];
}

inline int fifa(int x){
  access(x); splay(x);
  while(ch[x][0]) x=ch[x][0];
  return x;
}

inline void Insert(edge k){
  if(k.x==k.y){vis[k.g]=1;cnt++;return ;}
  t1[k.g]=k.e; mn[k.g]=k.g;
  if(fifa(k.x)==fifa(k.y)){
    int x=query(k.x,k.y,0);
    if(t1[x]>t1[k.g]) if(query(k.x,k.y,1)&1^1) vis[k.g]++,cnt++; else return ;
    else{
      if(query(k.x,k.y,1)&1^1) vis[x]++,cnt++;
      cut(E[x-n].x,E[x-n].g); cut(E[x-n].y,E[x-n].g);
      link(k.x,k.g);
      link(k.y,k.g);
    }
  }
  else link(k.x,k.g),link(k.g,k.y);
}

inline void del(edge k){
  if(vis[k.g]) vis[k.g]=0,cnt--;
  else if(fifa(k.x)==fifa(k.g))cut(k.x,k.g),cut(k.y,k.g);
}

int main(){
  reaD(n);reaD(m);reaD(t);
  for(int i=0;i<=n;i++) t1[i]=1<<30;
  for(int i=1;i<=m;i++) reaD(E[i].x),reaD(E[i].y),reaD(E[i].b),reaD(E[i].e);
  sort(E+1,E+1+m);
  for(int i=1;i<=m;i++) E[i].g=i+n;
  for(int i=1;i<=m;i++) D[i]=E[i];
  sort(D+1,D+1+m,cmp);
  for(int i=1,j=1,k=1;i<=t;i++){
    while(E[j].b<i&&j<=m) Insert(E[j++]);
    while(D[k].e<i&&k<=m) del(D[k++]);
    if(cnt) puts("No");else puts("Yes");
  }
}