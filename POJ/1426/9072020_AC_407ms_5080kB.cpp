#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;
const int maxn=1000006;
int n;

long long bfs()
{
    queue<long long>Q;
    Q.push(1);

    while(!Q.empty())
    {
        long long q=Q.front();
        Q.pop();
        if(q%n==0)return q;

        Q.push(q*10);
        Q.push(q*10+1);
    }
    return -1;
}
int main()
{
    while(scanf("%d", &n), n)
    {
        long long ans=bfs();
        printf("%lld\n", ans);
    }
    return 0;
}