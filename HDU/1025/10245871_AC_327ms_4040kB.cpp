#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>
#define INF 1<<29
using namespace std;
const int MAXN=500005;
int N;
int dp[MAXN];

struct node{
    int p;
    int r;
}list[MAXN];

bool cmp(node a,node b){
    return a.p<b.p;
}

int main(){
    
    int t=1;
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++)
            scanf("%d%d",&list[i].p,&list[i].r);
        sort(list,list+N,cmp);
        
        for(int i=0;i<MAXN;i++)
            dp[i]=INF;
        
        for(int i=0;i<N;i++)
            *lower_bound(dp,dp+N,list[i].r)=list[i].r;
        
        int len=lower_bound(dp,dp+N,INF)-dp;
        
        if(len==1)
            printf("Case %d:\nMy king, at most %d road can be built.\n\n",t++,len);
        else
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n",t++,len);
    }
    
    
    return 0;
}
