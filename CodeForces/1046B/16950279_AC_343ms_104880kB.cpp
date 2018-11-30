#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500000;
const int MAXLOGV=20;

struct edge{
    int u,v,next;
}e[MAXN*4],e1[MAXN*4];
int head1[MAXN],edge_num1;
int head[MAXN],edge_num;
void insert_edge(int u,int v){
    e1[edge_num1].u=u;
    e1[edge_num1].v=v;
    e1[edge_num1].next=head1[u];
    head1[u]=edge_num1++;
}

void insert_edge2(int u,int v){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

int N,M,Q;
int st[MAXN];
int low[MAXN];
int dfn[MAXN];
int n1;
void tarjan(int k,int fa)
{
    st[++st[0]]=k;
    low[k]=dfn[k]=++dfn[0];
    for(int i=head1[k];~i;i=e1[i].next)
    {
        int p=e1[i].v;
        if(p!=fa)
        {
            if(!dfn[p])
            {
                tarjan(p,k);
                if(low[p]>=dfn[k])//栈中p所在的部分与k构成了一个点双
                                  //当low[p]>dfn[k]时，这个点双只有一条边两个点。
                {
                    insert_edge2(++n1,k);
                    insert_edge2(k,n1);//新建方点n1，并向所有点双中的点连边
                    while(st[st[0]]!=p){
                        insert_edge2(n1,st[st[0]]);
                        insert_edge2(st[st[0]],n1);
                        st[st[0]--]=0;
                    }
                    insert_edge2(n1,p);
                    insert_edge2(p,n1);
                    st[st[0]--]=0;
                }
                else low[k]=min(low[k],low[p]);
            }
            else low[k]=min(low[k],dfn[p]);
        }
    }
}


int f[MAXLOGV+2][MAXN];
int dep[MAXN];
void dfs(int u,int fa)
{
    f[0][u]=fa;
    dep[u]=dep[fa]+1;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)
            continue;
        dfs(v,u);
    }
}
void lca_init(){
    memset(f,0,sizeof(f));
    dep[0]=0;
    dfs(1,1);
    for(int k=0;k+1<MAXLOGV;++k){
        for(int v=1;v<=n1;++v){
            f[k+1][v]=f[k][f[k][v]];
        }
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


int main()
{
    memset(head,-1,sizeof(head));
    edge_num=0;
    memset(head1,-1,sizeof(head1));
    edge_num1=0;
    scanf("%d%d%d",&N,&M,&Q);
    n1=N;
    int u,v;
    for(int i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        insert_edge(u,v);
        insert_edge(v,u);
    }

    tarjan(1,0);

//    for(int i=0;i<edge_num;i++)
//        cout<<e[i].u<<" "<<e[i].v<<endl;

    lca_init();

    while(Q--){
        scanf("%d%d",&u,&v);
        printf("%d\n",(dep[u]+dep[v]-2*dep[LCA(u,v)])/2);
       // cout<<LCA(u,v)<<endl;
    }

    return 0;
}





