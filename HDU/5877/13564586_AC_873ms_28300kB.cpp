#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[400005];
int lowbit(int t)
{
return t&(-t);
}
void add(int x,ll y)
{
for(int i=x;i<=400002;i+=lowbit(i))
tree[i]+=y;
}
ll getsum(int x)
{
ll ans=0;
for(int i=x;i>0;i-=lowbit(i))
ans+=tree[i];
return ans;
}

ll ans;
ll a[400005];
ll sorted[500005];
int fa[400005];
vector<int> ch[400005];
ll N,K;
int cnt;

int find(int x){
	return fa[x]==x?x:find(fa[x]);
}

void dfs(int u){
	int n1=lower_bound(sorted+1,sorted+1+cnt,K/a[u])-sorted;
	
	ans+=getsum(n1);
	
	add(lower_bound(sorted+1,sorted+1+cnt,a[u])-sorted,1);
	
	for(int i=0;i<ch[u].size();i++){
		dfs(ch[u][i]);
		add(lower_bound(sorted+1,sorted+1+cnt,a[ch[u][i]])-sorted,-1);
	}

}

int main(){
	
	int T;
	while(~scanf("%d",&T)){
		int u,v;
		
		while(T--){
			memset(tree,0,sizeof(tree));
			ans=0;
			scanf("%lld%lld",&N,&K);
			for(int i=0;i<=N;i++)
				fa[i]=i;
				
			for(int i=1;i<=N;i++){
				scanf("%lld",&a[i]);
				sorted[i]=a[i];
				sorted[i+N]=K/a[i];
			}
			sort(sorted+1,sorted+2*N+1);
			cnt=unique(sorted+1,sorted+1+2*N)-sorted-1;
				
				
			for(int i=0;i<N-1;i++){
				scanf("%d%d",&u,&v);
				ch[u].push_back(v);
				fa[v]=u;
			}
			
			int root=find(1);
			
			dfs(root);
			
			printf("%lld\n",ans);
			for(int i=1;i<=N;i++)
				ch[i].clear();
		}
	
	}

	return 0;
}