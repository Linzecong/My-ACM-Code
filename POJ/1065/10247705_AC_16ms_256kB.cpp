#include<set>
#include<iostream>
#include<algorithm>
#define INF 1<<29
using namespace std;
const int MAXN = 5005;
pair<int,int> p[MAXN];

int a[MAXN];
int dp[MAXN];
int n;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            p[i] = pair<int,int>(x,y);
        }
        sort(p,p+n);

        for(int i = 0;i < n;i++)
            a[i] = p[n-1-i].second;

        fill(dp,dp+n,INF);
        for(int i = 0;i < n;i++){
            *lower_bound(dp,dp+n,a[i]) = a[i];
        }

        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    return 0;
}
