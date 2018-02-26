/* *******************************************
Author       : kuangbin
Created Time : 2013年09月08日 星期日 13时19分17秒
File Name    : 1004.cpp
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

const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return -1;
}
struct Point 
{
    double x,y;
    Point(double _x = 0,double _y = 0)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x * b.y - y * b.x;
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
Point p[110];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            p[i].input();
        bool flag = false;
        double ans = 1e20;
        for(int i = 0; i < n;i++)
            for(int j = i+1;j < n;j++)
                for(int k = j+1;k < n;k++)
                {
                    double area = (p[i]-p[j])^(p[k]-p[i]);
                    area = fabs(area)/2;    
                    if(sgn(area) == 0)continue;
                    flag = true;
                    ans = min(ans,area);
                }
        if(!flag)
            printf("Impossible\n");
        else printf("%.2f\n",ans);
    }
    return 0;
}