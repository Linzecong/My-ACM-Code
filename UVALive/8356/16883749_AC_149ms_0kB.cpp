	#include <iostream>
	#include <cstring>
	#include <algorithm>
	#include <vector>
	using namespace std;
	const int maxn=1e4+5; 
	struct node{
		int y1,y2;
	};
	int x1,x2,y1,y2;
	int MaxX;
	int n,k;
	vector<node>Add[maxn];
	int tree[maxn<<2];
	bool lazy[maxn<<2]; 
	void update(int l,int r,int L,int R,int k){
		int mid=(L+R)>>1;
		if (L>r||R<l) return;
		if (l<=L&&r>=R){
			lazy[k]^=1;
			tree[k]=(R-L+1)-tree[k];
			return;
		}
		if (lazy[k]){
			lazy[k]=0;
			lazy[k*2]^=1;tree[k*2]=(mid-L+1)-tree[k*2];
			lazy[k*2+1]^=1;tree[k*2+1]=(R-mid)-tree[k*2+1];
		}
		update(l,r,L,mid,k*2);
		update(l,r,mid+1,R,k*2+1);
		tree[k]=tree[k*2]+tree[k*2+1];
	}
	long long ans;
	int main(){
		int T;
		scanf("%d",&T);
		while (T--){
			MaxX=0;
			ans=0;
			scanf("%d%d",&n,&k);
			for (int i=1;i<=n;i++)
				Add[i].clear();
			for (int i=0;i<=4*n;i++) tree[i]=0,lazy[i]=0;
			for (int i=1;i<=k;i++){
				scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
				Add[x1].push_back({y1,y2});
				Add[x2+1].push_back({y1,y2});
			}
			for (int i=1;i<=n;i++){
				for (int j=0;j<Add[i].size();j++)
					update(Add[i][j].y1,Add[i][j].y2,1,n,1);
				ans+=tree[1];
			}
			printf("%lld\n",ans);
		}
	}
	
	
	
