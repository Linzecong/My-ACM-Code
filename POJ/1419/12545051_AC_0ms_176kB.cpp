#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <memory.h>
#include <stack>

using namespace std;


int G[105][105];//图
int n,m;
int inset[105];//当前在团中的点
int chosen[105];//最大团的点集合
int nownum;//当前最大团点的数量
int bestnum;//最大团点的数量
void dfs(int i){
    //如果所有节点都被深搜了
    if(i>n){
        memcpy(chosen,inset,sizeof(chosen));//更新最大团的点和数量
        bestnum=nownum;
        return;
    }
    bool flag=1;//当前点是否与当前最大团中的点都相连
    for(int j=0;j<nownum;j++){
        if( G[i][inset[j]]==1){
            flag=false;
            break;
        }
    }
    //是的话，可以加入到最大团中
    if(flag){
        inset[nownum++]=i;
        dfs(i+1);
        nownum--;
    }

    //否则不加人，和一个小小的剪枝
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
        memset(G,0,sizeof(G));//求补图
        nownum=0;
        bestnum=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            G[a][b]=1;//补图
            G[b][a]=1;
        }
        dfs(1);//从第一个节点开始深搜

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
