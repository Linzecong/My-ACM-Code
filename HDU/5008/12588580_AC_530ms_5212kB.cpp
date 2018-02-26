#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<string>
#define LL __int64
#define N 100005
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 10e-6
using namespace std;
char s[N];
int sa[N],t[N],t2[N],c[N],r[N];
void build_sa(int n,int m)
{
    int i,k,*x = t,*y = t2;
    for(i = 0; i < m; i++)  c[i] = 0;
    for(i = 0; i < n; i++)  c[ x[i] = r[i] ]++;
    for(i = 1; i < m; i++)  c[i] += c[i-1];
    for(i = n-1; i >= 0; i--)   sa[ --c[ x[i] ] ] = i;

    for(k = 1; k <= n; k<<=1)
    {
        int p = 0;
        for(i = n-k; i < n; i++)    y[p++] = i;
        for(i = 0; i < n; i++)  if(sa[i] >= k)  y[p++] = sa[i] - k;

        for(i = 0; i < m; i++)  c[i] = 0;
        for(i = 0; i < n; i++)  c[ x[ y[i] ] ]++;
        for(i = 1; i < m; i++)  c[i] += c[i-1];
        for(i = n-1; i >= 0; i--)   sa[ --c[ x[ y[i] ] ] ] = y[i];

        swap(x,y);
        p = 1; x[ sa[0] ] = 0;
        for(i = 1; i < n; i++)
            x[ sa[i] ] = y[ sa[i-1] ] == y[ sa[i] ] && y[ sa[i-1]+k ] == y[ sa[i]+k ] ? p-1 : p++;
        if(p >= n) break;
        m = p;
    }
}
int rk[N],height[N];
void getheight(int n)
{
    int i,j,k = 0;
    for(i = 0; i <= n; i++)  rk[ sa[i] ] = i;
    for(i = 0; i < n; i++)  {
        if(k) k--;
        j = sa[ rk[i]-1 ];
        while(s[i+k] == s[j+k]) k++;
        height[ rk[i] ] = k;
    }
}
LL cnt[N];
int main()
{
    while(scanf("%s",s) != EOF)
    {
        int n = strlen(s);
        int i;
        for(i = 0; i < n; i++)
            r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        build_sa(n+1,28);
        getheight(n);
        cnt[0] = -1;
        for(i = 1; i <= n; i++)     cnt[i] = n - sa[i] - height[i];
        for(i = 2; i <= n; i++)     cnt[i] += cnt[i-1];
        int l = 0,r = 0;
        LL k;
        int cas;
        scanf("%d",&cas);
        while(cas--)
        {
            scanf("%I64d",&k);
            k = (k^l^r)+1;
            if(k > cnt[n]){
                l = r = 0;
                printf("%d %d\n",l,r);
                continue;
            }
            int cur = lower_bound(cnt+1,cnt+n+1,k) - cnt;
         //   cout<<cur<<" "<<sa[cur]<<endl;
            if(cur > n) {
                l = r = 0;
            }
            else {
                LL ll = sa[cur];
                LL rr = n - (cnt[cur] - k)-1;
                int tot = rr-ll+1;
                l = ll;
                for(i = cur+1; i <= n; i++)
                {
                    if(height[i] < tot)  break;
                    if(sa[i] < l)
                        l = sa[i];
                }
                r = l+tot-1;
                r++;l++;
            }
            printf("%d %d\n",l,r);
        }
    }
    return 0;
}
