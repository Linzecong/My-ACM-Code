#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
const int maxn = 2e5+10;
 
struct LCT {
      int fa[maxn],ch[maxn][2],rev[maxn],sz[maxn],q[maxn];
      void init() {
           memset(ch,0,sizeof(ch));
           memset(fa,0,sizeof(fa));
           memset(sz,0,sizeof(sz));
           memset(rev,0,sizeof(rev));
      }
      inline bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x;  }
      inline void pushup( int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]]+1; }
      inline void pushdown(int x) {
                 if (rev[x]) {
                      rev[x] = 0;  swap(ch[x][0],ch[x][1]);
                      rev[ch[x][0]] ^= 1, rev[ch[x][1]] ^= 1;
                 }
      }
      inline void Rotate(int x) {
                 int y = fa[x],  z = fa[y],l,r;
                 if  (ch[y][0] == x) l = 0, r=l^1;
                 else  l = 1, r = l^1;
                 if  (!isroot(y)) {
                       if (ch[z][0] == y) ch[z][0] = x;
                       else ch[z][1] = x;
                 }
                 fa[x] = z; fa[y]  = x; fa[ch[x][r]] = y;
                 ch[y][l] = ch[x][r]; ch[x][r] = y;
                 pushup(y), pushup(x);
      }
 
      inline void splay(int  x) {
               int top = 1; q[top] = x;
               for (int i = x; !isroot(i); i = fa[i]) q[++top] = fa[i];
               for (int i = top; i ; i--) pushdown(q[i]);
               while(!isroot(x)) {
                     int y = fa[x], z = fa[y];
                     if (!isroot(y)) {
                         if ((ch[y][0] == x)^(ch[z][0]==y)) Rotate(x);
                         else Rotate(y);
                     }
                     Rotate(x);
               }
      }
      inline void access(int x) { for (int y = 0; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, pushup(x); }
      inline void makeroot(int x) { access(x), splay(x), rev[x] ^= 1; }
      inline int findroot(int x) { access(x), splay(x); while(ch[x][0]) x = ch[x][0]; return x; }
      inline void split(int x,int y) { makeroot(x), access(y), splay(y); }
      inline void cut(int x,int y) { split(x,y); if (ch[y][0] == x) ch[y][0] = 0, fa[x] = 0; } //断的是一条实边
      inline void link(int x,int y) { makeroot(x), fa[x] = y; } // y成为了根
}lct;
 
int fa[20][maxn],a[maxn],n;
 
int go(int x,int len) {
     for (int i = 19; i >= 0; i--) {
          if ((len>>i)&1) x = fa[i][x];
     }
     return x ? x :n+1; //已经课跳出去，连接n+1
}
 
int main() {
    int t;
    scanf ("%d",&t);
    while(t--) {
        lct.init();
        scanf ("%d",&n);
        for (int i  = 2; i <= n; i++) scanf ("%d",&fa[0][i]);
        for (int i = 1; i < 20; i++)
            for (int j = 1; j <= n; j++)
               fa[i][j] = fa[i-1][fa[i-1][j]];
        for (int i = 1; i <= n+1; i++) lct.sz[i] = 1;
        for (int i = 1; i <= n; i++) {
            scanf ("%d",&a[i]);
            lct.link(i,go(i,a[i]));
        }
        int q;
        scanf ("%d",&q);
        while(q--) {
            int op,x,y;
            scanf ("%d%d",&op,&x);
            if (op == 1) {
                lct.split(n+1,x);
                printf ("%d\n",lct.sz[x]-1);
            }
            else{
                scanf ("%d",&y);
                lct.cut(x,go(x,a[x]));
                a[x] = y;
                lct.link(x,go(x,a[x]));
            }
        }
    }
    return 0;
}
