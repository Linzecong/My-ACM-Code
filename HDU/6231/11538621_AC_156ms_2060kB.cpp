#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;

int N,K;
ll M;
int a[100005];

bool judge(int x){
    ll ans=0;
    int num=0;
    int j=1;

    for(int i=1;i<=N;i++){
        if(a[i]>=x)
            num++;
        if(num==K){
            ans+=N-i+1;
            while(a[j]<x){
                ans+=N-i+1;
                j++;
            }
            num--;
            j++;
        }
    }

    if(ans>=M)
        return true;
    else
        return false;

}


int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d%lld",&N,&K,&M);

        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);

        int l=1,r=1000000000;
        int m;
        while(l<r){
            m=(l+r)/2;
            if(judge(m))
                l=m+1;
            else
                r=m;
        }
        printf("%d\n",l-1);

    }

    return 0;
}


