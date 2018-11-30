#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=998244353;

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

void Out(ll a)
{   //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        Out(a / 10);
    }
    putchar(a % 10 + '0');
}

int num[1005][1005];
int a[100005];
int b[100005];
int x,y,k;
int N,M;

bool judge(ll res,ll m){

    ll ans=0;
    for (int i=1; i<=1000; i++){
        ans+=m/i*num[i][0];
        ans-=num[i][m%i+1];
    }
    if (ans>=k+res) return true;
    return false;

}


int main(){


    int t;

    scan_d(t);
    int op;

    ll m;
    while(t--){
        memset(num,0,sizeof(num));
        ll res=0;

        scan_d(N);
        scan_d(M);
        for(int i=1;i<=N;i++){
            scan_d(a[i]);
        }
        for(int i=1;i<=N;i++){
            scan_d(b[i]);
            num[a[i]][b[i]%a[i]]++;

            res+=(b[i]/a[i]);
        }
        for(int i=1; i<=1000; i++)
            for(int j=i-1; j>=0; j--)
                num[i][j]+=num[i][j+1];

        while(M--){
            scan_d(op);
            if(op==1){
                scan_d(x);
                scan_d(y);
                for(int i=b[x]%a[x]; i>=0; i--)
                    num[a[x]][i]--;
                for(int i=b[x]%y; i>=0; i--)
                    num[y][i]++;
                res-=b[x]/a[x];
                res+=b[x]/y;
                a[x]=y;
            }
            else if(op==2){
                scan_d(x);
                scan_d(y);
                for(int i=b[x]%a[x]; i>=0; i--)
                    num[a[x]][i]--;
                for(int i=y%a[x]; i>=0; i--)
                    num[a[x]][i]++;
                res-=b[x]/a[x];
                res+=y/a[x];
                b[x]=y;
            }
            else{
                scan_d(k);

                ll l=1,r=10000000000000LL;

                while(l<r){
                    m=(l+r)>>1;
                    if(judge(res,m))
                        r=m;
                    else
                        l=m+1;
                }

                Out(l);
                puts("");
            }
        }

    }
    return 0;
}
