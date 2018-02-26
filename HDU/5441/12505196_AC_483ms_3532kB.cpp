#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <deque>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
using namespace std;

typedef long long int ll;

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9')
        ;
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

inline void scan_d(ll &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9')
        ;
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int pre[20005];
ll num[20005];

int find(int x)
{
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

int merge(int x, int y,int &a,int &b,int &c)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
        b=num[fx];
        c=num[fy];

        num[fy] += num[fx];
        a=num[fy];
        return num[fy];
    }
    return -1;
}

struct edge
{
    int v1;
    int v2;
    int w;
    // edge(int a, int b, int c)
    // {
    //     v1 = a;
    //     v2 = b;
    //     w = c;
    // }

} e[100005];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int query[5005];
int query2[5005];

int edge_num = 0;
int main()
{

    int T;
    scan_d(T);
    while (T--)
    {
        for (int i = 0; i < 20005; i++)
        {
            pre[i] = i;
            num[i] = 1;
        }
        edge_num = 0;

        int n, m, q;
        scan_d(n);
        scan_d(m);
        scan_d(q);

        int a, b, w;
        for (int i = 0; i < m; i++)
        {
            scan_d(a);
            scan_d(b);
            scan_d(w);
            e[edge_num].v1 = a;
            e[edge_num].v2 = b;
            e[edge_num].w = w;
            edge_num++;
        }

        sort(e, e + edge_num, cmp);

        for (int i = 0; i < q; i++)
        {
            scan_d(query[i]);
            query2[i] = query[i];
        }

        sort(query, query + q);

        map<int, ll> ans;

        ll aaa = 0;
        int j = 0;
        for (int i = 0; i < q; i++)
        {

            for (j; j < m; j++)
            {
                if (e[j].w <= query[i])
                {
                    
                    int n1,n2,n3;
                    int nnn=merge(e[j].v1, e[j].v2,n1,n2,n3);
                    if(nnn==-1){
                        continue;
                    }
                    
                    aaa = aaa - ((n2 - 1) * (n2)) - ((n3 - 1) * (n3)) + (n1 * (n1 - 1));
                }
                else
                {
                    ans[query[i]] = aaa;
                    break;
                }
            }
            ans[query[i]]=aaa;
        }

        for (int i = 0; i < q; i++)
        {

            printf("%lld\n", ans[query2[i]]);
        }
    }

    return 0;
}