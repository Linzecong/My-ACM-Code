#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <memory.h>
#include <stack>

using namespace std;


int G[105][105];
int n,m;
int inset[105];
int chosen[105];
int nownum;
int bestnum;
void dfs(int i){
    if(i>n){
        memcpy(chosen,inset,sizeof(chosen));
        bestnum=nownum;
        return;
    }

    bool flag=1;
    for(int j=0;j<nownum;j++){
        if( G[i][inset[j]]==0){
            flag=false;
            break;
        }
    }

    if(flag){
        inset[nownum++]=i;
        dfs(i+1);
        nownum--;
    }
    if(nownum+(n-i)>bestnum)
        dfs(i+1);

}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int a,b;
        memset(inset,0,sizeof(inset));
        memset(G,1,sizeof(G));
        nownum=0;
        bestnum=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            G[a][b]=0;
            G[b][a]=0;
        }
        dfs(1);

        printf("%d\n",bestnum);
        for(int i=0;i<bestnum;i++){
            if(i!=bestnum-1)
                printf("%d ",chosen[i]);
            else
                printf("%d\n",chosen[i]);
        }


    }

    return 0;

}
