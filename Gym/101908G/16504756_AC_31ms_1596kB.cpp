#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;
const int MAXN=4005;
const int INF=0x3f3f3f3f;
typedef long long ll;

int X[MAXN];
int Y[MAXN];

struct edge{
	int u,v,t;
}e1[40001];
int P,R,C;

struct Edge
{
    int v, next;
    ll flow;
} e[50001];
 
int head[MAXN], edge_num, layer[MAXN];
 
void addedge(int u, int v, ll w)
{
    e[edge_num].v = v;
    e[edge_num].flow = w;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
 
    e[edge_num].v = u;
    e[edge_num].flow = 0;
    e[edge_num].next = head[v];
    head[v] = edge_num++;
}
 
bool bfs(int start, int End)
{
    queue<int> Q;
    Q.push(start);
    memset(layer, 0, sizeof(layer));
    layer[start] = 1;
    while (Q.size())
    {
        int u = Q.front();
        Q.pop();
 
        if (u == End)
            return true;
 
        for (int j = head[u]; j != -1; j = e[j].next)
        {
            int v = e[j].v;
 
            if (layer[v] == false && e[j].flow)
            {
                layer[v] = layer[u] + 1;
                Q.push(v);
            }
        }
    }
 
    return false;
}
ll dfs(int u, ll MaxFlow, int End)
{
    if (u == End)
        return MaxFlow;
 
    ll uflow = 0;
 
    for (int j = head[u]; j != -1; j = e[j].next)
    {
        int v = e[j].v;
 
        if (layer[v] - 1 == layer[u] && e[j].flow)
        {
            ll flow = min(MaxFlow - uflow, e[j].flow);
            flow = dfs(v, flow, End);
 
            e[j].flow -= flow;
            e[j ^ 1].flow += flow;
 
            uflow += flow;
 
            if (uflow == MaxFlow)
                break;
        }
    }
    if (uflow == 0)
        layer[u] = 0;
    return uflow;
}
ll dinic(int start, int End)
{
    ll MaxFlow = 0;
    while (bfs(start, End))
        MaxFlow += dfs(start, INF, End);
    return MaxFlow;
}


int cnt=0;
int S,T;
int SX[MAXN];
int SY[MAXN];
ll sum=0;

void rebuild(int m){
	cnt=0;
	memset(head,-1,sizeof(head));
	edge_num=0;
	for(int i=1;i<=R;i++){
		addedge(S,SX[i],X[i]);
	}
		
	for(int j=1;j<=P;j++){
		addedge(SY[j],T,Y[j]);
	}
	
	for(int i=1;i<=C;i++){
		if(e1[i].t<=m){
			addedge(SX[e1[i].v],SY[e1[i].u],INF);
		}
	}
}

bool judge(){
	ll fl=dinic(S,T);
	if(fl<sum){
		return false;
	}
	else
		return true;
}


int main(){
	
	
	scanf("%d%d%d",&P,&R,&C);
	
	for(int i=1;i<=P;i++){
		scanf("%d",&Y[i]);
		sum=sum+ll(Y[i]);
	}
		
		
	for(int i=1;i<=R;i++)
		scanf("%d",&X[i]);
	
	for(int i=1;i<=C;i++)
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].t);
	
	S=++cnt;
	T=++cnt;
	for(int i=1;i<=R;i++)
		SX[i]=++cnt;
		
	for(int j=1;j<=P;j++)
		SY[j]=++cnt;
	
	
	int L=1,R=1000005;
	
	while(L<R){
		int m=(L+R)/2;
		rebuild(m);
		if(judge()){
			R=m;
		}
		else
			L=m+1;	
	}
	
	if(L==1000005)
		cout<<-1<<endl;
	else
		printf("%d\n",L);
	
	
	
	
	
	return 0;
}