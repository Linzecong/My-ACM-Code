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

int a[1000006];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
            scanf("%d",&a[i]);
        int q;
        scanf("%d",&q);
        int a1,b;
        for(int i=0;i<q;i++){
            scanf("%d%d",&a1,&b);
            int mini=-100000000;
            for(int j=a1;j<=b;j++){
                if(a[j]>mini)
                    mini=a[j];
            }
            printf("%d\n",mini);
        }


    }
    

    return 0;
}