#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int a[10005];


int dp[10006][105];

int mod(int n,int k){
    n=n%k;
    if(n<0)
        n+=k;
    return n;
}

int main(){

    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);

    dp[0][mod(a[0],K)]=1;

    for(int i=1;i<N;i++)
        for(int j=0;j<K;j++){
            if(dp[i-1][j]){
                dp[i][mod(j+a[i],K)]=1;
                dp[i][mod(j-a[i],K)]=1;
            }
        }
    if(dp[N-1][0])
        printf("Divisible\n");
    else
        printf("Not divisible\n");


    return 0;
}
