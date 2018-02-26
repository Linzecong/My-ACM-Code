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
int fa[200];
vector<int> childs[200];
int n,p;


void dfs(int v,int fa){

    dp[v][1]=childs[v].size()-(v!=fa);

    for(int i=0;i<childs[v].size();i++){
        int ch=childs[v][i];
        if(ch==fa)
            continue;
        dfs(ch,v);

        for(int j=p;j>0;j--)
            for(int s=1;s<j;s++)
                dp[v][j]=min(dp[v][j-s]+dp[ch][s]-1,dp[v][j]);
    }
}


int main()
{

    while(~scanf("%d%d",&n,&p)){

        memset(dp,0x3f3f3f3f,sizeof(dp));
        memset(fa,-1,sizeof(fa));

        int a,b;
        for(int i=2;i<=n;i++){
            scanf("%d%d",&a,&b);
            childs[a].push_back(b);
            childs[b].push_back(a);
            fa[b]=a;
        }

        int i=1;
        while(fa[i]!=-1)
            i=fa[i];

        dfs(i,i);

        int ans=dp[i][p];
        for(int j=1;j<=n;j++)
            ans=min(ans,dp[j][p]+1);

        printf("%d\n",ans);

        for(int i=0;i<=n;i++)
            childs[i].clear();
    }

    return 0;
}
