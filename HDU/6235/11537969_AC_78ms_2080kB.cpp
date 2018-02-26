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

int a[100005];

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        a[1]=1;
        if(n%2)
            a[2]=n/2+2;
        else
            a[2]=n/2+1;

        for(int i=3;i<=n;i++)
            a[i]=a[i-2]+1;

        for(int i=1;i<n;i++)
            cout<<a[i]<<" ";
        cout<<a[n]<<endl;

    }

    return 0;
}


