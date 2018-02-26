#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
typedef long long int ll;

/*这是个稀疏图！！！剪枝很巧妙！
假设从1号点出发，到达2号点有三条路，第一条路长度为4，第二条路长度为11。

假设K为7：那么第一条路和第二条路只需要搜索一次，不需要重复搜索。

为什么呢？因为4%7=4  11%7=4 ，还不懂？
*/
vector<int> E[1005];

int maze[1005][1005];

int vis[1005][1005];


char str[1005];

ll step0,pos0;
int n,m,s,k;


void dfs(ll cur,ll step){
    if(step%k==0&&str[cur-1]=='P'){
        if(step<=step0){
            if(step==step0){
                if(cur<pos0)
                    pos0=cur;
            }
            else{
                pos0=cur;
            }
            step0=step;
        }
        return;
    }


        for(int i=0;i<E[cur].size();i++){
            
            int to=E[cur][i];
            int w=maze[cur][to];
            
            if(vis[to][step+w%k]==-1||(step+w)<vis[to][step+w%k]){
                vis[to][step+w%k]=step+w;
                dfs(to,step+w);
            }
        }

}



int main(){


    int t;
    cin>>t;

    for(int qqq=1;qqq<=t;qqq++){


        scanf("%d%d%d%d",&n,&m,&s,&k);

        scanf("%s",str);


        memset(maze,0,sizeof(maze));
        memset(E,0,sizeof(E));
        memset(vis,-1,sizeof(vis));

        int ii,jj;

        for(int i=0;i<m;i++){
            scanf("%d%d",&ii,&jj);

            scanf("%d",&maze[ii][jj]);

            E[ii].push_back(jj);
        }

        step0=9999999999;
        pos0=9999999999;


        dfs(s,0);

        if(pos0!=9999999999)
            printf("Case %d: %lld %lld\n",qqq,step0,pos0);
        else
            printf("Case %d: %d %d\n",qqq,-1,-1);


    }

    return 0;
}
