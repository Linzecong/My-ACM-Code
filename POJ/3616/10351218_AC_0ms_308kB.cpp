#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define ll long long
using namespace std;

int N,M,R;

struct interval{
    int l;
    int r;
    int e;
}list[10050];

bool cmp(interval a,interval b){
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

int dp[10050];

int main(){

    while(~scanf("%d%d%d",&N,&M,&R)){

       for(int i=0;i<M;i++){
           scanf("%d%d%d",&list[i].l,&list[i].r,&list[i].e);
           list[i].r+=R;
       }

       memset(dp,0,sizeof(dp));

        sort(list,list+M,cmp);

        for(int i=0;i<M;i++)
            dp[i]=list[i].e;


        for(int i=1;i<M;i++)
            for(int j=0;j<i;j++)
                if(list[i].l>=list[j].r)
                    dp[i]=max(dp[i],dp[j]+list[i].e);





        int maxnum=dp[0];
        for(int i=1;i<M;i++)
            maxnum=max(maxnum,dp[i]);

        cout<<maxnum<<endl;

    }

    return 0;
}
