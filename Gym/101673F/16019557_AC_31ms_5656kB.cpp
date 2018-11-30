#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N=1e5+10;
int head[MAX_N],siz[MAX_N],cnt,n;
ll ans[MAX_N],ncnt[MAX_N],fi[MAX_N],se[MAX_N],res1=0,res2=1e18+10;
struct Edge{
    int to,next;
}edge[MAX_N<<1];
void add_edge(int u,int v){
    edge[cnt]=(Edge){v,head[u]};
    head[u]=cnt++;
}
void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(ncnt,0,sizeof(ncnt));
    memset(ans,0,sizeof(ans));
    memset(fi,0,sizeof(fi));
    memset(se,0,sizeof(se));
}
void dfs(int x,int fa){
    siz[x]=1;
    for(int i=head[x];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=fa){
            dfs(v,x);
            siz[x]+=siz[v];
        }
    }
}
void get_ans(int x,int fa){
    ncnt[x]=n+1-siz[x];
    fi[x]=ncnt[x];
    for(int i=head[x];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=fa){
            ans[x]+=(ll)siz[v]*ncnt[x];
            ncnt[x]+=(ll)siz[v];
            se[x]=max(se[x],(ll)siz[v]);
            if(se[x]>fi[x]){
                swap(se[x],fi[x]);
            }
            get_ans(v,x);
        }
    }
    if(res1<ans[x]){
        res1=ans[x],res2=fi[x]*se[x];
    }
}
int main(){
    init();
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(0,-1);
    get_ans(0,-1);
    printf("%lld %lld\n",res1,res1-res2);
    return 0;
}
