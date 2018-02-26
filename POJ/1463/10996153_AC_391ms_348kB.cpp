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

int dp[1505][2];
int far[1505];

vector<int> childs[1505];


void dfs(int v){
    dp[v][1]=1;
    dp[v][0]=0;

    for(int i=0;i<childs[v].size();i++){
        dfs(childs[v][i]);
        dp[v][0]+=dp[childs[v][i]][1];
        dp[v][1]+=min(dp[childs[v][i]][0],dp[childs[v][i]][1]);
    }

}


int main()
{

    int n;
    while(~scanf("%d",&n)){
        memset(far,-1,sizeof(far));
        for(int k=0;k<n;k++){
            int fa,num;
            scanf("%d:(%d)",&fa,&num);
            childs[fa].clear();
            for(int i=0;i<num;i++){
                int temp;
                scanf("%d",&temp);
                childs[fa].push_back(temp);
                far[temp]=fa;
            }
        }

        //找到根节点
        int i=0;
        while(far[i]!=-1)
            i=far[i];

        dfs(i);

        printf("%d\n",min(dp[i][0],dp[i][1]));

    }

    return 0;
}
