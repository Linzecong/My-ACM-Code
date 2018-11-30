#include<bits/stdc++.h>
using namespace std;
const int MAXN=400004;
typedef long long int ll;

struct edge{
	int u,v,next;
}e[MAXN*2];
int head[MAXN],edge_num;
void insert_edge(int u,int v){
	e[edge_num].u=u;
	e[edge_num].v=v;
	e[edge_num].next=head[u];
	head[u]=edge_num++;
}
int N,M;
bool vis[MAXN];
int dis[MAXN];
void bfs(int S){
	
	set<int> s1,s2;
	
	vis[S]=1;

	for(int i=1;i<=N;i++)
		s1.insert(i);	
	dis[S]=0;
	s1.erase(S);

	queue<int> que;
	que.push(S);
	
	while(!que.empty()){
		int tp=que.front();
		que.pop();

			for(int i=head[tp];~i;i=e[i].next){
				int v=e[i].v;
				
				if(s1.count(v)){
					s1.erase(v);
					s2.insert(v);
					vis[v]=1;
				}
			
			}
		for(auto &it:s1){
			dis[it]=dis[tp]+1;
			que.push(it);
		}

		s1=s2;
		s2.clear();
	}

}



int main(){
	
	int T;
	while(~scanf("%d",&T)){
		while(T--){
			edge_num=0;
			memset(head,-1,sizeof(head));
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			int u,v;
			scanf("%d%d",&N,&M);
			for(int i=0;i<M;i++){
				scanf("%d%d",&u,&v);
				insert_edge(u,v);
				insert_edge(v,u);
												
			}
			int S;
			scanf("%d",&S);

			bfs(S);

			for(int i=1;i<=N;i++){
				if(i==S)
				  continue;
			  
				if(dis[i]!=0x3f3f3f3f)
				printf("%d",dis[i]);
			  else
				printf("%d",-1);
				if(i==N)
					printf("\n");
				else
				  printf(" ");
			}

		}
	}
	




















	return 0;
}