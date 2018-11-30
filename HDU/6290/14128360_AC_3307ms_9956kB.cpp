#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM=200500;
const int MAXN=100500;

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

struct edge{
    int u;
    int v;
    int a;
    int b;
    int next;
}e[MAXM];
int edge_num,head[MAXN];
void insert_edge(int u,int v,int a,int b){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].a=a;
    e[edge_num].b=b;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

struct Node{
    int id;
    ll d;
    Node(int id, ll d):id(id),d(d){}
    bool operator < (const Node &A)const{
        return d > A.d;
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
            if(((e[i].a+tp1.d)/(tp1.d))>=(1LL<<e[i].b)&&e[i].a+tp1.d<d[e[i].v]){
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
    scan_d(T);
    while(T--){

        memset(head,-1,sizeof(head));
        edge_num=0;

        int u,v,a,b;
        int N,M;
        scan_d(N);
        scan_d(M);
        for(int i=0;i<M;i++){
            scan_d(u);
            scan_d(v);
            scan_d(a);
            scan_d(b);
            insert_edge(u,v,a,b);
        }

        printf("%d\n",dijkstra(1,N));

    }

    return 0;
}











