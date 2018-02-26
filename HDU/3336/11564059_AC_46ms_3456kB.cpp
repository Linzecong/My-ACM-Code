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

void getNext(char a[],int len,int nxt[]){
    nxt[0]=nxt[1]=0;
    for(int i=1;i<len;i++){
        int j=nxt[i];
        while(j&&a[i]!=a[j])
            j=nxt[j];
        nxt[i+1]=(a[i]==a[j])?j+1:0;
    }
}

int KMP(char a[],char b[],int N,int M,int nxt[]){
    int j=0;
    int ans=0;
    for(int i=0;i<N;i++){
        while(j&&a[i]!=b[j])
            j=nxt[j];
        if(a[i]==b[j])
            j++;
        if(j==M){
            ans++;
        }
    }
    return ans;
}

char a[1000050];//原始串

char b[1000050];//模式串
int nxt[1000050];
int N,M;
int dp[1000050];
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        scanf("%s",a);

        getNext(a,N,nxt);

        for(int i = 1; i <= N; i ++)
            dp[i] = 1;

        dp[0] = 0;
        int sum = 0;
        for(int i = 1; i <= N; i ++)
        {
            dp[i] = dp[nxt[i]] + 1;
            sum += dp[i]%10007;
        }
        printf("%d\n",sum%10007);

    }



    return 0;
}














