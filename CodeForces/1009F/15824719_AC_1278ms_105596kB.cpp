#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 1001105;

inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}

struct edge{
    int v,next;
}e[MAXN<<1];

int edge_num=1;
int head[MAXN];
void insert_edge(int u,int v){
    e[edge_num].v=v;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

int md[MAXN];//当前点的重链的最大深度
int dep[MAXN];//当前点的深度
int hson[MAXN];//重儿子
int ans[MAXN];

void dfs1(int u,int fa)
{
    dep[u]=md[u]=dep[fa]+1;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].v;if(v==fa)continue;
        dfs1(v,u);md[u]=max(md[u],md[v]);
        if(md[v]>md[hson[u]])hson[u]=v;
    }
}

int tmp[MAXN];//动态数组，用于当前深度为i的节点个数
int *f[MAXN];//f[i][j]，即节点i深度为j的节点个数，由于重链长度和为N，借助tmp即可。
int *id=tmp;

void dfs(int u,int fa)
{
    f[u][0]=1;
    //先遍历重儿子，然后轻儿子信息，暴力添加
    if(hson[u]){
        f[hson[u]]=f[u]+1;
        dfs(hson[u],u);//借用下一层深度，需要想象力这里
        ans[u]=ans[hson[u]]+1;//更新重链上的答案
    }
    //遍历轻儿子
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa||v==hson[u])
            continue;
        f[v]=id;
        id+=md[v]-dep[v]+1;//借用重链大小层深度
        dfs(v,u);
        //这个循环最多执行N次
        for(int j=0;j<=md[v]-dep[v];j++)
        {
            //暴力更新层数大小
            f[u][j+1]+=f[v][j];//注意这里数组肯定不会越界喔！因为长度最大为N，刚刚我们已经借用了足够的层数
            if(f[u][j+1]>f[u][ans[u]]||(f[u][j+1]==f[u][ans[u]]&&ans[u]>j+1))
                ans[u]=j+1;//更新答案
        }
    }
    //叶子结点特殊处理
    if(f[u][ans[u]]==1)
        ans[u]=0;
}

// void dfs(int u,int fa){
//     f[u][0]=1;
    
//     if(hson[u]){
//         f[hson[u]]=f[u]+1;
//         dfs(hson[u],u);
//         ans[u]=ans[hson[u]]+1;
//     }
    
//     for(int i=head[u];i;i=e[i].next){
//         int v=e[i].v;
//         if(v==fa||v==hson[u])
//             continue;
//         f[v]=id;
//         id+=md[v]-dep[v]+1;
//         dfs(v,u);
        
//         for(int j=0;j<=md[v]-dep[v];j++){
            
//             f[u][j+1]+=f[v][j];
//             if(f[u][j+1]>f[u][ans[u]]||(f[u][j+1]==f[u][ans[u]]&&ans[u]>j+1))
//                 ans[u]=j+1;
//         }
//     }
    
//     if(f[u][ans[u]]==1)
//         ans[u]=0;
// }

int main()
{

    int N;
    N=read();
    for(int i=0;i<N-1;i++){
        int u,v;
        u=read();
        v=read();
        insert_edge(u,v);
        insert_edge(v,u);
    }
    dfs1(1,0);
    f[1]=id;
    id+=md[1];
    dfs(1,0);
    for(int i=1;i<=N;i++)
        printf("%d\n",ans[i]);
   
    return 0;
}
