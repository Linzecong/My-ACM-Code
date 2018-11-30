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
int fa[MAXN][25],bin[MAXN];
int dfn[MAXN];
int dfs_clock;
int N,Q;
void dfs(int x)
{
    dfn[x]=++dfs_clock;
    int bottom = top;
    for (int i = 1; i < 25; i++)
        if (deep[x] >= bin[i])
            fa[x][i] = fa[fa[x][i - 1]][i - 1];
        else
            break;

    for (int i = 0; i<G[x].size(); i++)
    {
        int to = G[x][i];
        if (to != fa[x][0])
        {
            fa[to][0] = x;
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

int LCA(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
    int t = deep[x] - deep[y];
    for (int i = 0; bin[i] <= t; i++)
        if (t & bin[i])
            x = fa[x][i];
    for (int i = 24; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    if (x == y)
        return x;
    return fa[x][0];
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
        y=fa[y][0];
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
    bin[0] = 1;
    for (int i = 1; i < 25; i++)
        bin[i] = bin[i - 1] << 1;

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
        }


        sort(q,q+Q,cmp);



        int lca=LCA(q[0].l,q[0].r);
        Move(q[0].l,q[0].r);
        Work(lca);
        ans[q[0].id]=res();
        Work(lca);
        for(int i=1;i<Q;i++){
            Move(q[i-1].l,q[i].l);
            Move(q[i-1].r,q[i].r);
            lca=LCA(q[i].l,q[i].r);
            Work(lca);
            ans[q[i].id]=res();
            Work(lca);
        }
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);

    }


    return 0;
}







