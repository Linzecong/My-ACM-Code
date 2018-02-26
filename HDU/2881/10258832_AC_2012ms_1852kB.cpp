#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN=10005;
int N,M;
int dp[MAXN];

struct mission{
    int t;
    int x;
    int y;
    mission(int a=0,int b=0,int c=0){
        t=a;
        x=b;
        y=c;
    }
}list[MAXN];
bool cmp(mission a,mission b){
    return a.t<b.t;
}

bool judge(mission a,mission b)
{
    int len=abs(b.x-a.x)+abs(b.y-a.y);
    if(len>abs(b.t-a.t))
        return false;
    return true;
}

int main(){
    
    
    while(~scanf("%d%d",&N,&M)){
        if(N==0&&M==0)
            break;
        
        for(int i=0;i<M;i++)
            scanf("%d%d%d",&list[i].t,&list[i].x,&list[i].y);
        
        memset(dp,0,sizeof(dp));
        sort(list,list+M,cmp);
        
        
        int ans=0;
        for(int i=0;i<M;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(judge(list[j],list[i]))
                    dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>ans)ans=dp[i];            
        }
        
        
        printf("%d\n",ans);
    }
    
    
    return 0;
}
