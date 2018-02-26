#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=200005;

int dsll[maxn<<2],dsrl[maxn<<2],dsml[maxn<<2],dslazy[maxn<<2];
int nsll[maxn<<2],nsrl[maxn<<2],nsml[maxn<<2],nslazy[maxn<<2];

//ls,左端最大连续区间，rs右端最大连续区间，ms区间内最大连续区间

void build(int l,int r,int rt){

    dslazy[rt] = nslazy[rt] = -1;
    dsll[rt] = dsrl[rt] = dsml[rt] = r - l + 1;
    nsll[rt] = nsrl[rt] = nsml[rt] = r - l + 1;

    if(l==r){
        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);

}

void nspushdown(int l, int r, int rt){
    if(~nslazy[rt]){
        int m = (l + r) >> 1;
        nslazy[rt<<1] = nslazy[rt<<1|1] = nslazy[rt];
        nsll[rt<<1] = nsrl[rt<<1] = nsml[rt<<1] = (m - l + 1) * nslazy[rt];
        nsll[rt<<1|1] = nsrl[rt<<1|1] = nsml[rt<<1|1] = (r - m) * nslazy[rt];
        nslazy[rt] = -1;
    }
}



void dspushdown(int l,int r,int rt){
    if(~dslazy[rt]){
        int m = (l + r) >> 1;

        dslazy[rt<<1] = dslazy[rt<<1|1] = dslazy[rt];

        dsll[rt<<1] = dsrl[rt<<1] = dsml[rt<<1] = (m - l + 1) * dslazy[rt];

        dsll[rt<<1|1] = dsrl[rt<<1|1] = dsml[rt<<1|1] = (r - m) * dslazy[rt];

        dslazy[rt] = -1;
    }
}


void dsupdate(int L,int R,int C, int l, int r, int rt){


    if(L<=l&&r<=R){
        dslazy[rt]=C;

        dsll[rt] = dsrl[rt] = dsml[rt] = (r - l + 1) * C;

        return;
    }

    dspushdown(l,r,rt);


    int m=(l+r)/2;


    if(L <= m) //与查询同理
        dsupdate(L,R,C,l,m,rt<<1);
    if(R >  m)
        dsupdate(L,R,C,m+1,r,rt<<1|1);


    //pushup
    if((dsll[rt] = dsll[rt<<1]) == m - l + 1) dsll[rt] += dsll[rt<<1|1];
    if((dsrl[rt] = dsrl[rt<<1|1]) == r - m) dsrl[rt] += dsrl[rt<<1];

    dsml[rt] = max(max(dsml[rt<<1], dsml[rt<<1|1]), dsrl[rt<<1] + dsll[rt<<1|1]);



}

void nsupdate(int L, int R, int c, int l, int r, int rt)
{
    if(l >= L && r <= R){
        nslazy[rt] = c;
        nsll[rt] = nsrl[rt] = nsml[rt] = (r - l + 1) * c;
        return;
    }
    nspushdown(l, r, rt);

    int m = (l + r) >> 1;
    if(L <= m) nsupdate(L, R, c, l,m,rt<<1);
    if(R > m) nsupdate(L, R, c, m+1,r,rt<<1|1);

    if((nsll[rt] = nsll[rt<<1]) == m - l + 1) nsll[rt] += nsll[rt<<1|1];
    if((nsrl[rt] = nsrl[rt<<1|1]) == r - m) nsrl[rt] += nsrl[rt<<1];
    nsml[rt] = max(max(nsml[rt<<1], nsml[rt<<1|1]), nsrl[rt<<1] + nsll[rt<<1|1]);
}



//查询len长度的时间段起点 不存在则返回0
int dsquery(int len, int l, int r, int rt)
{
    if(len > dsml[rt]) return 0;
    int m = (l + r) >> 1;
    if(len <= dsll[rt]) return l;
    if(len <= dsml[rt<<1]) return dsquery(len, l,m,rt<<1);
    else if(len <= dsrl[rt<<1] + dsll[rt<<1|1]) return m + 1- dsrl[rt<<1];
    else return dsquery(len, m+1,r,rt<<1|1);
}

int nsquery(int len, int l, int r, int rt)
{
    if(len > nsml[rt]) return 0;
    int m = (l + r) >> 1;
    if(len <= nsll[rt]) return l;
    if(len <= nsml[rt<<1]) return nsquery(len, l,m,rt<<1);
    else if(len <= nsrl[rt<<1] + nsll[rt<<1|1]) return m + 1- nsrl[rt<<1];
    else return nsquery(len, m+1,r,rt<<1|1);
}


int main(){

    int t;
    scanf("%d",&t);
int n,m;
    for(int qqq=1;qqq<=t;qqq++){
        int x,y,len;
        char order[10];
        scanf("%d%d",&n,&m);
        build(1,n,1);

        printf("Case %d:\n", qqq);
        while(m--){
            scanf("%s",order);
            if(order[0] == 'D'){
                scanf("%d", &len);
                x = dsquery(len, 1, n, 1);
                if(x){
                    y = x + len - 1;
                    dsupdate(x, y, 0, 1, n, 1);
                    printf("%d,let's fly\n", x);
                }
                else puts("fly with yourself");
            }
            else if(order[0] == 'N'){
                scanf("%d", &len);
                x = dsquery(len, 1, n, 1);
                if(x){
                    y = x + len - 1;
                    dsupdate(x, y, 0, 1, n, 1);
                    nsupdate(x, y, 0, 1, n, 1);
                    printf("%d,don't put my gezi\n", x);
                }
                else{
                    x = nsquery(len, 1, n, 1);
                    if(x){
                        y = x + len - 1;
                        dsupdate(x, y, 0, 1, n, 1);
                        nsupdate(x, y, 0, 1, n, 1);
                        printf("%d,don't put my gezi\n", x);
                    }
                    else puts("wait for me");
                }
            }
            else{
                scanf("%d%d", &x, &y);
                dsupdate(x, y, 1, 1, n, 1);
                nsupdate(x, y, 1, 1, n, 1);
                puts("I am the hope of chinese chengxuyuan!!");
            }



        }



    }


    return 0;
}







