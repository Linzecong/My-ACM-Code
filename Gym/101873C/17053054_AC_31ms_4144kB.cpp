#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int>G[1005];
int dp[1005][1005];
int t[1005],p[1005];
int T,n,m,t1,u,v;
int main(){
    memset(dp,0x3f,sizeof(dp));
    scanf("%d%d%d%d",&T,&n,&m,&t1);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        scanf("%d%d",&t[i],&p[i]);
    if (t[1]>=T){
        cout << "It is a trap." << endl;
        return 0;
    }
    int M=dp[0][0];
    dp[1][t[1]]=p[1];
    for (int j=t[1];j<=T;j++){
        for (int i=1;i<=n;i++){
            if (j+t[i]<=T)
                dp[i][j+t[i]]=min(dp[i][j+t[i]],dp[i][j]+p[i]);
            if (j+t1>T) 
                continue;
            for (int k=0;k<G[i].size();k++){
                int v=G[i][k];
                if (j+t1+t[v]>T)
                    continue;
                dp[v][j+t1+t[v]]=min(dp[v][j+t1+t[v]],dp[i][j]+p[v]);
            }
        }
    }
    if (dp[1][T]==M) cout << "It is a trap." << endl;
    else cout << dp[1][T] << endl;
}
