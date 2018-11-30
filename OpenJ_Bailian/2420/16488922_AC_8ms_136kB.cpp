//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include<functional>
#include<iterator>
#include<set>
#include<utility>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>

using namespace std;

#define N 1005
#define eps 1e-8
#define INF 1e99
#define delta 0.98
#define T 100

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct Point
{
    double x,y;
} p[N];

double dist (Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double GetSum(Point p[],int n,Point t)
{
    double ans = 0;
    while(n--)
    {
        ans+=dist(p[n],t);
    }
    return ans;
}

double Search(Point p[],int n)
{
    Point s = p[0];
    double t = T;
    double ans = INF;
    while(t>eps)
    {
        bool flag = 1;
        while(flag)
        {
            flag = 0;
            for(int i=0; i<4; i++)
            {
                Point z;
                z.x = s.x + dx[i]*t;
                z.y = s.y + dy[i]*t;
                double tp = GetSum(p,n,z);
                if(ans>tp)
                {
                    ans = tp;
                    s = z;
                    flag = 1;
                }
            }
        }
        t*=delta;
    }
    return ans;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        printf("%.0lf\n",Search(p,n));
    }
    return 0;
}