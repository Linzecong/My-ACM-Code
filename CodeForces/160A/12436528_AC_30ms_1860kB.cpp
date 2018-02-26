#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>

using namespace std;

int a[1005];
int sum[1005];

int main(){

    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+N+1);

    for(int i=1;i<=N;i++){
        sum[i]=sum[i-1]+a[i];
        //cout<<sum[i]<<" ";
    }


    int j;
    for(j=N;j>=1;j--)
        if(sum[N]-sum[j-1]>sum[j-1])
            break;

    printf("%d\n",N-j+1);

    return 0;
}

