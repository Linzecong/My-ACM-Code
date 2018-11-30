/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/26 22:20:05
File Name     :E:\2014ACM\专题学习\DLX\HDU2295.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int maxnode = 3000;
const int MaxM = 55;
const int MaxN = 55;
int K;
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN],S[MaxN];
    int ands,ans[MaxN];
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c)
    {
        for(int i = D[c];i != c;i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    void resume(int c)
    {
        for(int i = U[c];i != c;i = U[i])
            L[R[i]]=R[L[i]]=i;
    }
    bool v[maxnode];
    int f()
    {
        int ret = 0;
        for(int c = R[0];c != 0;c = R[c])v[c] = true;
        for(int c = R[0];c != 0;c = R[c])
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c];i != c;i = D[i])
                    for(int j = R[i];j != i;j = R[j])
                        v[Col[j]] = false;
            }
        return ret;

    }
    bool Dance(int d)
    {
        if(d + f() > K)return false;
        if(R[0] == 0)return d <= K;
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            if(Dance(d+1))return true;
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
        return false;
    }
};
DLX g;
const double eps = 1e-8;
struct Point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}city[MaxM],station[MaxN];
double dis(Point a,Point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&K);
        for(int i = 0;i < n;i++)city[i].input();
        for(int i = 0;i < m;i++)station[i].input();
        double l = 0, r = 1e8;
        while(r-l >= eps)
        {
            double mid = (l+r)/2;
            g.init(m,n);
            for(int i = 0;i < m;i++)
                for(int j = 0;j < n;j++)
                    if(dis(station[i],city[j]) < mid - eps)
                        g.Link(i+1,j+1);
            if(g.Dance(0))r = mid-eps;
            else l = mid+eps;
        }
        printf("%.6lf\n",l);
    }
    return 0;
}