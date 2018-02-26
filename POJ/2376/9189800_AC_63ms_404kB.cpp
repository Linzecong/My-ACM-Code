#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1000000+50;
struct interval
{
    int left,right;
    bool operator < (const interval &x) const
    {
        return (left<x.left);
    }
};

int n,t;
interval cow[MAXN];

int main()
{
    scanf("%d%d",&n,&t);
    for (int i=0;i<n;i++)
        scanf("%d%d",&cow[i].left,&cow[i].right);
    sort(cow,cow+n);

    int lright=0,ans=0,p=-1;
    for (int i=0;i<n;i++)
    {
        if (cow[i].left>lright+1)
        {
            if (p==-1) break;
            /*如果当前左边界已经大于之前的最大右边界，且没有中间区间能衔接，必定说明无解*/
            ans++;
            lright=p;
            p=-1;
            /*否则将已经覆盖区域的右边界设为之前最大的右边界*/
        }
        if (cow[i].left<=lright+1 && cow[i].right>=lright+1)
        {
            p=max(p,cow[i].right);
            if (p>=t)
            {
                ans++;
                break;
                /*如果当前已经覆盖完大区间，就退出*/ 
            }
        }
    }
    if (p>=t) cout<<ans<<endl;
        else cout<<-1<<endl;
         return 0;
}