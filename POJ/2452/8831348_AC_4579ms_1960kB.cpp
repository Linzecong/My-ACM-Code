#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=50004;

int maxindex[maxn<<2];
int minindex[maxn<<2];

int A[maxn];


void pushup(int rt){
    maxindex[rt]=A[maxindex[rt<<1]]>A[maxindex[rt<<1|1]]?maxindex[rt<<1]:maxindex[rt<<1|1];
    minindex[rt]=A[minindex[rt<<1]]>A[minindex[rt<<1|1]]?minindex[rt<<1|1]:minindex[rt<<1];
}


void build(int l,int r,int rt){
    if(l==r){
        maxindex[rt]=l;
        minindex[rt]=l;
        return;
    }
    int m=(l+r)>>1;

    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}



int query(int L,int R,int l,int r,int rt,bool max){
    if(L<=l&&r<=R){

        if(max)
            return maxindex[rt];
        else
            return minindex[rt];

    }


    int m=(l+r)>>1;


    if(max){
        int ANS=L;
        if(L<=m){
            int temp=query(L,R,l,m,rt<<1,max);
            ANS=A[ANS]>A[temp]?ANS:temp;
        }

        if(R>m){
            int temp=query(L,R,m+1,r,rt<<1|1,max);
            ANS=A[ANS]>A[temp]?ANS:temp;
        }
        return ANS;
    }
    else{
        int ANS=L;
        if(L<=m){
            int temp=query(L,R,l,m,rt<<1,max);
            ANS=A[ANS]>A[temp]?temp:ANS;
        }

        if(R>m){
            int temp=query(L,R,m+1,r,rt<<1|1,max);
            ANS=A[ANS]>A[temp]?temp:ANS;
        }
        return ANS;
    }
}


int searchmin(int i,int n){

    if(A[i] >= A[i+1]){
            return -1;
        }
        int low = i+1, top = n, mid, key = i + 1;
        int v;
        while(low <= top){
            mid = low + top >> 1;
            v = A[query(i+1, mid,1,n,1,0)];

            if(v > A[i]){
                key = max(key, mid);
                low = mid + 1;
            } else {
                top = mid - 1;
            }
        }

        if(key == i + 1){
            return 1;
        }

        low = i + 1;
        top = key;
        int ret = key;

//        int mx = A[query(i, top,1,n,1,1)];
//        while(low <= top){
//            mid = low + top >> 1;
//            v = A[query(i, mid,1,n,1,1)];
//            if(v == mx){
//                ret = min(ret, mid);
//                top = mid - 1;
//            } else {
//                low = mid + 1;
//            }
//        }

        ret=query(i, ret,1,n,1,1);

        return ret - i;




}





int main(){



    int n;

    while(cin>>n){

        for(int i=1;i<=n;i++)
            scanf("%d",&A[i]);

        build(1,n,1);


        int maxlen=-1;

        for(int i=1;i<n;i++){

            maxlen=max(maxlen,searchmin(i,n));



        }


        printf("%d\n",maxlen);


    }

    return 0;
}

//5 5 0 0 5 4 5 1 5 6
