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

int dp[26050];//记录以i为根节点的所有子树中，权值和最大的那个权值
vector<int> childs[26050];

map<pair<int,int>,int> vis;

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
    while(~scanf("%d",&n)){

        vis.clear();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            childs[i].clear();


        int a,b,c;
        for(int k=1;k<=n;k++){
            scanf("%d%d%d",&a,&b,&c);

            vis[make_pair(a,b)]=k;
            dp[k]=c;

            int l=vis[make_pair(a-1,b)];
            int r=vis[make_pair(a+1,b)];
            int u=vis[make_pair(a,b-1)];
            int d=vis[make_pair(a,b+1)];

            if(l){
                childs[k].push_back(l);
                childs[l].push_back(k);
            }
            if(r){
                childs[k].push_back(r);
                childs[r].push_back(k);
            }
            if(u){
                childs[k].push_back(u);
                childs[u].push_back(k);
            }
            if(d){
                childs[k].push_back(d);
                childs[d].push_back(k);
            }

        }



        dfs(1,0);

        int ans=-10000000;
        for(int i=1;i<=n;i++)
            ans=max(ans,dp[i]);
        printf("%d\n",ans);

    }

    return 0;
}
