#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN=1000005;

int dp[MAXN];//保存从0~i的最大和
int Max[MAXN];//保存从0~i的最大和


int a[MAXN];
int N,M;

int main(){



    while(~scanf("%d%d",&M,&N)){


        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);

        memset(dp,0,sizeof(dp));
        memset(Max,0,sizeof(Max));

        int ans=-9999999;


        for(int i=1;i<=M;i++){
            ans=-9999999;

            for(int j=i-1;j<N;j++){

                dp[j]=max(dp[j-1]+a[j],Max[j-1]+a[j]);
                Max[j-1]=ans;

                if(dp[j]>ans)
                    ans=dp[j];

            }

        }

        printf("%d\n",ans);






    }


    return 0;
}
