#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 101
bool visited[maxn][maxn];
int m,n,s,si,sj;
struct node
{
    int x,y,all,t;  //x,y,all分别表示m,n,s杯中可乐的体积，t表示倒了多少次
};
void BFS()
{
    queue<node> que;
    memset(visited,false,sizeof(visited));
    node p,q;
    p.x = 0,p.y = 0,p.t = 0,p.all = s;
    que.push(p);
    visited[p.x][p.y] = true;
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        if(p.y == p.all && p.y == s/2)             
        {
            printf("%d\n",p.t);
            return;
        }
        if(p.all+p.x > m)                               //s倒m
        {
            q.x = m,q.y = p.y,q.all = p.all+p.x-m,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = p.all+p.x,q.y = p.y,q.all = 0,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        if(p.all+p.y > n)                                //s倒n
        {
            q.x = p.x, q.y = n, q.all = p.all+p.y-n,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = p.x,q.y = p.all+p.y,q.all = 0,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        if(p.x+p.y > n)                                //m倒n
        {
            q.x = p.x+p.y-n,q.y = n,q.all = p.all,q.t = p.t+1; 
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = 0,q.y = p.x+p.y,q.all = p.all,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        q.all = p.all+p.x,q.x = 0,q.y = p.y,q.t = p.t+1; //m倒s
        if(!visited[q.x][q.y])
            que.push(q),visited[q.x][q.y] = true;  
        if(p.x+p.y > m)
        {
            q.y = p.y+p.x-m,q.x = m,q.all = p.all,q.t = p.t+1;//n倒m
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = p.x+p.y,q.y = 0,q.all = p.all,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        q.all = p.all+p.y,q.x = p.x,q.y = 0,q.t = p.t+1; //n倒s
        if(!visited[q.x][q.y])
            que.push(q),visited[q.x][q.y] = true;
    }
    printf("NO\n");
}
int main()
{
    //freopen("1013.txt","r",stdin);
    while(scanf("%d%d%d",&s,&m,&n) && (s||m||n))
    {
        if(s%2)
        {
            printf("NO\n");
            continue;
        }
        if(m > n) swap(m,n);
        BFS();
    }
    return 0;
}