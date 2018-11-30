#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN=120005;
const int MAXLOGV=16;

vector<int> G[MAXN];
int f[MAXLOGV+2][MAXN];
int dep[MAXN];

void dfs(int u,int fa)
{
    f[0][u]=fa;dep[u]=dep[fa]+1;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
}
int LCA(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<MAXLOGV;++k){
        if( (dep[v]-dep[u])>>k&1){
            v=f[k][v];
        }
    }
    if(u==v) return u;
    for(int k=MAXLOGV-1;k>=0;--k){
        if(f[k][u]!=f[k][v]){
            u=f[k][u];
            v=f[k][v];
        }
    }
    return f[0][u];
}


int root=1;



int a[MAXN];
int ch[MAXN*40][2];
int num[MAXN*40*2];
int tot=0;
int rt[MAXN];
int N,M;

void insert(int x,int r,int lr){

    bitset<21> s(x);
    int cur=r;
    int lcur=lr;

    for(int i=20;i>=0;i--){

        if(!ch[cur][s[i]]){
            ch[cur][s[i]]=++tot;
            ch[cur][!s[i]]=ch[lcur][!s[i]];
            num[ch[cur][s[i]]]=num[ch[lcur][s[i]]];
        }
        cur=ch[cur][s[i]];
        lcur=ch[lcur][s[i]];
        num[cur]++;
    }

}

ll search(int u,int v,int lca,int x){

    bitset<21> s(x);
    bitset<21> ans;

    unsigned long long res=x^a[lca];

    int ucur=rt[u];
    int vcur=rt[v];
    int lcur=rt[lca];

    for(int i=20;i>=0;i--){
        if((num[ch[ucur][!s[i]]]+num[ch[vcur][!s[i]]]-2*num[ch[lcur][!s[i]]])>0){
            ans[i]=1;
            ucur=ch[ucur][!s[i]];
            vcur=ch[vcur][!s[i]];
            lcur=ch[lcur][!s[i]];
        }
        else{
            ucur=ch[ucur][s[i]];
            vcur=ch[vcur][s[i]];
            lcur=ch[lcur][s[i]];
        }

    }
    return max(ans.to_ullong(),res);
}

void lca_init(){
    memset(f,0,sizeof(f));
    dep[0]=0;
    dfs(1,0);
    for(int k=0;k+1<MAXLOGV;++k){
        for(int v=1;v<=N;++v){
            if(f[k][v]==0) f[k+1][v]=0;
            else f[k+1][v]=f[k][f[k][v]];
        }
    }
}
void insertdfs(int u,int fa){
    rt[u]=++tot;
    insert(a[u],rt[u],rt[fa]);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa)
            insertdfs(v,u);
    }
}

int main(){

    while(~scanf("%d%d",&N,&M)){
        tot=0;
        memset(ch,0,sizeof(ch));
        memset(num,0,sizeof(num));
        memset(rt,0,sizeof(rt));



        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
            G[i].clear();
        }
        int u,v;
        for(int i=0;i<N-1;i++){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        lca_init();
        insertdfs(root,0);

        int x;
        while(M--){
            scanf("%d%d%d",&u,&v,&x);
            cout<<search(u,v,LCA(u,v),x)<<endl;
        }

    }



    return 0;
}






















