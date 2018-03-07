#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;

const int MAXN = 100005;
const int MAXM = 200005;
int N, M;

int pre[MAXN];
int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}
void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
    }
}

struct edge{
    int u,v,w;
}e[MAXM];
int edge_num;
bool cmp(edge a,edge b){
    return a.w>b.w;
}


int main()
{

    while (~scanf("%d%d", &N, &M))
    {
        for (int i = 0; i <= N; i++)
            pre[i] = i;
        edge_num=0;

        int a, b, w;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &a, &b);
        }
        int ans = 0;
        int count = 0;
        int all=0;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &a, &b, &w);
            e[edge_num].u=a;
            e[edge_num].v=b;
            e[edge_num++].w=w;
            all+=w;
        }

        sort(e,e+M,cmp);

        for(int i=0;i<M;i++){
            int fx=find(e[i].u);
            int fy=find(e[i].v);
            if(fy!=fx){
                pre[fx]=fy;
                ans+=e[i].w;
                count++;
            }
        }


        printf("%d %d\n", M-count, all-ans);
    }

    return 0;
}
