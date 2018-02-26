#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <deque>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
using namespace std;

typedef long long int ll;

int a[100006];

int b[10];
bool judge(int a){
    memset(b,0,sizeof(b));
    while(a){
        if(b[a%10])
            return false;
        b[a%10]=1;
        a/=10;
    }
    return true;
}

int main()
{

    for(int i=1;i<=100000;i++){
        if(judge(i))
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1];
    }

int l,r;
    int T;
    scanf("%d",&T);
    while(T--){
        
        scanf("%d%d",&l,&r);

        printf("%d\n",a[r]-a[l-1]);


    }
    

    return 0;
}