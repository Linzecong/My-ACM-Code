#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include<queue>
#define INF (1<<29)
using namespace std;
typedef long long ll;


int N,M;
int V[13];
int G[13][13];
int dp[1<<13][13][13];
ll num[1<<13][13][13];


int main(){



    int t;
    scanf("%d",&t);

    while(t--){

        scanf("%d%d",&N,&M);

        for(int i=0;i<N;i++)
            scanf("%d",&V[i]);

        memset(dp,-1,sizeof(dp));
        memset(G,0,sizeof(G));
        memset(num,0,sizeof(num));

        int a,b;
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--,b--;
            G[a][b]=G[b][a]=1;
        }

        if(N==1){
            printf("%d 1\n",V[0]);
            continue;
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(i!=j&&G[i][j]){
                    dp[(1<<i)|(1<<j)][i][j]=V[i]+V[j]+V[i]*V[j];
                    num[(1<<i)|(1<<j)][i][j]=1;
                }


        for(int state=0;state<(1<<N);state++){
            for(int i=0;i<N;i++){
                if((state&(1<<i))!=0){
                    for(int j=0;j<N;j++){
                        if(G[i][j]&&i!=j&&(state&(1<<j))!=0&&dp[state][i][j]!=-1){
                            for(int k=0;k<N;k++){
                                if(G[j][k]&&i!=k&&j!=k&&(state&(1<<k))==0){
                                    int temp=dp[state][i][j]+V[k]+V[j]*V[k];

                                    if(G[i][k])
                                        temp+=V[i]*V[j]*V[k];


                                    if(dp[state|(1<<k)][j][k]<temp){
                                        dp[state|(1<<k)][j][k]=temp;
                                        num[state|(1<<k)][j][k]=num[state][i][j];
                                    }
                                    else{
                                        if(dp[state|(1<<k)][j][k]==temp)
                                            num[state|(1<<k)][j][k]+=num[state][i][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


        int ans1=0;
        ll ans2=0;

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(i!=j&&G[i][j]){
                    if(ans1<dp[(1<<N)-1][i][j]){
                        ans1=dp[(1<<N)-1][i][j];
                        ans2=num[(1<<N)-1][i][j];
                    }
                    else{
                        if(ans1==dp[(1<<N)-1][i][j])
                            ans2+=num[(1<<N)-1][i][j];
                    }
                }

        printf("%d %lld\n",ans1,ans2/2);


    }

    return 0;
}





















