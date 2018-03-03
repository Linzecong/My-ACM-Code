#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <memory.h>
#include <stack>
#include <string.h>

using namespace std;

int n,m;
int ans;
int G[200][200];
int all[200][200];//第j个极大团所包含的节点
int some[200][200];
int none[200][200];

void dfs(int x,int an,int sn,int nn){
    if(!sn&&!nn){
        ans++;
       // for(int i=1;i<=an;i++)
       //     cout<<all[x][i]<<" ";
       // cout<<endl;
    }
    if(ans>1000)
        return;

    int key=some[x][1];
    for(int j=1;j<=sn;j++){
        int v=some[x][j];
        int tsn=0;
        int tnn=0;

        if(G[key][v])
            continue;

        for(int i=1;i<=an;i++)
            all[x+1][i]=all[x][i];
        all[x+1][an+1]=v;

        for(int i=1;i<=sn;i++)
            if(G[v][some[x][i]])
                some[x+1][++tsn]=some[x][i];

        for(int i=1;i<=nn;i++)
            if(G[v][none[x][i]])
                none[x+1][++tnn]=none[x][i];

        dfs(x+1,an+1,tsn,tnn);

        some[x][j]=0;
        none[x][++nn]=v;
    }

}

int main()
{

    while(~scanf("%d%d",&n,&m)){
        ans=0;
        memset(G,0,sizeof(G));
        int a,b;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            G[a][b]=1;
            G[b][a]=1;

        }

        for(int i=1;i<=n;i++)
            some[1][i]=i;

        dfs(1,0,n,0);

        if(ans > 1000)
            puts("Too many maximal sets of friends.");
        else
            printf("%d\n", ans);


    }

    return 0;

}
