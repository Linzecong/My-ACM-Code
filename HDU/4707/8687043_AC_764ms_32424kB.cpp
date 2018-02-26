/* *******************************************
Author       : kuangbin
Created Time : 2013年09月08日 星期日 12时00分01秒
File Name    : 1009.cpp
******************************************* */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN = 1000010;
vector<int>vec[MAXN];
int dep[MAXN];
void bfs(int s)
{
    memset(dep,-1,sizeof(dep));
    dep[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int sz = vec[u].size();
        for(int i = 0;i < sz;i++)
        {
            int v = vec[u][i];
            if(dep[v] != -1)continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}
int main()
{
    
    int T;
    int n;
    int D;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&D);
        int u,v;
        for(int i = 0;i < n;i++)
            vec[i].clear();
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        bfs(0);
        int ans = 0;
        for(int i = 0;i < n;i++)
            if(dep[i] > D)
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}