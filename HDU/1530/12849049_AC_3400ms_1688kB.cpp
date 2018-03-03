#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int G[55][55];

int inset[105];//当前在团中的点  
int nownum;//当前最大团点的数量  
int bestnum;//最大团点的数量  
void dfs(int i){  
    //如果所有节点都被深搜了  
    if(i>n){  
        bestnum=nownum;  
        return;  
    }  
    bool flag=1;//当前点是否与当前最大团中的点都相连  
    for(int j=0;j<nownum;j++){  
        if( G[i][inset[j]]==0){  
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

    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &G[i][j]);

        bestnum=0;
        nownum=0;

        dfs(1);

        printf("%d\n", bestnum);
    }
    return 0;
}