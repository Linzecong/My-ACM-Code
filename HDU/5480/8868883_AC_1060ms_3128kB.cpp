#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=100005;

int C[2][maxn];

int lowbit(int x){
    return x& -x;
}

int sum(int x,int j){
    int s=0;
    for(int i=x;i>0;i-=lowbit(i))
        s+=C[j][i];
    return s;
}

void add(int x,int v,int j){
    for(int i=x;i<=v;i+=lowbit(i))
        C[j][i]++;
}



int main(){



    int t;

    scanf("%d",&t);

    while(t--){
        memset(C,0,sizeof(C));
        int vis1[100005],vis2[100005];
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));

        int n,m,k,q;
        scanf("%d%d%d%d",&m,&n,&k,&q);

        for(int i=0;i<k;i++){
            int x, y;
            scanf("%d%d",&x,&y);

            if(!vis1[x]){
            add(x,n,0);
            vis1[x]=1;
            }

            if(!vis2[y]){
            add(y,m,1);
            vis2[y]=1;
            }
        }

        for(int i=0;i<q;i++){
            int x1, y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            if((x2-x1+1==sum(x2,0)-sum(x1-1,0))||(y2-y1+1==sum(y2,1)-sum(y1-1,1)))
                printf("%s\n","Yes");
            else
            printf("%s\n","No");

        }


    }

    return 0;
}
