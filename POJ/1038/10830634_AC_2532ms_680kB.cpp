#include<iostream>

#include<string.h>
#include<math.h>
using namespace std;

const int N = 60000;
int block[155][11];
int dp[2][N];

int three[11];
int preblock[11];
int nowblock[11];

int n, m, K, mask;

int getState(int f[]){
    int res = 0;
    for(int i = 1; i <= m; i++)
        res += (f[i]*three[i-1]);
    return res;
}

void getBlock(int x,int f[]){
    for(int i = 1; i <= m; i++){
        f[i] = x%3;
        x /= 3;
    }
}


void dfs(int i,int x,int num) {
    if(x>m)
        return;

    int cur=(i+1)&1;
    int nxt=i&1;
    int k=getState(nowblock) ;

    dp[nxt][k]=max(dp[nxt][k],dp[cur][getState(preblock)]);


    if((x<=(m-1)) && ((preblock[x]==0) && (preblock[x+1]==0) ) && ( (nowblock[x]==0)&&(nowblock[x+1]==0))  ){
        nowblock[x] = nowblock[x+1] = 2;
        int kk = getState(nowblock);
        dp[nxt][kk] = max( dp[nxt][kk], num+1 );
        dfs( i, x+2, num+1 );
        nowblock[x] = nowblock[x+1] = 0;
    }


    if( (x<=(m-2)) && ( (!nowblock[x])&&(!nowblock[x+1])&&(!nowblock[x+2]) )  ){
        nowblock[x]=nowblock[x+1]=nowblock[x+2] = 2;
        int kk = getState(nowblock);
        dp[nxt][kk] = max( dp[nxt][kk], num+1 );
        dfs( i, x+3, num+1);
        nowblock[x]=nowblock[x+1]=nowblock[x+2] = 0;
    }

    dfs( i, x+1, num );
}

void solve()
{

    memset( dp, 0xff, sizeof(dp) );
    memset( preblock, 0, sizeof(preblock));
    memset( nowblock, 0, sizeof(nowblock));
    for(int i = 1; i <= m; i++)
        preblock[i] = block[1][i]+1;

    dp[1][ getState(preblock) ] = 0;

    mask = three[m];

    for(int i = 2; i <= n; i++)
    {
        int cur = (i+1)&1, nxt= i&1;

        memset( dp[nxt], 0xff, sizeof(dp[nxt]) );

        for(int j = 0; j < mask; j++){

            if( dp[cur][j] == -1 )
                continue;

            getBlock( j, preblock );


            for(int x = 1; x <= m; x++)
            {
                if( block[i][x] ) nowblock[x] = 2;
                else
                {
                    nowblock[x] = preblock[x]-1;
                    if( nowblock[x] < 0 ) nowblock[x] = 0;
                }
            }

            dfs( i, 1,  dp[cur][j] );
        }
    }

    int ans = 0;
    for(int i = 0; i < mask; i++)
        ans = max( ans, max(dp[0][i],dp[1][i]) );
    printf("%d\n", ans );
}

int main()
{

    three[0] = 1;
    for(int i = 1; i <= 10; i++ )three[i]=3*three[i-1];
    
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d", &n,&m,&K);
        int x, y;
        memset( block, 0, sizeof(block));

        for(int i = 0; i < K; i++){
            scanf("%d%d",&x,&y);
            block[x][y] = 1;
        }

        solve();
    }
    return 0;
}
