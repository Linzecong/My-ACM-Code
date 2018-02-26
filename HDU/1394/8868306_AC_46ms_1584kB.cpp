#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=5005;

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



    int n;

    while(~scanf("%d",&n)){


        int num[n+1];

        memset(num,0,sizeof(num));


        for(int i=1;i<=n;i++){
            C[i]=0;
            scanf("%d",&num[i]);
            num[i]++;
        }

        int min=5000*5000;
        int a=0;


        for(int i=1;i<=n;i++){
            a+=i-1-sum(num[i]);
            add(num[i],1);
        }

        for(int i=1;i<=n;i++){
            a=a-(num[i]-1)+(n-num[i]);
            if(a<min)
                min=a;
        }


        printf("%d\n",min);



    }

    return 0;
}
