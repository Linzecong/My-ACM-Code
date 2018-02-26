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

int firstshort[10050];
int secondshort[10050];
int dp[10050];

int w[10050];
vector<int> childs[10050];

void dfsPath(int v){

    int fir=0;
    int sec=0;

    for(int i=0;i<childs[v].size();i++){
        int child=childs[v][i];
        dfsPath(child);
        int cost=firstshort[child]+w[child];
        if(cost>fir){
            sec=fir;
            fir=cost;
        }
        else{
            if(cost>sec)
                sec=cost;
        }
    }
    firstshort[v]=fir;
    secondshort[v]=sec;
}


void dfs(int v){

    for(int i=0;i<childs[v].size();i++){
        int ch=childs[v][i];
        int len=w[ch];

        dp[ch]=max(dp[v],firstshort[ch]+len==firstshort[v]?secondshort[v]:firstshort[v])+len;

        dfs(ch);
    }

}




int main()
{

    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++)
            childs[i].clear();

        memset(firstshort,0,sizeof(firstshort));
        memset(secondshort,0,sizeof(secondshort));
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        for(int k=2;k<=n;k++){
            int fa,num;
            scanf("%d%d",&fa,&num);
            childs[fa].push_back(k);
            w[k]=num;
        }



        dfsPath(1);
        dfs(1);




        for(int i=1;i<=n;i++)
            printf("%d\n",max(firstshort[i],dp[i]));

    }

    return 0;
}
