#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN=105;
int N,M;
int dp[MAXN][MAXN];
int a[MAXN];
int b[MAXN];

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=M;i++)
            scanf("%d",&b[i]);

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]));

                if(a[i]!=b[j]){
                    int k1,k2;
                    for(k1=i-1;k1>=1;k1--)
                        if(a[k1]==b[j])
                            break;
                    for(k2=j-1;k2>=1;k2--)
                        if(b[k2]==a[i])
                            break;

                    if(k1&&k2)
                    dp[i][j]=max(dp[i][j],dp[k1-1][k2-1]+2);

                }
            }


        printf("%d\n",dp[N][M]);
    }


    return 0;
}
