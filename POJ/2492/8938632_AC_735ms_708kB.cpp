#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;

int pre[MAXN];
int sex[MAXN];//0同性，1不同姓


//int find(int x){
//    int r=pre[x];
//    while(r!=pre[r])
//        r=pre[r];

//    int i=x,j;
//    while(pre[i]!=r){
//        j=pre[i];
//        pre[i]=r;
//        sex[i]=(sex[j]+sex[i])%2;
//        i=j;
//    }

//    return r;
//}

int find(int x){
    int px;
    if(x!=pre[x]){
        px = pre[x];
        pre[x] = find(pre[x]);
        sex[x] = (sex[px] + sex[x])%2;
    }
    return pre[x];
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++){
        int n,q;
        scanf("%d%d",&n,&q);

        for(int i=0;i<=n;i++){
            pre[i]=i;
            sex[i]=0;
        }
        bool is=true;

        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int ar=find(a);
            int br=find(b);

            if(is){
                if(ar!=br){
                    pre[ar]=br;

                    sex[ar] = (1 + sex[b] - sex[a])%2;  
                }
                find(a);
            }

            if((sex[a]+sex[b])%2==0)
                    is=false;


        }

        if(!is){
            printf("Scenario #%d:\nSuspicious bugs found!\n\n",qqq);
        }
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n",qqq);

    }


    return 0;
}
