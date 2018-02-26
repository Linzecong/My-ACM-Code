#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
typedef long long int ll;

int dp[5000];

struct node{
    int x;
    int y;

    int z;
}list[6000];

bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}

int main(){


    int qqq=1;


    while(1){






        memset(list,0,sizeof(list));
memset(dp,0,sizeof(dp));

        int n;
        cin>>n;

        if(n==0)
            break;


        for(int i=0;i<n*6;i+=6){
            cin>>list[i].x>>list[i].y>>list[i].z;

            list[i+1].y=list[i].x;
            list[i+1].z=list[i].y;
            list[i+1].x=list[i].z;

            list[i+2].y=list[i].z;
            list[i+2].z=list[i].x;
            list[i+2].x=list[i].y;

            list[i+3].y=list[i].x;
            list[i+3].z=list[i].z;
            list[i+3].x=list[i].y;

            list[i+4].y=list[i].y;
            list[i+4].z=list[i].x;
            list[i+4].x=list[i].z;

            list[i+5].y=list[i].z;
            list[i+5].z=list[i].y;
            list[i+5].x=list[i].x;

        }

        sort(list,list+n*6,cmp);



        int res=0;
        for(int i=0;i<n*6;i++){
            dp[i]=list[i].z;
            if(list[i].x==-1)
                break;
            for(int j=0;j<i;j++)
                if(list[j].y>list[i].y&&list[j].x>list[i].x){
                    dp[i]=max(dp[i],dp[j]+list[i].z);
                }
            res=max(res,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",qqq++,res);


    }

    return 0;
}
