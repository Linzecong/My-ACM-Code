#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


const int maxn=100005;

int tree[maxn<<2];//线段树数组，看你要存什么

int A[maxn];//原数组，下标1~n

//更新节点信息，这里是求最值
void pushup(int rt){
    if(A[tree[rt<<1]]>A[tree[rt<<1|1]])
    tree[rt]=tree[rt<<1];
    else
    tree[rt]=tree[rt<<1|1];
}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    if(l==r){//若到达叶子结点
        tree[rt]=l;//将该位置存原数组的值
        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);//建完左右子树后，更新当前节点的值
}

//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
int query(int L,int R,int l,int r,int rt){
	if(R<L)
	return -1;
	
    if(L<=l&&r<=R)//如果当前区间在查询区间内，直接返回当前存的值
        return tree[rt];

    int m=(l+r)>>1;

    //累加求答案
    int ANS=0;
    if(L<=m){
        int ttt=query(L,R,l,m,rt<<1);
		if(A[ANS]<A[ttt])
		ANS=ttt;
    }
        
    if(R>m){
		int ttt=query(L,R,m+1,r,rt<<1|1);
		if(A[ANS]<A[ttt])
		ANS=ttt;
    }
    return ANS;
}


struct card{
    int c;
    int r;
    int i;
}cards[100005];

bool cmp(card a,card b){
    if(a.c==b.c)
        return a.r<b.r;
    return a.c<b.c;
}

int n;

int lowb(int x){
    int l=1;
    int r=n;
    int m;
    while(l<=r){
        m=(l+r)/2;
       // cout<<m<<endl;
        if(cards[m].c<=x){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    

    return l-1;
}


int main(){
 
    scanf("%d",&n);

    int nc;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&cards[i].c,&cards[i].r);   
        cards[i].i=i;
        nc=cards[i].c;
    }
    
    if(n==1){
    	if(cards[1].c>1){
    		printf("No such luck\n");
        	return 0;
    	}
    }
    
    sort(cards+1,cards+n+1,cmp);


    for(int i=1;i<=n;i++){
        A[i]=cards[i].r;
    }
    A[0]=-110000;

    build(1,n,1);


    int ttt=lowb(1);
   // cout<<ttt<<endl;

    vector<int> ans; 
    int i=query(1,ttt,1,n,1);
    
	if(i==-1){
        printf("No such luck\n");
        return 0;
    }
    
    //cout<<i<<endl;
    
    ans.push_back(cards[i].i);

    bool flag=1;

    while(cards[i].r<nc){
        int temp=i;
       // cout<<cards[i].r<<endl;
        ttt=lowb(cards[i].r);
      //  cout<<ttt<<endl;
        i=query(1,ttt,1,n,1);

   		if(i==temp){    
      		flag=0;
     	    break;
    	}
        ans.push_back(cards[i].i);
    }
    
    if(ans.back()==n)
    	ans.pop_back();

    if(flag){
    	ans.push_back(n);
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        if(i!=ans.size()-1)
        printf("%d ",ans[i]);
        else
        printf("%d\n",ans[i]);
    }
    else
    printf("No such luck\n");





    return 0;
}