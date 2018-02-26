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

void getNext(int a[],int len,int nxt[]){
    nxt[0]=nxt[1]=0;
    for(int i=1;i<len;i++){
        int j=nxt[i];
        while(j&&a[i]!=a[j])
            j=nxt[j];
        nxt[i+1]=(a[i]==a[j])?j+1:0;
    }
}

void KMP(int a[],int b[],int N,int M,int nxt[]){
    int j=0;
    for(int i=0;i<N;i++){
        while(j&&a[i]!=b[j])
            j=nxt[j];
        if(a[i]==b[j])
            j++;
        if(j==M){
            printf("%d\n",i-M+2);
            return;
        }
    }
    printf("-1\n");
}


int a[1000050];//原始串
int b[1000050];//模式串
int nxt[1000050];
int N,M;

int main(){
    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++){

        scanf("%d",&N);
        scanf("%d",&M);

        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<M;i++)
            scanf("%d",&b[i]);

        getNext(b,M,nxt);
        KMP(a,b,N,M,nxt);

    }

    return 0;
}
