#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100100;
struct Edge
{
        int to;
        int next;
}e[MAXN*2];
int head[MAXN],edge_num;
void insert_edge(int u,int v)
{
        e[edge_num].to=v;
        e[edge_num].next=head[u];
        head[u]=edge_num++;
}


int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int size[MAXN];
int son[MAXN];
int pos[MAXN];
int SEG;
int A[MAXN];
int N,Q;
void init(){
    edge_num=0;
    memset(head,-1,sizeof(head));
    SEG=1;
    memset(son,-1,sizeof(son));
}

void dfs1(int u,int pre,int d){
        deep[u]=d;
        fa[u]=pre;
        size[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if(v!=pre)
            {
                dfs1(v,u,d+1);
                size[u]+=size[v];
                if(son[u]==-1||size[v]>size[son[u]])
                  son[u]=v;
            }
        }
}

void dfs2(int u,int sp){
    top[u]=sp;
    pos[u]=SEG++;
    if(son[u]!=-1)
      dfs2(son[u],sp);
    else
      return;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(v!=son[u]&&v!=fa[u])
          dfs2(v,v);
    }
}

int root[MAXN<<2],ls[MAXN<<7],rs[MAXN<<7],sum[MAXN<<7];
int col=0,tot=0;

void pushup(int rt){
    sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}

void update(int L,int C,int l,int r,int &rt){
    if(!rt)
      rt=++tot;

    if(l==r){
        sum[rt]+=C;
        return;
    }
    int m=(l+r)/2;
    if(L<=m)
      update(L,C,l,m,ls[rt]);
    else
      update(L,C,m+1,r,rs[rt]);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
    if(!rt)
        return 0;
    if(L<=l&&r<=R)return sum[rt];
    int m=(l+r)/2;
    int ans=0;
    if(L<=m)
        ans+=query(L,R,l,m,ls[rt]);
    if(R>m)
        ans+=query(L,R,m+1,r,rs[rt]);
    return ans;
}

int query(int u,int v,int x){
    int f1=top[u],f2=top[v];
    int temp=0;
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        temp+=query(pos[f1],pos[u],1,N,root[x]);
        u=fa[f1];
        f1=top[u];
    }
    if(deep[u]>deep[v])
      swap(u,v);
    temp+=query(pos[u],pos[v],1,N,root[x]);
    return temp;
}

map<int,int> mp;
int main(){
    init();
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++)
      scanf("%d",&A[i]);
    int x,y;
    for(int i=0;i<N;i++){
        scanf("%d%d",&x,&y);
        insert_edge(x,y);
        insert_edge(y,x);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    for(int i=1;i<=N;i++){
        if(!mp[A[i]])
          mp[A[i]]=++col;
        update(pos[i],1,1,N,root[mp[A[i]]]);
    }
    char s[10];
    while(Q--){
        scanf("%s",s);
        if(s[0]=='C'){
            scanf("%d%d",&x,&y);
            update(pos[x],-1,1,N,root[mp[A[x]]]);
            A[x]=y;
            if(!mp[y])
              mp[y]=++col;
            update(pos[x],1,1,N,root[mp[A[x]]]);

        }
        else{
            int z;
            scanf("%d%d",&x,&y);
            scanf("%d",&z);
            printf("%d\n",query(x,y,mp[z]));
        }
    }

    return 0;
}


