#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
using namespace std;
typedef long long int ll;
const int MAXN=205005;

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

vector<int> G[MAXN];
int blocksize, blocknum;
int sta[MAXN];
int top;
int deep[MAXN];
int block[MAXN];
int fa[MAXN];
int dfn[MAXN];
int dfs_clock;
int N,Q;
void dfs(int x)
{
    dfn[x]=++dfs_clock;
    int bottom = top;
    for (int i = 0; i<G[x].size(); i++)
    {
        int to = G[x][i];
        if (to != fa[x])
        {
            fa[to] = x;
            deep[to] = deep[x] + 1;
            dfs(to);
            if (top - bottom >= blocksize)
            {
                blocknum++;
                while (top != bottom)
                    block[sta[top--]] = blocknum;
            }
        }
        sta[++top] = x;
    }
}



struct Query{
    int l;
    int r;
    int id;
}q[MAXN];
bool cmp(Query a,Query b){
    if(block[a.l]==block[b.l])
        return dfn[a.r]<dfn[b.r];
    return block[a.l]<block[b.l];
}

int V[MAXN];
bool vis[MAXN];
int ans[MAXN];
int bs;
int num[MAXN];
int bnum[MAXN];
int blo[MAXN];

int lca_vis[MAXN];
int par[MAXN], lca[MAXN];
vector< pair<int , int> >lazy[MAXN];
int find_fa(int x){
    top = 0;
    while(x != par[x]){
        sta[top++] = x;
        x = par[x];
    }
    while(top){
        par[sta[--top]] = x;
    }
    return x;
}

void dfs2(int x){
    par[x] = x;
    for(int i=0; i<G[x].size(); i++){
        int j = G[x][i];
        if(j == fa[x])	continue;
        dfs2(j);
    }

    lca_vis[x] = 1;

    for(int i=0; i<lazy[x].size(); i++){
        int j = lazy[x][i].first;
        int k = lazy[x][i].second;
        if(lca_vis[j]){
            lca[k] = find_fa(j);
        }
    }
    par[x] = fa[x];
}


void Work(int x){
    if(vis[x]){
        num[V[x]]--;
        if(num[V[x]]%2){
            bnum[blo[V[x]]]++;
        }
        else
            bnum[blo[V[x]]]--;

        vis[x]=0;
    }
    else{
        num[V[x]]++;
        if(num[V[x]]%2){
            bnum[blo[V[x]]]++;
        }
        else
            bnum[blo[V[x]]]--;
        vis[x]=1;
    }
}

void Move(int x,int y){
    while(x!=y){
        if(deep[x]>deep[y])
            swap(x,y);
        Work(y);
        y=fa[y];
    }
}

int res(){
    //    for(int i=1;i<=5;i++)
    //        cout<<num[i]<<" ";
    //    cout<<endl;

    for(int i=1;i<=bs+1;i++){
        if(bnum[i]!=bs){
            for(int j=(i-1)*bs+1;j<MAXN;j++){
                if(num[j]%2==0){
                    return j;
                }
            }
        }
    }
}


int main(){

    int T;
    scan_d(T);

    bs=sqrt(MAXN);
    for(int i=1;i<MAXN;i++)
        blo[i]=(i-1)/bs+1;

    while(T--){
        memset(vis, 0, sizeof(vis));
        memset(num, 0, sizeof(num));
        memset(bnum, 0, sizeof(bnum));
        memset(fa, -1, sizeof(fa));
        memset(deep, 0, sizeof(deep));
        memset(dfn,0,sizeof(dfn));
        dfs_clock=0;
        blocknum=0;

        scan_d(N);
        scan_d(Q);
        blocksize=sqrt(N);
        for(int i=1;i<=N;i++){
            G[i].clear();
            lazy[i].clear();
            scan_d(V[i]);
        }
        int u,v;
        for(int i=1;i<N;i++){
            scan_d(u);
            scan_d(v);
            G[u].push_back(v);
            G[v].push_back(u);
        }


        dfs(1);
        blocknum++;
        while(top)
            block[sta[top--]]=blocknum;

        for(int i=0;i<Q;i++){
            scan_d(u);
            scan_d(v);
            if(block[u]>block[v])
                swap(u,v);
            q[i].l=u;
            q[i].r=v;
            q[i].id=i;

            lazy[q[i].l].push_back(make_pair(q[i].r, i));
            lazy[q[i].r].push_back(make_pair(q[i].l, i));
        }
        for(int i=1; i<=N; i++)
                lca_vis[i] = 0;
        dfs2(1);

        sort(q,q+Q,cmp);



        int lcaa=lca[q[0].id];
        Move(q[0].l,q[0].r);
        Work(lcaa);
        ans[q[0].id]=res();
        Work(lcaa);
        for(int i=1;i<Q;i++){
            Move(q[i-1].l,q[i].l);
            Move(q[i-1].r,q[i].r);
            lcaa=lca[q[i].id];
            Work(lcaa);
            ans[q[i].id]=res();
            Work(lcaa);
        }
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);

    }


    return 0;
}








