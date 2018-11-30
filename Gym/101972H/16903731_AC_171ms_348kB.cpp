#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int MAXN=1e5+10;


char A[MAXN];
char B[MAXN];

set<char> vec[256];
int num[256];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<256;i++){
            vec[i].clear();
            num[i]=0;
        }

        int N,M,K;
        scanf("%d%d%d",&N,&M,&K);
        scanf("%s%s",A,B);

        for(int i=0;i+K-1<N;i++)
            vec[A[i]].insert(A[i+K-1]);

        for(int i=0;i<M;i++)
            num[B[i]]++;

        ll ans=0;
        for(int i=0;i<M;i++){

            for(auto &j:vec[B[i]]){
                ans=ans+num[j];

            }
            num[B[i]]--;

        }
        cout<<ans<<endl;


    }
    return 0;
}

