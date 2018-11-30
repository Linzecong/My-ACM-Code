#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;

struct query{
	int l;
	int r;
	int id;
}q[MAXN];
int block[MAXN],blocksize;
bool cmp(query a,query b){
	if(block[a.l]==block[b.l])
		return a.r<b.r;
	return block[a.l]<block[b.l];
}

int a[MAXN];
int N,M;
int ans[MAXN];
int res=0;
int vis[1000005];
void add(int num){
	if(vis[a[num]]==0)
		res++;
	vis[a[num]]++;
}
void remove(int num){
	if(vis[a[num]]==1)
		res--;
	vis[a[num]]--;
}

void solve(){
	int r=0;
	int l=0;
	for(int i=0;i<M;i++){
		
		while(q[i].r>r)
			r++,add(r);
		
		while(q[i].r<r)
			remove(r),r--;
		
		while(q[i].l>l)
			remove(l),l++;
		while(q[i].l<l)
			l--,add(l);
		
		ans[q[i].id]=res;
	
	}
	
}

int main(){
	
	int N;
	scanf("%d",&N);
	blocksize=sqrt(N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		block[i]=(i-1)/blocksize+1;
	}
	
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q,q+M,cmp);
	
	solve();
	for(int i=0;i<M;i++)
		printf("%d\n",ans[i]);
	
	return 0;
}