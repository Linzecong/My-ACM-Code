#include <iostream>
#include <stdio.h>
#include <algorithm>

#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

const int maxn=50005;

int C[maxn];

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

    int T;

    scanf("%d",&T);

    for(int qqq=1;qqq<=T;qqq++)
    {
        printf("Case %d:\n",qqq);
        int N;
        scanf("%d",&N);

        for(int i=1; i<=N; i++)
              C[i] = 0;


        for(int i=0;i<N;i++)
        {
            int temp;
            scanf("%d",&temp);
            add(i+1,temp);
        }



        while(1){
            char b[100];

            scanf("%s",b);

            string a=b;

            if(a=="End")
                break;

            if(a=="Query"){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",sum(y)-sum(x-1));
                continue;
            }

            if(a=="Add"){
                int x,y;
                scanf("%d%d",&x,&y);
                add(x,y);
                continue;
            }

            if(a=="Sub"){
                int x,y;
                scanf("%d%d",&x,&y);
                add(x,-y);
                continue;
            }


        }
    }






    return 0;
}














