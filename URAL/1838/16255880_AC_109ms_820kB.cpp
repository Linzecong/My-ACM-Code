#include<iostream>
#include<string.h>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=0x3f3f3f3f3f3f3f3f;

int a[MAXN];
int main(){
    int l,N;
    scanf("%d%d",&l,&N);

    int ans=l;

    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);

    if(N==3||N==2){
        cout<<l<<endl;
        return 0;
    }



    for(int i=2;i<=N-2;i++){

        int LL=a[1]*2;
        int RR=a[i]*2;

        if(RR>a[i+1])RR=a[i+1];
        if(LL<a[i])LL=a[i];
        if(LL>=RR)
            continue;

        int LLL=l-(l-a[i+1])*2;
        int RRR=l-(l-a[N])*2;


        if(RRR>a[i+1])RRR=a[i+1];
        if(LLL<a[i])LLL=a[i];
        if(LLL>=RRR)
            continue;

        ans-=min(RRR,RR)-max(LL,LLL)<=0?0:min(RRR,RR)-max(LL,LLL);


    }
    cout<<ans<<endl;



    return 0;
}





