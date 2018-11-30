#include<iostream>
using namespace std;

int a[50005];
int tree[50005<<2];//和 

void pushup(int root){
	tree[root]=tree[root*2]+tree[root*2+1];
}

void build(int l,int r,int root){
	if(l==r){
		tree[root]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,root*2);
	build(m+1,r,root*2+1);
	pushup(root);
} 

//
int query(int L,int R,int l,int r,int root){
	if(L<=l&&r<=R)
		return tree[root];
	
	int m=(l+r)/2;
	int ANS=0; 
	if(L<=m){
		ANS+=query(L,R,l,m,root*2);
	}
	if(R>m){
		ANS+=query(L,R,m+1,r,root*2+1); 
	} 
	return ANS;	
}


void update(int L,int C,int l,int r,int root){
	if(l==r){
		tree[root]+=C;
		return;
	}
	int m=(l+r)/2;
	if(L<=m){
		update(L,C,l,m,root*2);
	}
	else{
		update(L,C,m+1,r,root*2+1); 
	}
	pushup(root);
}


int main(){
	
	int t;
	int nc=1;
	scanf("%d",&t);
	while(t--){
		printf("Case %d:\n",nc++);
		int n;
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
			
		build(1,n,1);
		
//		for(int i=1;i<20;i++)
//		cout<<tree[i]<<" ";
//			
			
		char str[10];
		
		while(~scanf("%s",str)){
			if(str[0]=='E')
				break;
			if(str[0]=='A'){
				int i,j;
				scanf("%d%d",&i,&j);
				update(i,j,1,n,1);
				
			}
			if(str[0]=='S'){
				int i,j;
				scanf("%d%d",&i,&j);
				update(i,-j,1,n,1); 
			}
			
			if(str[0]=='Q'){
				int i,j;
				scanf("%d%d",&i,&j);
				
				printf("%d\n",query(i,j,1,n,1));
			}
		}
	}
	return 0; 
}




