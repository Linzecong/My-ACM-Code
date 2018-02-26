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
inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}


inline void scan_d(long long int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
typedef long long int ll;

const int MAXN = 100005; //用DC3要开三倍大小

int wa[MAXN], wb[MAXN], wv[MAXN], JS[MAXN]; //计算SA用的辅助数组

int rk[MAXN], height[MAXN], SA[MAXN]; //三个常用数组

/***后缀数组倍增解法***/
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *r, int *SA, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++)
        JS[i] = 0;
    for (i = 0; i < n; i++)
        JS[x[i] = r[i]]++;
    for (i = 1; i < m; i++)
        JS[i] += JS[i - 1];
    for (i = n - 1; i >= 0; i--)
        SA[--JS[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (SA[i] >= j)
                y[p++] = SA[i] - j;
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < m; i++)
            JS[i] = 0;
        for (i = 0; i < n; i++)
            JS[wv[i]]++;
        for (i = 1; i < m; i++)
            JS[i] += JS[i - 1];
        for (i = n - 1; i >= 0; i--)
            SA[--JS[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[SA[0]] = 0, i = 1; i < n; i++)
            x[SA[i]] = cmp(y, SA[i - 1], SA[i], j) ? p - 1 : p++;
    }
    return;
}
/*******************/

/***后缀数组DC3解法***/
#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x)*3 + 1 : ((x)-tb) * 3 + 2)
int c0(int *r, int a, int b)
{
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b)
{
    if (k == 2)
        return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
    else
        return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}
void sort(int *r, int *a, int *b, int n, int m)
{
    int i;
    for (i = 0; i < n; i++)
        wv[i] = r[a[i]];
    for (i = 0; i < m; i++)
        JS[i] = 0;
    for (i = 0; i < n; i++)
        JS[wv[i]]++;
    for (i = 1; i < m; i++)
        JS[i] += JS[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--JS[wv[i]]] = a[i];
    return;
}
void DC3(int *r, int *SA, int n, int m)
{
    int i, j, *rn = r + n, *SAn = SA + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++)
        if (i % 3 != 0)
            wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc)
        DC3(rn, SAn, tbc, p);
    else
        for (i = 0; i < tbc; i++)
            SAn[rn[i]] = i;
    for (i = 0; i < tbc; i++)
        if (SAn[i] < tb)
            wb[ta++] = SAn[i] * 3;
    if (n % 3 == 1)
        wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++)
        wv[wb[i] = G(SAn[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        SA[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++)
        SA[p] = wa[i++];
    for (; j < tbc; p++)
        SA[p] = wb[j++];
    return;
}
/***********************/

//计算rank和height数组
void calheight(int *r, int *SA, int n)
{
    //  memset(height,0,sizeof(height));
    //  memset(rk,0,sizeof(rk));
    int i, j, k = 0;
    for (i = 1; i <= n; i++)
        rk[SA[i]] = i;
    for (i = 0; i < n; height[rk[i++]] = k)
        for (k ? k-- : 0, j = SA[rk[i] - 1]; r[i + k] == r[j + k]; k++)
            ;
}
int N;         //字符串长度
/*****RMQ部分*****/
int ST[MAXN][16];
void RMQ(int *a)
{
    int m = (int)(log(N * 1.0) / log(2.0));
    for (int i = 1; i <= N; i++)
        ST[i][0] = a[i];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
            ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
int query(int a, int b)
{
    int k = int(log(b - a + 1.0) / log(2.0));
    return min(ST[a][k], ST[b - (1 << k) + 1][k]);
}


char sstr[MAXN]; //主字符串
int str[MAXN];
ll subnum[MAXN];

bool judge(int m,ll k){
    if(subnum[m]<k)
        return true;
    else
        return false;
}


int main()
{

    while (~scanf("%s", sstr))
    {
        N=strlen(sstr);
        for (int i = 0; i < N ; i++)
            str[i] = sstr[i] - 'a' + 1;

        str[N] = 0; //必须要末尾补0！！！！！

        DA(str, SA, N + 1, 28);//N是没有补0的大小，算SA时要把末尾0计算进去，所以要N+1
        calheight(str, SA, N);//计算height时不用末尾0
        RMQ(height);

        //cout<<query(2,5)<<endl;
        //调试
//        for(int i=0;i<=N+1;i++)
//            cout<<SA[i]<<" ";
//        cout<<endl;
//        for(int i=0;i<=N+1;i++)
//            cout<<rk[i]<<" ";
//        cout<<endl;
//        for(int i=0;i<=N+1;i++)
//            cout<<height[i]<<" ";
//        cout<<endl;

        subnum[0]=0;
        for(int i=1;i<=N;i++){
            subnum[i]=subnum[i-1]+N-SA[i]-height[i];
           // cout<<subnum[i]<<" ";
        }
        int q;
        scan_d(q);
        ll v,k;
        ll l=0,r=0;
        int m;
        for(int i=0;i<q;i++){
            scan_d(v);

            k=(l^r^v)+1;

            if(k>subnum[N]){
                printf("%d %d\n",0,0);
                l=0,r=0;
                continue;
             }


          //  k=v;
            l=1;
            r=N;
            while(l<r){
                m=(l+r)/2;
                if(judge(m,k)){
                    l=m+1;
                }
                else
                    r=m;
            }

            int len=k-subnum[l-1]+height[l];
            // cout<<l<<endl;
            int L=SA[l]+1;
            int R=L+len-1;
           // cout<<L<<" "<<R<<endl;

            int ii;
            int lll=l;
            for(ii=l+1;ii<=N;ii++){
                if(height[ii]<len)
                    break;
                else{
                    if(SA[ii]<SA[lll])
                        lll=ii;
                }
            }

            l=SA[lll]+1;
            r=l+len-1;

            printf("%I64d %I64d\n",l,r);
        }


    }

    return 0;
}
