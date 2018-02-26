#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000;

int A[MAXN];
int Sorted[MAXN];
int num[20][MAXN];//i前面有多少个点进入左孩子
int Val[20][MAXN];//每层的数组，0层就是原数组

void build(int l,int r,int ceng){
    if(l==r)
        return;
    int mid=(l+r)>>1;
    int same=mid-l+1;//保存有多少和中位数一样大的数进入左孩子

    for(int i=l;i<=r;i++)
        if(Val[ceng][i]<Sorted[mid])
            same--;

    int ln=l;
    int rn=mid+1;//左右孩子的开头区间下标

    for(int i=l;i<=r;i++){
        if(i==l)
            num[ceng][i]=0;
        else
            num[ceng][i]=num[ceng][i-1];

        if(Val[ceng][i]<Sorted[mid]||(Val[ceng][i]==Sorted[mid]&&same>0)){
            Val[ceng+1][ln++]=Val[ceng][i];
            num[ceng][i]++;
            if(Val[ceng][i]==Sorted[mid])
                same--;
        }
        else{
            Val[ceng+1][rn++]=Val[ceng][i];
        }
    }
    build(l,mid,ceng+1);
    build(mid+1,r,ceng+1);

}

int query(int L,int R,int K,int l,int r,int ceng){
    if(l==r)
        return Val[ceng][l];

    int lc;
    if(L==l)
        lc=0;
    else
        lc=num[ceng][L-1];

    int tl=num[ceng][R]-lc;

    if(tl>=K)
        return query(l+lc,l+num[ceng][R]-1,K,l,(l+r)>>1,ceng+1);
    else{
        int lr=((l+r)>>1)+1+(L-l-lc);
        return query(lr,lr+R-L+1-tl-1,K-tl,((l+r)>>1)+1,r,ceng+1);
    }

}




int main(){

    int n,m,l,r,k;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&Val[0][i]);
            Sorted[i]=Val[0][i];
        }
        sort(Sorted+1,Sorted+n+1);
        build(1,n,0);
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(l,r,k,1,n,0));
        }
    }


    return 0;
}
