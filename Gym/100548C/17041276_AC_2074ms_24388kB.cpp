#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MAXN= 405;//点数的最大值
const int MAXM= 1e6 + 10;//边数的最大值
#define captype double
struct Edge{
    int from,to,next;
    captype cap;
};

struct SAP_MaxFlow{
    Edge edges[MAXM];
    int tot,head[MAXN];
    int gap[MAXN];
    int dis[MAXN];
    int cur[MAXN];
    int pre[MAXN];

    void init(){
        tot=0;
        memset(head,-1,sizeof(head));
    }
    void AddEdge(int u,int v,captype c,captype rc=0){
        edges[tot] = (Edge){u,v,head[u],c};  head[u]=tot++;
        edges[tot] = (Edge){v,u,head[v],rc}; head[v]=tot++;
    }
    captype maxFlow_sap(int sNode,int eNode, int n){//n是包括源点和汇点的总点个数，这个一定要注意
        memset(gap,0,sizeof(gap));
        memset(dis,0,sizeof(dis));
        memcpy(cur,head,sizeof(head));
        pre[sNode] = -1;
        gap[0]=n;
        captype ans=0;
        int u=sNode;
        while(dis[sNode]<n){
            if(u==eNode){
                captype Min=INF ;
                int inser;
                for(int i=pre[u]; i!=-1; i=pre[edges[i^1].to])
                if(Min>edges[i].cap){
                    Min=edges[i].cap;
                    inser=i;
                }
                for(int i=pre[u]; i!=-1; i=pre[edges[i^1].to]){
                    edges[i].cap-=Min;
                    edges[i^1].cap+=Min;
                }
                ans+=Min;
                u=edges[inser^1].to;
                continue;
            }
            bool flag = false;
            int v;
            for(int i=cur[u]; i!=-1; i=edges[i].next){
                v=edges[i].to;
                if(edges[i].cap>0 && dis[u]==dis[v]+1){
                    flag=true;
                    cur[u]=pre[v]=i;
                    break;
                }
            }
            if(flag){
                u=v;
                continue;
            }
            int Mind= n;
            for(int i=head[u]; i!=-1; i=edges[i].next)
            if(edges[i].cap>0 && Mind>dis[edges[i].to]){
                Mind=dis[edges[i].to];
                cur[u]=i;
            }
            gap[dis[u]]--;
            if(gap[dis[u]]==0) return ans;
            dis[u]=Mind+1;
            gap[dis[u]]++;
            if(u!=sNode)  u=edges[pre[u]^1].to;  //退一条边
        }
        return ans;
    }
}F;

int N, M ;
double d[MAXN];
int tag[MAXN];
int G[405][405];

#define U (400 * 2100)

bool check(double g)
{
    int s = 0, t = N+1;
    F.init();
    double flow = 0;
    for(int i=1;i<=N;++i){
        d[i] = 0.0;
        for(int j=1;j<=N;++j){
            if(i==j) 
                continue;
            d[i] += G[i][j];
           // if(G[i][j])
                F.AddEdge(i,j,G[i][j]);
        }
    }

    for(int i=1;i<=N;++i){
        if(tag[i]){
            flow += U + 2*g - d[i];
            F.AddEdge(s, i, INF);
        }
        else{
            F.AddEdge(s,i,U);
            F.AddEdge(i,t, U + 2 * g  - d[i]);
        }
    }

    double hg = (U*N - flow - F.maxFlow_sap(s,t,t+1)) * 0.5;
    return hg > eps;
}

int A[MAXN];
int main()
{

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        int u,v,w;
        memset(G,0,sizeof(G));

        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&A[i]);

        for(int i=1;i<=N;++i){
            for(int j=i+1;j<=N;j++)
                if(A[j]<A[i])
                    G[i][j] = G[j][i] = 1;
        }

        for(int i=1;i<=N;++i){
            tag[i]=0;
        }
        double L = 0, R = 200, mid;
        while(R - L >= eps){
            mid = (L+R) * 0.5;
            if(check(mid)) L = mid;
            else R = mid;
        }
        printf("Case #%d: %.10f\n",qqq,(L+R)*0.5);
        
    }
    
    return 0;
}

