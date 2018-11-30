#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;

int black[MAXN];
vector<int> b;
vector<int> G[MAXN];

struct node{
    int u;
    int d;
};
int fa[MAXN];
int dep[MAXN];
int N,M;
bool vis[101];
bool bfs(int u,int m){
    queue<node> que;
    que.push({fa[u],1});
    int ans=1;
    memset(vis,0,sizeof(vis));
    vis[u]=1;
    vis[fa[u]]=1;
    while(!que.empty()){
        node tp=que.front();
        que.pop();
        if(black[tp.u])
            ans++;
        if(tp.d==m)
            continue;
        for(auto &v:G[tp.u]){
            if(vis[v]==0&&dep[v]<=dep[u]){
                que.push({v,tp.d+1});
                vis[v]=1;
            }
        }
    }


    return ans>=M;
}

bool judge(int m){
    for(auto &u:b){
        if(bfs(u,m))
            return true;
    }
    return false;
}

void dfs(int u,int f,int d){
    fa[u]=f;
    dep[u]=d;
    for(auto &v:G[u]){
        if(v!=f)
            dfs(v,u,d+1);
    }
}


int main(){

    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&black[i]);
        if(black[i])
            b.push_back(i);
    }
    int u,v;
    for(int i=1;i<N;i++){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1,0,0);

    if(M==1){
        cout<<0<<endl;
        return 0;
    }

    int ans=0;
    int l=1,r=105;
    while(l<r){
        int m=(l+r)/2;
        if(judge(m)){
            r=m;
            ans=m;
        }
        else
            l=m+1;
    }
    cout<<ans<<endl;


    return 0;
}


