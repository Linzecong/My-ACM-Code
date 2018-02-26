#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
using namespace std;  
#define N 10010  
#define M 100100  
int n,m;  
int pre[N];  
int flag[N];  
struct Edge  
{  
    int u,v,w;  
} e[M];  
  
void init()  
{  
    for(int i=0; i<n; i++)  
        pre[i]=i;  
    memset(flag,0,sizeof(flag));  
}  
bool cmp(Edge a,Edge b)  
{  
    return a.w>b.w;  
}  
int finds(int x)  
{  
    int r=x;  
    while(r!=pre[r])  
        r=pre[r];  
    int j;  
    while(x!=pre[x])  
    {  
        j=x;  
        x=pre[x];  
        pre[j]=r;  
    }  
    return r;  
}  
int kruskal()  
{  
    int ans=0,x,y;  
    for(int i=0; i<m; i++)  
    {  
        x=finds(e[i].u);  
        y=finds(e[i].v);  
        if(x==y)  
        {  
            if(!flag[x])  
            {  
                flag[x]=1;  
                ans+=e[i].w;  
            }  
            continue;  
        }  
        if(flag[x]&&flag[y]) continue;  
        pre[x]=y;  
        ans+=e[i].w;  
        if(!flag[x]&&!flag[y]) continue;  
        flag[x]=flag[y]=1;  
    }  
    return ans;  
}  
int main()  
{  
    int u,v,w;  
    while(scanf("%d %d",&n,&m)&&n)  
    {  
        init();  
        for(int i=0; i<m; i++)  
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);  
        sort(e,e+m,cmp);  
        printf("%d\n",kruskal());  
    }  
    return 0;  
} 