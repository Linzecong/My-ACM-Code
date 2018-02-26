#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 1000;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int T,n,m,step;
bool vis[maxn][maxn][3];
char s[maxn][maxn];
struct node {
    int r, c;
    node(int rr=0, int cc=0):r(rr), c(cc) {}
}s1,s2,G[2];
bool yougui(int x, int y) {
    if((abs(G[0].r-x)+abs(G[0].c-y)) <= 2*step) return true;
    if((abs(G[1].r-x)+abs(G[1].c-y)) <= 2*step) return true;
    return false;
}
queue<node> q[2];
bool bfs(int id) {
    int cnt = q[id].size();
    while(cnt--) {
        node u = q[id].front(); q[id].pop();
        if(yougui(u.r,u.c)) continue;
        for(int i=0;i<4;i++){
            int x = u.r + dx[i], y = u.c + dy[i];
            if(x < 1 || x > n || y < 1 || y > m || s[x][y] == 'X') continue;
            if(yougui(x,y)) continue;
            if(!vis[x][y][id]) {
                if(vis[x][y][(id^1)]) return true;
                vis[x][y][id] = true;
                q[id].push(node(x,y));
            }
        }
    }
    return false;
}
int hehe() {
    memset(vis,false,sizeof(vis));
    step = 0;
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    q[0].push(node(s2.r,s2.c));
    q[1].push(node(s1.r,s1.c));
    vis[s2.r][s2.c][0] = vis[s1.r][s1.c][1] = true;
    while(!q[0].empty() || !q[1].empty()){
        step++;
        if(bfs(0)) return step;
        if(bfs(0)) return step;
        if(bfs(0)) return step;
        if(bfs(1)) return step;
    }
    return -1;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        int c = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i][j] == 'G') s1 = node(i,j);
                else if(s[i][j] == 'M') s2 = node(i,j);
                else if(s[i][j] == 'Z') G[c++] = node(i,j);
            }
        }
        printf("%d\n",hehe());
    }

    return 0;
}