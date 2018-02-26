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
#define MAXV 2000005
#define INF (1LL<<62)
using namespace std;
typedef long long int ll;

int dp[16050];//记录以i为根节点的所有子树中，权值和最大的那个权值
int fa[16050];//记录父亲
vector<int> childs[16050];

//从下往上递归
void dfs(int v,int fa){

    for(int i=0;i<childs[v].size();i++){
        int ch=childs[v][i];
        if(ch==fa)
            continue;
        dfs(ch,v);
        dp[v]+=max(0,dp[ch]);//是正数就肯定取
    }
}


int main()
{

    int n;
    scanf("%d",&n);
    memset(fa,-1,sizeof(fa));

    for(int k=1;k<=n;k++)
        scanf("%d",&dp[k]);

    int a,b;
    for(int k=2;k<=n;k++){
        scanf("%d%d",&a,&b);
        childs[a].push_back(b);
        childs[b].push_back(a);
    }


    dfs(1,0);

    int ans=-1000000;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);

    return 0;
}
