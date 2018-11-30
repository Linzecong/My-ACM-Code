#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef struct node{
    int to, w;
    node(int a = 0, int b = 0){
        to = a; w = b;
    }
}Edge;
 
const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;
 
vector<Edge> vec[maxn];
int vis[maxn], dis[maxn], cnt[maxn];
 
int spfa(int n){
    Edge v;
    int p, len;
    queue<int> q;
    while(!q.empty()) q.pop();
 
    for(int i = 0; i <= n; ++i){
        dis[i] = INF;
        vis[i] = 0;
        cnt[i] = 0;
    }
    q.push(n);
    cnt[n] = 1;
    vis[n] = 1;
    dis[n] = 0;
 
    while(!q.empty()){
        p = q.front(); q.pop();
        len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            if(dis[v.to] > dis[p] + v.w){
                dis[v.to] = dis[p] + v.w;
                if(!vis[v.to]){
                    vis[v.to] = 1;
                    cnt[v.to] += 1;
                    if(cnt[v.to] >= n) return -1;
                    q.push(v.to);
                }
            }
        }
        vis[p] = 0;
    }
    return dis[1] == INF ? -2 : dis[1];
}
int main(){
    int a, b, d, n, t, ml, md;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &ml, &md);
        for(int i = 0; i <= n; ++i) vec[i].clear();
        for(int i = 1; i < n; ++i){
            vec[i].push_back(node(i+1, 0));
        }
        for(int i = 0; i < ml; ++i){
            scanf("%d%d%d", &a, &b, &d);
            vec[b].push_back(node(a, d));
        }
        for(int i = 0; i < md; ++i){
            scanf("%d%d%d", &a, &b, &d);
            vec[a].push_back(node(b, -d));
        }
        printf("%d\n", spfa(n));
    }
    return 0;
}
