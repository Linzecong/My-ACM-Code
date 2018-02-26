#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<stdlib.h>

using namespace std;

int a[1005];

int b[3];

int main(){

    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]%2;
        b[a[i]]++;
    }

    if(b[0]==1){
        for(int i=1;i<=N;i++)
            if(a[i-1]==0){
                printf("%d\n",i);
                break;
            }
    }
    else{
        for(int i=1;i<=N;i++)
            if(a[i-1]==1){
                printf("%d\n",i);
                break;
            }
    }




    return 0;
}

