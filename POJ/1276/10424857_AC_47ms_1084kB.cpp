#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=2000005;

inline int scanf(int &num)
{
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return -1;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return 1;
}


int W,N;
int num[100005];
int value[100005];
int weight[100005];
int dp[100005];


void zero_one_pack(int w,int v){

    for(int i=W;i>=w;i--)
        dp[i]=max(dp[i-w]+v,dp[i]);
}

void complete_pack(int w,int v){

    for(int i=w;i<=W;i++)
        dp[i]=max(dp[i-w]+v,dp[i]);
}

void multi_pack(int w,int v,int n){

    if(n*w>=W){
        complete_pack(w,v);
        return;
    }

    int k=1;
    while(k<n){
        zero_one_pack(k*w,k*v);
        n-=k;
        k*=2;
    }

    zero_one_pack(n*w,n*v);

}



int main(){



    while(~scanf(W)){

        scanf(N);

        for(int i=1;i<=N;i++){
            scanf(num[i]);
            scanf(value[i]);
            weight[i]=value[i];
        }


        memset(dp,0,sizeof(dp));

        for(int i=1;i<=N;i++)
            multi_pack(weight[i],value[i],num[i]);

        printf("%d\n",dp[W]);

    }


    return 0;
}
