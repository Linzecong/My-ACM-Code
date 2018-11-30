#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
    int from;
    int to;
    int w;
    int next;
}e[200000];
int head[10000];
int vis[10000];
int out[10000];
int dis[10000];
int n,ml,dl,cont;
void add(int from,int to,int w)
{
    e[cont].to=to;
    e[cont].w=w;
    e[cont].next=head[from];
    head[from]=cont++;
}
void SPFA()
{
    for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    memset(out,0,sizeof(out));
    queue<int >s;
    s.push(1);
    int flag=0;
    while(!s.empty())
    {
        int u=s.front();
        out[u]++;
        if(out[u]>n)
        {
            flag=1;
            break;
        }
        s.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            int w=e[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    s.push(v);
                }
            }
        }
    }
    if(flag==1)
    {
        printf("-1\n");
    }
    else if(dis[n]==0x3f3f3f3f)printf("-2\n");
    else printf("%d\n",dis[n]);
}
int main()
{
    while(~scanf("%d%d%d",&n,&ml,&dl))
    {
        cont=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<ml;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
        }
        for(int i=0;i<dl;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(y,x,-w);
        }
        SPFA();
    }
}
