#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define INF 1<<29
using namespace std;
typedef long long int ll;

int dp[1005][105][1<<6];
int sta[1005];

int minc[1005];

int h,c;

void dfs(int prestate,int nowstate,int nextstate,int n,int cnt,int cnum,int fnum){

    if(cnum>c)
        return;

    if(n>=5){


        dp[cnt+1][cnum][nextstate]|=dp[cnt][fnum][prestate]&1;
        minc[cnt+1]=min(minc[cnt+1],cnum);
        return;
    }

    if(((1<<n)&nowstate)!=0){
        dfs(prestate,nowstate,nextstate,n+1,cnt,cnum,fnum);//下一个
        return;
    }


    dfs(prestate,nowstate|(1<<n),nextstate,n+1,cnt,cnum+1,fnum);


    if((nextstate&(1<<n))==0){
        dfs(prestate,nowstate|(1<<n),nextstate|(1<<n),n+1,cnt,cnum,fnum);
    }



    if(n!=0)
        if((nextstate&(1<<n))==0&&(nextstate&(1<<(n-1)))==0)
            dfs(prestate,nowstate|(1<<n),nextstate|(1<<n)|(1<<(n-1)),n+1,cnt,cnum,fnum);

    if(n<4)
        if((nextstate&(1<<n))==0&&(nextstate&(1<<(n+1)))==0)
            dfs(prestate,nowstate|(1<<n),nextstate|(1<<n)|(1<<(n+1)),n+1,cnt,cnum,fnum);

    if(n<4&&((1<<(n+1))&nowstate)==0){
        dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate,n+2,cnt,cnum,fnum);

        if((nextstate&(1<<n))==0)
            dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate|(1<<n),n+2,cnt,cnum,fnum);

        if((nextstate&(1<<(n+1)))==0)
            dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate|(1<<(n+1)),n+2,cnt,cnum,fnum);


        if((nextstate&(1<<n))==0&&(nextstate&(1<<(n+1)))==0)
            dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate|(1<<n)|(1<<(n+1)),n+2,cnt,cnum,fnum);

    }

}


int main(){

    while(~scanf("%d%d",&h,&c)){


        memset(dp,0,sizeof(dp));
        memset(sta,0,sizeof(sta));
        memset(minc,0,sizeof(minc));
        dp[1][0][0]=1;


        char str[10];
        int sss=0;
        for(int i=1;i<=h;i++){
            scanf("%s",str);
            sss=0;
            for(int i=0;i<5;i++){
                if(str[i]=='1'){
                    sss|=(1<<(5-i-1));
                }
            }
            sta[i]=sss;

        }



        int state=1<<5;

        for(int i=1;i<=h;i++){

            for(int k=0;k<=c;k++)
                if(dp[i][k][0]==1)
                    dp[i][k][sta[i]]=1;


            for(int j=0;j<state;j++){
                j|=sta[i];

                for(int k=0;k<=c;k++)
                    dfs(j,j,sta[i+1],0,i,k,k);
            }
        }



        bool flag=0;

        for(int k=0;k<=c;k++)
            if(dp[h+1][k][0])
                flag=1;

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
