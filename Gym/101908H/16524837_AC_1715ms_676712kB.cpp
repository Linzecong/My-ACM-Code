#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned int ull;
const int MAXN=100105;
const int INF=0x3f3f3f3f;
const ull P1=19260817;
ull base[MAXN];
ull res;//记录模式串的哈希值
int N,Q;
char a[MAXN];//模式串
char W[MAXN];//每个点的值
int len;//模式串长度

/****树链剖分部分****/
struct edge{
    int u;
    int v;
    int next;
}e[MAXN*2];
int head[MAXN],edge_num;
void insert_edge(int u,int v){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

int top[MAXN];
int fa[MAXN];
int dep[MAXN];
int siz[MAXN];
int pos[MAXN];
int fp[MAXN];//反pos
int son[MAXN];
int SEG;
void init(){
    edge_num=0;
    memset(head,-1,sizeof(head));
    SEG=1;
    memset(son,-1,sizeof(son));
}

void dfs1(int u,int pre,int d){
    dep[u]=d;
    fa[u]=pre;
    siz[u]=1;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].v;
        if(v!=pre){
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]]){
                son[u]=v;
            }
        }
    }
}

void dfs2(int u,int sp){
    top[u]=sp;
    pos[u]=SEG++;
    fp[SEG-1]=u;
    if(son[u]!=-1)
        dfs2(son[u],sp);
    else
        return;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].v;
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}
/****树链剖分部分****/



struct node{
    int ans,len;
    ull lef[105];
    ull rig[105];
    node(){
        clear();
    }
    void clear(){
        ans=len=0;
        for(int i=0;i<::len;i++){
            lef[i]=rig[i]=0;
        }
    }
}tr[MAXN<<2][2];
node now;

node combine(node x,node y){
    now.clear();
    now.ans=x.ans+y.ans;
    now.len=x.len+y.len;

    for(int i=1;i<len;i++)
        now.ans+=((x.rig[i]*base[len-i]+y.lef[len-i])==res);

    for(int i=1;i<len;i++){
        if(x.len>=i)
            now.lef[i]=x.lef[i];
        else if(now.len>=i)
            now.lef[i]=x.lef[x.len]*base[i-x.len]+y.lef[i-x.len];
        else
            now.lef[i]=0;
    }

    for(int i=1;i<len;i++){
        if(y.len>=i)
            now.rig[i]=y.rig[i];
        else if(now.len>=i)
            now.rig[i]=y.rig[y.len]+x.rig[i-y.len]*base[y.len];
        else
            now.rig[i]=0;
    }
    return now;
}


void pushup(int rt){
    tr[rt][0]=combine(tr[rt<<1][0],tr[rt<<1|1][0]);
    tr[rt][1]=combine(tr[rt<<1|1][1],tr[rt<<1][1]);
}

void build(int l,int r,int rt){
    tr[rt][0].len=tr[rt][1].len=r-l+1;
    if(l==r){
        tr[rt][0].lef[1]=tr[rt][0].rig[1]=W[fp[l]];
        tr[rt][1].lef[1]=tr[rt][1].rig[1]=W[fp[l]];
        tr[rt][0].ans=tr[rt][1].ans=(tr[rt][0].lef[1]==res);
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

void update(int L,ull C,int l,int r,int rt){
    if(l==r){
        tr[rt][0].lef[1]=tr[rt][0].rig[1]=C;
        tr[rt][1].lef[1]=tr[rt][1].rig[1]=C;
        tr[rt][0].ans=tr[rt][1].ans=(tr[rt][1].lef[1]==res);
        return;
    }
    int m=(l+r)/2;
    if(L<=m)
        update(L,C,l,m,rt<<1);
    else
        update(L,C,m+1,r,rt<<1|1);
    pushup(rt);
}

node tmp;
void query(int L,int R,int l,int r,int rt,int type){
    if(L<=l&&r<=R){
        if(tmp.len==0)
            tmp=tr[rt][type];
        else
            tmp=combine(tmp,tr[rt][type]);
        return;
    }
    int m=(l+r)/2;
    if(type==0){
        if(L<=m)
            query(L,R,l,m,rt<<1,type);
        if(R>m)
            query(L,R,m+1,r,rt<<1|1,type);
    }
    else{
        if(R>m)
            query(L,R,m+1,r,rt<<1|1,type);
        if(L<=m)
            query(L,R,l,m,rt<<1,type);
    }
}

node lef_ans;
node rig_ans;
int query(int u,int v){
    int f1=top[u];
    int f2=top[v];
    lef_ans.clear();
    rig_ans.clear();
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            tmp.clear();
            query(pos[f2],pos[v],1,N,1,0);
            rig_ans=combine(tmp,rig_ans);
            v=fa[f2];
            f2=top[v];
        }
        else{
            tmp.clear();
            query(pos[f1],pos[u],1,N,1,1);
            lef_ans=combine(lef_ans,tmp);
            u=fa[f1];
            f1=top[u];
        }
    }
    if(dep[u]>dep[v]){
        tmp.clear();
        query(pos[v],pos[u],1,N,1,1);
        lef_ans=combine(lef_ans,tmp);
    }
    else{
        tmp.clear();
        query(pos[u],pos[v],1,N,1,0);
        lef_ans=combine(lef_ans,tmp);
    }
    lef_ans=combine(lef_ans,rig_ans);
    return lef_ans.ans;
}

int main(){
    base[0]=1;
    base[1]=P1;
    for(int i=2;i<MAXN;i++)
        base[i]=base[i-1]*P1;
    init();
    scanf("%d%d",&N,&Q);
    scanf("%s%s",a,W+1);
    len=strlen(a);
    for(int i=0;i<len;i++)
        res=res*P1+a[i];

    int u,v;
    for(int i=1;i<N;i++){
        scanf("%d%d",&u,&v);
        insert_edge(u,v);
        insert_edge(v,u);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    build(1,N,1);
    int op;
    char x[5];
    while(Q--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&u,&v);
            printf("%d\n",query(u,v));
        }
        else{
            scanf("%d",&u);
            scanf("%s",x);
            update(pos[u],x[0],1,N,1);
        }
    }

    return 0;
}


