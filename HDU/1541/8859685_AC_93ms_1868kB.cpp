#include <iostream>
#include <stdio.h>
#include <algorithm>

#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

const int maxn=32005;

int C[maxn];

int L[15005][2];
int ANS[15005];

int lowbit(int x){
    return x& -x;
}

int sum(int x){
    int s=0;
    for(int i=x;i;i-=lowbit(i))
        s+=C[i];
    return s;
}

void add(int x,int v){
    for(int i=x;i<=maxn;i+=lowbit(i))
        C[i]+=v;
}

int main(){


    int N;

    while(~scanf("%d",&N)){

        memset(C,0,sizeof(C));
                memset(ANS,0,sizeof(ANS));

    for(int i=0;i<N;i++){
        scanf("%d%d",&L[i][0],&L[i][1]);



        add(L[i][0]+1,1);

        int l=sum(L[i][0]+1)-1;

        ANS[l]++;
    }



    for(int i=0;i<N;i++){
        printf("%d\n",ANS[i]);

    }
}

    return 0;
}














