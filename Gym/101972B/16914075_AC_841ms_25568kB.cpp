#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int a[MAXN];
vector<int> G[MAXN];

int line[MAXN];
bool vis[MAXN];

bool vis2[MAXN];
int dep[MAXN];
int sz[MAXN];

void dfs1(int u,int fa,int d){
    dep[u]=d;
    sz[u]=1;
    if(G[u].size()>3)
        vis[u]=1;
    for(auto &v:G[u]){
        if(v==fa)
            continue;
        dfs1(v,u,d+1);
        sz[u]+=sz[v];
        if(G[v].size()>=3||vis[v])
            vis[u]=1;

    }
}

map<int,int> add[2];
map<int,int> sub[2];
int maxx=0;
int ans[MAXN];

int combine(int u){

    for(auto &t:sub[0]){
        add[1][t.first+2*dep[u]]+=t.second;
        maxx=max(maxx,add[1][t.first+2*dep[u]]);
    }

    for(auto &t:add[0]){
        sub[1][t.first-2*dep[u]]+=t.second;
        maxx=max(maxx,sub[1][t.first-2*dep[u]]);
    }

    add[1][a[u]+dep[u]]++;
    sub[1][a[u]-dep[u]]++;
    maxx=max(maxx,add[1][a[u]+dep[u]]);
    maxx=max(maxx,sub[1][a[u]-dep[u]]);

    return sz[u]-maxx;
}

void dfs3(int u,int fa,int c){
    vis2[u]=1;
    if(u!=1)
    {
        if(G[u].size()==1){

            add[c][a[u]+dep[u]]++;
            sub[c][a[u]-dep[u]]++;

            maxx=max(maxx,add[c][a[u]+dep[u]]);
            maxx=max(maxx,sub[c][a[u]-dep[u]]);
            ans[u]=sz[u]-maxx;
        }
    }

    for(auto &v:G[u]){
        if(v==fa)
            continue;
        dfs3(v,u,c);
        add[c][a[u]+dep[u]]++;
        sub[c][a[u]-dep[u]]++;

        maxx=max(maxx,add[c][a[u]+dep[u]]);
        maxx=max(maxx,sub[c][a[u]-dep[u]]);
        ans[u]=sz[u]-maxx;

    }
}
void dfs2(int u,int fa){

    if(vis[u]==0){
        if(G[u].size()<=2&&u!=1){
            maxx=0;
            dfs3(u,fa,0);
            add[0].clear();
            sub[0].clear();
        }
        else{
            int cnt=0;
            int ch[2];
            for(auto &v:G[u]){
                if(v==fa)
                    continue;
                ch[cnt++]=v;
                maxx=0;
                dfs3(v,u,cnt-1);
            }
            ans[u]=combine(u);
            add[0].clear();
            add[1].clear();
            sub[0].clear();
            sub[1].clear();
        }
    }

    for(auto &v:G[u]){
        if(v==fa)
            continue;
        if(vis2[v])
            continue;
        dfs2(v,u);
    }
}



int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(ans,-1,sizeof(ans));
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));

        add[0].clear();
        add[1].clear();
        sub[0].clear();
        sub[1].clear();
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
            G[i].clear();
        }
        for(int i=1,u,v;i<N;i++){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if(N==1){
            printf("%d\n",0);
        }
        else{

            if(G[1].size()>2)
                vis[1]=1;
            dfs1(1,0,0);
            dfs2(1,0);

            for(int i=1;i<=N;i++){
                printf("%d%c",ans[i],i==N?'\n':' ');
            }
        }

    }

    return 0;
}



