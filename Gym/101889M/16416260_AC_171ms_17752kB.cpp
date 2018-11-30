#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005; //用DC3要开三倍大小
const ll MOD=1000000007ll;
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
    for (i = 0; i < n; i++)
            rk[SA[i]] = i;
    return;
}
/*******************/

int head[MAXN];
int s[MAXN];
struct node{
    int v;
    bool operator <(const node &a)const{
        return rk[head[v]]>rk[head[a.v]];
    }
};

priority_queue<node> que;
int main(){

    int N;
    int now=0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        head[i]=now;
        int k,x;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&x);
            s[now++]=x;
        }
        s[now++]=301;//代表结束
    }
    s[now++]=0;
    DA(s,SA,now,305);

    for(int i=1;i<=N;i++){
        node v1;
        v1.v=i;
        que.push(v1);
    }

    ll ans=0;
    while(!que.empty()){
        int tp=que.top().v;
        que.pop();
        ans=(ans*365ll+s[head[tp]])%MOD;
        head[tp]++;
        if(s[head[tp]]!=301){
            node v1;
            v1.v=tp;
            que.push(v1);
        }
    }
    printf("%lld\n",ans*365ll%MOD);




    return 0;
}











