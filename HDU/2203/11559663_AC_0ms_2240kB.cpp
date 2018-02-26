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



    while(~scanf("%s%s",a,b)){
        N=strlen(a)*2;
        M=strlen(b);

        for(int i=0;i<N/2;i++)
            a[i+N/2]=a[i];

        getNext(a,N,nxt);

        if(KMP(a,b,N,M,nxt))
            printf("yes\n");
        else
            printf("no\n");
    }



    return 0;
}
