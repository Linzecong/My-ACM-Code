#include <bits/stdc++.h>
using namespace std;
const int MAXM=200505;
const int MAXN=100505;
typedef long long int ll;
struct edge
{
    int u,v,a,b;
    int next;

}e[MAXM];
int edge_num=0;
int head[MAXN];

void insert_edge(int a,int b,int c,int d){
    e[edge_num].u=a;
    e[edge_num].v=b;
    e[edge_num].a=c;
    e[edge_num].b=d;
    e[edge_num].next=head[a];
    head[a]=edge_num++;
}

struct Node{
    int id;
    ll d;
    Node(int id,ll d):id(id),d(d){}
    bool operator < (const Node &A)const{
        return d>A.d;
    }
};


ll d[MAXN];
bool vis[MAXN];

int dijkstra(int S,int T){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<Node> que;
    que.push(Node(S,1));
    d[S]=1;
    while(!que.empty()){
        Node tp1=que.top();
        que.pop();
        int tp=tp1.id;

        if(tp==T){
            for(int i=1;;i++)
                if((1LL<<i)>tp1.d)
                    return i-1;
        }

        if(vis[tp])
            continue;

        vis[tp]=1;

        for(int i=head[tp];i!=-1;i=e[i].next){
            if(vis[e[i].v])
                continue;

            if(((e[i].a+tp1.d)/tp1.d)>=(1LL<<e[i].b)&&e[i].a+tp1.d<d[e[i].v]){
                d[e[i].v]=e[i].a+tp1.d;
                que.push(Node(e[i].v,d[e[i].v]));
            }

        }

    }

    return -1;
}

int main()
{

    int T;
    scanf("%d",&T);
    while(T--){
        memset(head,-1,sizeof(head));
        edge_num=0;

        int u,v,a,b;
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            scanf("%d%d%d%d",&u,&v,&a,&b);
            insert_edge(u,v,a,b);
        }
        printf("%d\n",dijkstra(1,N));
    }

    return 0;
}






