#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200010;
int N,X,Y;
int x[MAXN];
int y[MAXN];

int num[MAXN*2];
int tot=0;
vector<int> G[MAXN];

int ans[MAXN];
int vis[MAXN];
vector<int> used;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&Y);
        tot=0;
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));

        num[tot++]=0;
        for(int i=1;i<=N;i++){
            scanf("%d%d",&x[i],&y[i]);
            G[x[i]].clear();
            G[x[i]+1].clear();
            num[tot++]=x[i];
            num[tot++]=x[i]+1;
        }

        for(int i=1;i<=N;i++)
            G[x[i]].push_back(y[i]);


        sort(num,num+tot);
        tot = unique(num,num+tot)-num;


        int ansmin=0x3f3f3f3f;
        int ansmax=0;

        int pre=0;
        int cnt=0;
        for(int i=0;i<tot;i++){
            X=num[i];
            used.clear();
            ans[X]+=G[X].size();

            for(int j=0;j<G[pre].size();j++){
                int dis=abs(1e5+1-pre)+abs(Y-G[pre][j]);
                vis[dis]++;
                if(vis[dis]==1)
                    cnt++;
                else
                    used.push_back(dis);
            }
            for(int j=0;j<used.size();j++)
            {
                if(vis[used[j]])cnt--;
                vis[used[j]]=0;
            }
            ans[X]+=cnt;
            pre=num[i];
        }

        memset(vis,0,sizeof(vis));
        pre=cnt=0;
        for(int i=tot-1;i>=0;i--){
            X=num[i];
            used.clear();
            for(int j=0;j<G[pre].size();j++){
                int dis=abs(-pre)+abs(Y-G[pre][j]);
                vis[dis]++;
                if(vis[dis]==1)
                    cnt++;
                else
                    used.push_back(dis);
            }
            for(int j=0;j<used.size();j++)
            {
                if(vis[used[j]])cnt--;
                vis[used[j]]=0;
            }
            ans[X]+=cnt;
            ansmin=min(ans[X],ansmin);
            ansmax=max(ans[X],ansmax);
            pre=num[i];
        }
        printf("%d %d\n",ansmin,ansmax);
    }

    return 0;
}
