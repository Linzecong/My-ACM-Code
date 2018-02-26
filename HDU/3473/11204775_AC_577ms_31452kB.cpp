#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<memory.h>
using namespace std;
const int MAXN=100010;

int A[MAXN];
int Sorted[MAXN];
int num[20][MAXN];//i前面有多少个点进入左孩子
long long int sum[20][MAXN];//i前面的和
int Val[20][MAXN];//每层的数组，0层就是原数组

void build(int l,int r,int ceng){
    if(l==r){
        sum[ceng][l]=sum[ceng][l-1]+Val[ceng][l];
        return;
        }

    int mid=(l+r)>>1;
    int same=mid-l+1;//保存有多少和中位数一样大的数进入左孩子

    for(int i=l;i<=r;i++){
        if(Val[ceng][i]<Sorted[mid])
            same--;
        sum[ceng][i]+=sum[ceng][i-1]+Val[ceng][i];
    }

    int ln=l;
    int rn=mid+1;//左右孩子的开头区间下标

    for(int i=l;i<=r;i++){
        if(Val[ceng][i]<Sorted[mid]){
            Val[ceng+1][ln++]=Val[ceng][i];
        }
        else{
            if((Val[ceng][i]==Sorted[mid]&&same>0)){
                Val[ceng+1][ln++]=Val[ceng][i];
                same--;
            }
            else
                Val[ceng+1][rn++]=Val[ceng][i];
        }
        num[ceng][i]=num[ceng][l-1]+ln-l;
    }
    build(l,mid,ceng+1);
    build(mid+1,r,ceng+1);

}

long long int ans=0;
int query(int L,int R,int K,int l,int r,int ceng){
    if(L==R)
        return Val[ceng][L];


    int mid=(l+r)>>1;
    int tl=num[ceng][R]-num[ceng][L-1];

    if(tl>=K){

        int ee=R-l+1 - (num[ceng][R]-num[ceng][l-1]) +mid;
        int ss=L-l+1 - (num[ceng][L-1]-num[ceng][l-1]) +mid;

        ans+=sum[ceng+1][ee]-sum[ceng+1][ss-1];


        int newl=l+num[ceng][L-1]-num[ceng][l-1];
        int newr=newl+tl-1;
        return query(newl,newr,K,l,mid,ceng+1);
    }
    else{

        int ss = l+ num[ceng][L-1]-num[ceng][l-1];
        int ee = ss +tl-1;

        ans-=sum[ceng+1][ee]-sum[ceng+1][ss-1];


        int newr=R+num[ceng][r]-num[ceng][R];
        int newl=newr-(R-L-tl);
        return query(newl,newr,K-tl,mid+1,r,ceng+1);
    }

}




int main(){

    int n,m,l,r;
    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&Val[0][i]);
            Sorted[i]=Val[0][i];
        }
        sort(Sorted+1,Sorted+n+1);
        build(1,n,0);
        scanf("%d",&m);
        printf("Case #%d:\n",qqq);
        while(m--)
        {
            ans=0;
            scanf("%d%d",&l,&r);
            l++;r++;
            int temp=query(l,r,(l+r)/2-l+1,1,n,0);
            if((l+r)%2)ans-=temp;
            printf("%I64d\n",ans);
        }
        printf("\n");
    }


    return 0;
}
