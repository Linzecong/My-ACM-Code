#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long int ll;

ll a[100005];

ll tree[100005<<2];
ll lazy[100005<<2];

void pushup(int root){
	tree[root]=tree[root*2]+tree[root*2+1];
}

void pushdown(int l,int r,int root){
	int m=(l+r)/2;
	if(lazy[root]!=0){
		tree[root*2]+=lazy[root]*(m-l+1);
		tree[root*2+1]+=lazy[root]*(r-(m+1)+1);
		
		lazy[root*2]+=lazy[root];
		lazy[root*2+1]+=lazy[root];
		lazy[root]=0;
	}
}

void build(int l,int r,int root){
	lazy[root]=0;
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
ll query(int L,int R,int l,int r,int root){
	if(L<=l&&r<=R)
		return tree[root];
		
	int m=(l+r)/2;
	
	
	pushdown(l,r,root);
	
	ll ANS=0; 
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


void update(int L,int R,ll C,int l,int r,int root){
	
	if(L<=l&&r<=R){
		tree[root]+=C*(r-l+1);
		lazy[root]+=C;
		return;
	}
	
	int m=(l+r)/2;
	pushdown(l,r,root);
	
	if(L<=m){
		update(L,R,C,l,m,root*2);
	}
	
	if(R>m){
		update(L,R,C,m+1,r,root*2+1); 
	}
	pushup(root);
	
}


int main(){
	
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	build(1,n,1);
	char str[10];
	for(int i=0;i<q;i++){
		scanf("%s",str);
		if(str[0]=='Q'){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b,1,n,1));
		}
		if(str[0]=='C'){
			int a,b;
			ll c;
			scanf("%d%d%lld",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
	}
	
	
	

	return 0; 
}



