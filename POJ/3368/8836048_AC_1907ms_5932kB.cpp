#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

const int maxn=100020;



int maxindex[maxn<<2];



map<int,int> m;

int A[maxn];
map<int,int> rindex;


vector<int> shuzu;

void pushup(int rt){
    maxindex[rt]=A[maxindex[rt<<1]]>A[maxindex[rt<<1|1]]?maxindex[rt<<1]:maxindex[rt<<1|1];

}


void build(int l,int r,int rt){
    if(l==r){
        maxindex[rt]=l;
        return;
    }
    int m=(l+r)>>1;

    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}



int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){

        return maxindex[rt];


    }


    int m=(l+r)>>1;



    int ANS=L;
    if(L<=m){
        int temp=query(L,R,l,m,rt<<1);
        ANS=A[ANS]>A[temp]?ANS:temp;
    }

    if(R>m){
        int temp=query(L,R,m+1,r,rt<<1|1);
        ANS=A[ANS]>A[temp]?ANS:temp;
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

        int zu=0;
        shuzu.clear();
        m.clear();

        rindex.clear();




        for(int i=1;i<=n;i++){

            int temp;
            scanf("%d",&temp);
            shuzu.push_back(temp);


            if(m.find(shuzu[i-1])==m.end()){
                zu++;
                m[shuzu[i-1]]=zu;
                A[zu]=1;
                rindex[shuzu[i-1]]=i;
            }else{
                A[m[shuzu[i-1]]]++;
                rindex[shuzu[i-1]]=i;
            }
        }



        build(1,zu,1);


        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);

            int lz=m[shuzu[a-1]];
            int rz=m[shuzu[b-1]];

            if(lz==rz)
                printf("%d\n",b-a+1);
            else{
                if(rz-lz==1){



                    int lc=rindex[shuzu[a-1]] -a+1;
                    int rc=b-a+1-lc;


                    printf("%d\n",max(lc,rc));
                }
                else{
                    int lc=rindex[shuzu[a-1]]  -a+1;
                    int rc=b - (rindex[shuzu[b-1]]-A[m[shuzu[b-1]]]);


                    printf("%d\n",max(lc,max(rc,A[query(lz+1,rz-1,1,zu,1)])));
                }

            }


        }







    }
    return 0;
}
