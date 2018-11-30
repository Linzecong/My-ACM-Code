#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char sta[MAXN];

bool know[MAXN];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){

        int N,M,K;
        scanf("%d%d%d",&N,&M,&K);
        char s[3];
        for(int i=1;i<=N;i++){
            scanf("%s",s);
            sta[i]=s[0];
        }
        int cur=0;
        int ans=0;
        for(int i=0;i<M;i++){
            scanf("%s",s);

            if(s[0]=='A'){
                cur=N;
            }
            else{
                int tmp;
                scanf("%d",&tmp);

                if(tmp<=K){
                    ans++;
                }
                else if(tmp<=cur&&sta[tmp]=='S'){
                    ans++;
                }
                cur=max(cur,tmp);
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}
