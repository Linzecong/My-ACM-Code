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

int main(){


    while(~scanf("%s",a)){

        N=strlen(a);
        scanf("%s",a+N);
        M=strlen(a);
        getNext(a,M,nxt);

        if(nxt[M]>=N&&nxt[M]>=M-N){
            if(N<M-N)
            for(int i=0;i<N;i++)
                putchar(a[i]);
            else
                for(int i=0;i<M-N;i++)
                    putchar(a[i+N]);
        }
        else
                for(int i=0;i<nxt[M];i++)
                    putchar(a[i]);

        if(nxt[M])
            putchar(' ');


        if(nxt[M]>=N&&nxt[M]>=M-N){
            if(N<M-N)
            printf("%d\n",N);
            else
                printf("%d\n",M-N);
        }
        else
               printf("%d\n",nxt[M]);



    }


    return 0;
}












