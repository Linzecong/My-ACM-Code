#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int a[20][MAXN];
int mp[20][MAXN];

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&a[i][j]);
            mp[i][a[i][j]]=j;
        }
    }

    ll ans=0;
    for(int i=1;i<=N;){
        int cur=a[1][i];
        bool flag=1;
        ll len=1;
        
        while(flag){
            cur=a[1][mp[1][cur]+1];
            if(cur==0){
                flag=0;
                continue;
            }
            for(int j=2;j<=M;j++){
                if(a[j][mp[j][cur]-1]!=a[1][mp[1][cur]-1]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                len++;
            }
        }

        i+=len;
        ans+=len*(1+len)/2;
    }
    cout<<ans<<endl;

    return 0;
}











