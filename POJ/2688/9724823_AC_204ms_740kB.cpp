#include <iostream>  
#include <queue>  
#include <cstring>  
#include <algorithm>  
#include <stdio.h>  
using namespace std;  
char mp[50][50];  
int dis[50][50];  
int vis[50][50];  
int tag[50][50];  
const int inf =99999999;  
struct node  
{  
    int x,y,step;  
}point[500];  
int w,h,cnt,ans;  
void bfs(node fir,int pt)  
{  
    queue <node > s;  
    fir.step=0;  
    while(!s.empty())  
        s.pop();  
    vis[fir.x][fir.y]=1;  
    s.push(fir);  
    while(!s.empty())  
    {  
        node t=s.front();  
        s.pop();  
        if(mp[t.x][t.y]=='*'||mp[t.x][t.y]=='o')  
            dis[ pt ] [ tag[t.x][t.y] ]=t.step;  
        int next[4][2]={0,1,0,-1,1,0,-1,0};  
        for(int i=0;i<4;i++)  
        {  
            node temp=t;  
            temp.x+=next[i][0];  
            temp.y+=next[i][1];  
            if(temp.x<1||temp.y<1||temp.x>h||temp.y>w||vis[temp.x][temp.y]==1||mp[temp.x][temp.y]=='x')  
            {  
                continue;  
            }  
            temp.step+=1;  
            s.push(temp);  
            vis[temp.x][temp.y]=1;  
        }  
  
    }  
}  
int vist[50];  
void dfs(int x,int step,int s)  
{  
    if(step==cnt)  
    {  
        ans=min(s,ans);  
        return ;  
    }  
    if(s>ans)  
        return ;  
    for(int i=1;i<=cnt;i++)  
    {  
        if(vist[i])  
            continue;  
        vist[i]=1;  
        dfs(i,step+1,s+dis[x][i]);  
        vist[i]=0;  
    }  
}  
  
int main()  
{  
    while(~scanf("%d%d",&w,&h) )  
    {  
        if(w==0&&h==0)  
        break;  
        cnt=0;  
        getchar();  
        memset(point,0,sizeof(point));  
        memset(tag,0,sizeof(tag));  
        memset(dis,0,sizeof(dis));  
        for(int i=1;i<=h;i++)  
        {  
            for(int j=1;j<=w;j++)  
                {  
                scanf("%c",&mp[i][j]);  
                if(mp[i][j]=='*')  
                {  
                    point[++cnt].x=i;  
                    point[cnt].y=j;  
                    tag[i][j]=cnt;  
                }  
                else if(mp[i][j]=='o')  
                {  
                    tag[i][j]=0;  
                    point[0].x=i;  
                    point[0].y=j;  
                }  
                }  
            getchar();  
        }  
        /*for(int i=1;i<=h;i++) 
        { 
            for(int j=1;j<=w;j++) 
                cout<<mp[i][j]; 
            cout<<endl; 
        } 
        cout<<"xxxx"<<endl;*/  
        for(int i=0;i<=cnt;i++)  
        {  
            for(int j=0;j<=cnt;j++)  
            {  
                if(i!=j)  
                    dis[i][j]=inf;  
                else  
                    dis[i][j]=0;  
            }  
        }  
        for(int i=0;i<=cnt;i++)  
        {  
            memset(vis,0,sizeof(vis));  
            bfs( point[i],i );  
        }  
      /*  for(int i=0;i<=cnt;i++) 
        { 
            for(int j=0;j<=cnt;j++) 
                cout<<dis[i][j]<<" "; 
            cout<<endl; 
        }*/  
        bool flag=1;  
        for(int i=0;i<=cnt && flag;i++)  
            for(int j=0;j<=cnt && flag;j++)  
                if(dis[i][j]==inf)  
                    flag=0;  
        if(!flag)  
        {  
            printf("-1\n");  
            continue;  
        }  
        memset(vist,0,sizeof(vist));  
        vist[0]=1;  
        ans=inf;  
        dfs(0,0,0);  
        printf("%d\n",ans);  
  
    }  
}  