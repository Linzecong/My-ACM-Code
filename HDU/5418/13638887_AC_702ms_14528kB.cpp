#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];

int dp[(1<<16)+10][MAXN];

int N,M;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        int u,v,w;

        memset(G,0x3f,sizeof(G));
        memset(dp,0x3f,sizeof(dp));

        for(int i=0;i<=N;i++)
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

        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

        dp[1][0]=0;
        for(int s=1;s<(1<<N);s++){
            for(int i=0;i<N;i++){
                if(s&(1<<i)){
                    for(int j=0;j<N;j++)
                        if((s&(1<<j))==0)
                            dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + G[i][j]);
                }
            }
        }


        int ans = 0x3f3f3f3f;
        for (int i = 1; i < N; i++)
            ans = min(ans, dp[(1 << N) - 1][i] + G[i][0]);

        if (N== 1)
            printf("0\n");
        else
            printf("%d\n", ans);

    }

    return 0;
}

