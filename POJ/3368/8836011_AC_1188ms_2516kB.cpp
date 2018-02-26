#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

const int maxn=100020;



int maxnum[maxn*4];




int A[maxn];


int shuzu[maxn],hash1[maxn];

struct{
    int sta, end;
}seg[maxn];

void pushup(int rt){
    maxnum[rt]=max(maxnum[rt<<1],maxnum[(rt<<1)+1]);

}


void build(int l,int r,int rt){
    if(l==r){
        maxnum[rt]=A[l];
        return;
    }
    int m=(l+r)>>1;

    build(l,m,rt<<1);
    build(m+1,r,(rt<<1)+1);
    pushup(rt);
}



int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return maxnum[rt];
    }
    int m=(l+r)>>1;

    int ANS=0;
    if(L<=m){
        int temp=query(L,R,l,m,rt<<1);
        ANS=max(ANS,temp);
    }

    if(R>m){
        int temp=query(L,R,m+1,r,(rt<<1)+1);
        ANS=max(ANS,temp);
    }
    return ANS;
}








int main(){

    int n,q;
    while(1){



        scanf("%d",&n);


        if(n==0)
            break;

        scanf("%d",&q);






        for(int i = 1; i <= n; i ++)
            scanf("%d",&shuzu[i]);
        int zu = 0, pre = 999999;
        for(int i = 1; i <= n; i ++){      //  离散化，将点的序列离散化为一个个的点集。
            if(shuzu[i] != pre){
                pre = shuzu[i];
                zu ++;
                seg[zu].sta = i;
                seg[zu].end = i;
            }
            else

                seg[zu].end = i;

            A[zu]=seg[zu].end-seg[zu].sta+1;

        //  printf("       %d %d\n",zu,A[zu]);

            hash1[i] = zu;               //  hash保存序列上第i个点，对应的点集的下标。

        }



        build(1,zu,1);

       // printf("       %d\n",query(1,1,1,zu,1));


        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);

            int lz=hash1[a];
            int rz=hash1[b];

            if(lz==rz)
                printf("%d\n",b-a+1);
            else{
                if(rz-lz==1){

                    int lc=seg[lz].end -a+1;

                    int rc=b-seg[rz].sta+1;

                    printf("%d\n",max(lc,rc));
                }
                else{
                    int lc=seg[lz].end -a+1;

                    int rc=b-seg[rz].sta+1;

                    printf("%d\n",max(lc,max(rc,query(lz+1,rz-1,1,zu,1))));
                }

            }


        }







    }
    return 0;
}
