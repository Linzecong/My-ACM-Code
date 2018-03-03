#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <memory.h>
#include <stack>
#include <string.h>

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

char str[3000];
int main()
{

    while(~scanf("%d",&n)){
        if(n==0)
            break;
        memset(inset,0,sizeof(inset));
        memset(G,0,sizeof(G));
        nownum=0;
        bestnum=0;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            int len=strlen(str);
            for(int j=2;j<len;j++){
                G[str[j]-'A'+1][str[0]-'A'+1]=1;
                G[str[0]-'A'+1][str[j]-'A'+1]=1;
            }
        }
        dfs(1);//从第一个节点开始深搜

        if(bestnum==1)
            printf("%d channel needed.\n",bestnum);
        else
            printf("%d channels needed.\n",bestnum);

    }

    return 0;

}
