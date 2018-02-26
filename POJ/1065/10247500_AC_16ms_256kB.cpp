#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
typedef pair<int,int> P;
const int maxn = 5000 + 5;
const int INF = 1000000000;

P p[maxn];
int a[maxn];
int dp[maxn];
int n;

void solve(){
    fill(dp,dp+n,INF);
    for(int i = 0;i < n;i++){
        *lower_bound(dp,dp+n,a[i]) = a[i];
    }
    printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            p[i] = P(x,y);
        }
        sort(p,p+n);

        

        for(int i = 0;i < n;i++) a[i] = p[n-1-i].second;
        solve();
    }
    return 0;
}
