#include<iostream>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
const int MAXN=2005;
typedef long long ll;

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
    int w;
    int next;
}e[MAXN*4];
int edge_num,head[MAXN];
void insert_edge(int u,int v,int w){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].w=w;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

int N,M;
bool vis[MAXN];
int time[MAXN];
int d[MAXN];
bool spfa(int s){
    queue<int> que;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    memset(time,0,sizeof(time));
    que.push(s);
    d[s]=0;
    time[s]++;
    vis[s]=1;
    while(!que.empty()){
        int tp=que.front();
        que.pop();
        vis[tp]=0;
        for(int i=head[tp];~i;i=e[i].next){
            int v=e[i].v;
            if(d[tp]+e[i].w<d[v]){
                d[v]=d[tp]+e[i].w;
                if(vis[v]==0){
                    vis[v]=1;
                    que.push(v);
                    if(++time[v]>=N)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int ans[MAXN];
int main(){

    int T;
    scan_d(T);
    for(int ttt=1;ttt<=T;ttt++){

        edge_num=0;
        memset(head,-1,sizeof(head));

        int X;
        int A,B,C,D;
        scan_d(N);
        scan_d(M);
        scan_d(X);
        for(int i=1;i<=M;i++){
            scan_d(A);
            scan_d(B);
            scan_d(C);
            scan_d(D);
            if(A==B&&C==D){
                insert_edge(B,C,X);
                insert_edge(D,A,-X);
            }
            else if(A==B&&B==C&&A==C){
                insert_edge(D,A,-X-1);
            }
            else if(B==C&&C==D&&D==B){
                insert_edge(D,A,-X-1);
            }
            else{
                insert_edge(B,C,X-1);
                insert_edge(D,A,-X-1);
            }

        }

        for(int i=1;i<=N;i++){
            if(i>1)
                insert_edge(i,i-1,-1);

            insert_edge(0,i,0);
        }


        if(spfa(0))
        {
            printf("Case #%d: IMPOSSIBLE\n",ttt);
        }
        else{

            printf("Case #%d: ",ttt);
            for(int i=2;i<=N;i++){

                int dd=d[i];
                if(dd==0x3f3f3f3f)
                    printf("%d",2000000000);
                else{
                    printf("%d",d[i]-d[i-1]);
                }
                if(i!=N)
                    printf(" ");
                else
                    puts("");
            }
        }

    }

    return 0;
}








