#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>
#define INF 1<<29
using namespace std;

int N;

int dp[205][205][205];
int a[205];

int col[205];
int len[205];

int dfs(int l,int r,int rlen){

    if(dp[l][r][rlen]!=-1)
        return dp[l][r][rlen];

    if(l==r)
        return (len[r]+rlen)*(len[r]+rlen);

    int maxscore=(len[r]+rlen)*(len[r]+rlen)+dfs(l,r-1,0);

    for(int k=l;k<=r-1;k++){
        if(col[k]!=col[r])
            continue;

        int tempmax=dfs(l,k,len[r]+rlen)+dfs(k+1,r-1,0);
        maxscore=max(maxscore,tempmax);


    }
    dp[l][r][rlen]=maxscore;
    return maxscore;

}


int main(){

    int t;
    scanf("%d",&t);
    for(int qqq=1;qqq<=t;qqq++){

        scanf("%d",&N);

        memset(dp,-1,sizeof(dp));
        memset(col,0,sizeof(col));
        memset(len,0,sizeof(len));


        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);

        int duan=1;
        int nowcol=a[1];
        col[duan]=nowcol;
        len[duan]++;

        for(int i=2;i<=N;i++){
            if(a[i]==nowcol)
                len[duan]++;
            else{
                duan++;
                nowcol=a[i];
                col[duan]=a[i];
                len[duan]++;
            }
        }

        printf("Case %d: %d\n",qqq,dfs(1,duan,0));

    }

    return 0;
}
