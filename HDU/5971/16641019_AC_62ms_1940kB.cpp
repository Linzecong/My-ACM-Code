#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct edge{
	int u,v;
	int next;	
}e[20005];
int edge_num,head[2000];
void insert_edge(int u,int v){
	e[edge_num].u=u;
	e[edge_num].v=v;
	e[edge_num].next=head[u];
	head[u]=edge_num++;
}

int col[2000];
vector<int> good,bad;
vector<int> have;

bool flag=0;
void dfs(int u,int fa,int c){
	
	if(col[u]==-1){
		col[u]=c;
		for(int i=head[u];~i;i=e[i].next){
			if(e[i].v!=fa){
				dfs(e[i].v,u,1-c);
			}
		}
	}
	else{
		if(col[u]!=c){
			flag=1;
		}
		else{
			return;	
		}
	}
	
}


int main(){
	
	int N,M,A,B;
	while(cin>>N>>M>>A>>B){
		edge_num=0;
		flag=0;
		memset(head,-1,sizeof(head));
		memset(col,-1,sizeof(col));
		good.clear();
		bad.clear();
		have.clear();
		
		int u,v,t;
		for(int i=0;i<M;i++){
			scanf("%d%d",&u,&v);
			insert_edge(u,v);
			insert_edge(v,u);
			have.push_back(u);
			have.push_back(v);
		}
		
		for(int i=0;i<A;i++){
			scanf("%d",&t);
			good.push_back(t);
		}
		
		for(int i=0;i<B;i++){
			scanf("%d",&t);
			bad.push_back(t);
		}
		
		for(int i=0;i<A;i++){
			dfs(good[i],good[i],0);
		}
		
		for(int i=0;i<B;i++){
			dfs(bad[i],bad[i],1);
		}
		
		for(int i=0;i<have.size();i++){
			if(col[have[i]]==-1){
				dfs(have[i],have[i],0);
			}
		}
		
		for(int i=1;i<=N;i++){
			
			if(col[i]==-1){
				flag=1;
			}
			
		}
		
		if(flag)
		cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
		}
		
		
			
		
		
	}

	return 0;
}