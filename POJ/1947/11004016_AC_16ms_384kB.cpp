#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;

int dp[200][200];
int chnum[200];
vector<int> childs[200];



void dfs(int v){

    dp[v][1]=childs[v].size();
    chnum[v]=1;

    for(int i=0;i<childs[v].size();i++){
        int ch=childs[v][i];

        dfs(ch);

        chnum[v]+=chnum[ch];

        for(int j=chnum[v];j>0;j--)
            for(int s=1;s<j;s++)
                dp[v][j]=min(dp[v][j-s]+dp[ch][s]-1,dp[v][j]);
        
    }
}


int main()
{

    int n,p;
    while(~scanf("%d%d",&n,&p)){

        memset(dp,0x3f3f3f3f,sizeof(dp));
        memset(chnum,0,sizeof(chnum));

        int a,b;
        for(int i=2;i<=n;i++){
            scanf("%d%d",&a,&b);
            childs[a].push_back(b);
        }

        dfs(1);

        int ans=dp[1][p];
        for(int i=2;i<=n;i++)
            ans=min(ans,dp[i][p]+1);
        printf("%d\n",ans);

        for(int i=0;i<=n;i++)
            childs[i].clear();
    }

    return 0;
}
