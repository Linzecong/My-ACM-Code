#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
int t,n,m;
int vis[12][12];
int dir[4][2]= {-1,0,1,0,0,-1,0,1};
char mat[12][12];
struct node
{
    int x,y,t;
    node(int xx,int yy,int tt)
    {
        x=xx;
        y=yy;
        t=tt;
    }
};
int bfs(node a,node b)
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    vis[a.x][a.y]=1;
    vis[b.x][b.y]=1;
    q.push(a);
    q.push(b);
    int res=0;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        res=a.t;
        for(int i=0;i<4;i++)
        {
            int dx=a.x+dir[i][0];
            int dy=a.y+dir[i][1];
            if(dx<0||dy<0||dx>=n||dy>=m||mat[dx][dy]!='#'||vis[dx][dy]) continue;
            vis[dx][dy]=1;
            q.push(node(dx,dy,res+1));
        }
    }
    return res;
}
vector<node> v;
int main()
{
    cin>>t;
    int num=0;
    while(t--)
    {
        num++;
        v.clear();
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>mat[i];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]=='#') v.push_back(node(i,j,0));
            }
        }
        if(v.size()==1)
        {
            cout<<"Case "<<num<<": "<<0<<endl;
            continue;
        }
        int ans=0x3f3f3f3f;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                int tmp=bfs(v[i],v[j]);
                int ok=1;
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        if(vis[i][j]==0&&mat[i][j]=='#')
                        {ok=0;break;}
                    }
                    if(!ok)
                    {
                        break;
                    }
                }
                if(ok)
                {
                    ans=min(ans,tmp);
                }
            }
        }
        if(ans==0x3f3f3f3f) cout<<"Case "<<num<<": "<<-1<<endl;
        else cout<<"Case "<<num<<": "<<ans<<endl;
    }
    return 0;
}