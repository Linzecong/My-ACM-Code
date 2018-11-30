#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];

int dp[(1<<16)+10][MAXN];

int n,M;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&M);
        int u,v,w;

        memset(G,0x3f,sizeof(G));
        memset(dp,0x3f,sizeof(dp));

        for(int i=0;i<=n;i++)
            G[i][i]=0;

        for(int i=0;i<M;i++){
            scanf("%d%d%d",&u,&v,&w);
            u--;
            v--;
            if(w<G[u][v]){
                G[u][v]=w;
                G[v][u]=w;
            }
        }

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

        //        dp[1][0]=0;
        //        for(int s=1;s<(1<<N);s++){
        //            for(int i=0;i<N;i++){
        //                if(s&(1<<i)){
        //                    for(int j=0;j<N;j++)
        //                        if((s&(1<<j))==0)
        //                            dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + G[i][j]);
        //                }
        //            }
        //        }

        for(int s=0;s<(1<<(n-1));s++)
            for(int i=1;i<n;i++)
                if(s&(1<<(i-1))){
                    if(s==(1<<(i-1))) dp[s][i]=G[0][i];
                    else{
                        dp[s][i]=INF;
                        for(int j=1;j<n;j++)
                            if(s&(1<<(j-1))&&j!=i)
                                dp[s][i]=min(dp[s][i],dp[s^(1<<(i-1))][j]+G[j][i]);
                    }
                }

        int ans=dp[(1<<(n-1))-1][1]+G[1][0];
        for(int i=2;i<n;i++)
            ans=min(ans,dp[(1<<(n-1))-1][i]+G[i][0]);

        if (n== 1)
            printf("0\n");
        else
            printf("%d\n", ans);

    }

    return 0;
}

