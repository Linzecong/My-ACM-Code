#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int maxn=100010;

int n,m,time,cnt,dfn[maxn],low[maxn],belong[maxn],sum[maxn],in[maxn],out[maxn];
bool visited[maxn];
vector <int > G[maxn];
stack <int > st;

void initial()
{
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(sum,0,sizeof(sum));
    memset(belong,0,sizeof(belong));
    memset(visited,0,sizeof(visited));
    while(!st.empty()) st.pop();
    for(int i=0; i<maxn; i++)  G[i].clear();
    time=1;
    cnt=0;
}

void input()
{
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
    }
}

void tarjan(int u)
{
    dfn[u]=low[u]=time++;
    st.push(u);
    visited[u]=1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!dfn[v])
        {

            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(visited[v])  low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        while(1)
        {
            int t=st.top();
            st.pop();
            belong[t]=cnt;
            sum[cnt]++;
            visited[t]=0;
            if(t==u)  break;
        }
    }
}

void ready()
{
    for(int i=1; i<=n; i++)
        for(int j=0; j<G[i].size(); j++)
        {
            int u=belong[i],v=belong[G[i][j]];
            if(u!=v)
            {
                out[u]++;
                in[v]++;
            }
        }
}

long long get_ans()
{
    long long ans=-1;
    for(int i=1; i<=cnt; i++)
    {
        if(!in[i] || !out[i])
        {
            long long x=sum[i],y=n-sum[i];
            ans=max(ans,x*(x-1)+y*(y-1)+x*y-m);
        }
    }
    return ans;
}

void solve(int co)
{
    for(int i=1; i<=n; i++)  if(!dfn[i]) tarjan(i);
    if(cnt==1)
    {
        printf("Case %d: -1\n",co);
        return ;
    }
    ready();
    printf("Case %d: %I64d\n",co,get_ans());
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int co=1; co<=T; co++)
    {
        initial();
        input();
        solve(co);
    }
    return 0;
}
