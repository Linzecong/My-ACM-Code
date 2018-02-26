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

//扫描线-
struct Edge{
    double l,r;//左右端点
    double h;//高
    int flag;//上边还是下边
    Edge(double a,double b,double c,int d){
        l=a;
        r=b;
        h=c;
        flag=d;
    }
Edge(){}
}E[maxn];

bool cmp(Edge a,Edge b){
    return a.h<b.h;
}


int cover[maxn<<2],n, cnt, res;
double len[maxn<<2];
double X[2*maxn];



void pushup(int rt,int l,int r){
    if(cover[rt]){
        len[rt]=X[r+1]-X[l];
    }
    else if(l==r) len[rt]=0;
    else len[rt]=len[rt<<1]+len[rt<<1|1];
}


void update(int L,int R,int C, int l, int r, int rt){
    if(L<=l&&r<=R){
        cover[rt]+=C;
        pushup(rt,l,r);
        return;
    }

    int m=(l+r)/2;


    if(L <= m) //与查询同理
        update(L,R,C,l,m,rt<<1);
    if(R >  m)
        update(L,R,C,m+1,r,rt<<1|1);

    pushup(rt,l,r);
}

int binary_find(double x){
    int lb = -1,ub = res - 1;
    while(ub - lb > 1){
        int mid = (lb + ub) >> 1;
        if(X[mid] >= x) ub = mid;
        else lb = mid;
    }
    return ub;
}


int main(){

    int cas = 1;
       while(~ scanf("%d", &n), n) {
           cnt = res = 0;
           for(int i = 0 ; i < n; i ++) {
               double a,b,c,d;
               scanf("%lf%lf%lf%lf",&a, &b, &c,&d);

               E[cnt] = Edge(a, c, b, 1);

               X[cnt++] = a;

               E[cnt] = Edge(a, c, d, -1);

               X[cnt++] = c;

           }

           sort(X, X + cnt);

           sort(E, E + cnt,cmp);

           res ++;
           for(int i = 1; i < cnt; i ++) {
               if(X[i] != X[i - 1]) X[res++] = X[i];
           }

           memset(len, 0, sizeof(len));
           memset(cover, 0, sizeof(cover));

           double ans = 0;
           for(int i = 0;i < cnt - 1;i ++){
               int l = binary_find(E[i].l);
               int r = binary_find(E[i].r) - 1;//利用[ , ),这个区间性质，左闭右开

               update(l, r, E[i].flag, 0, res-1,1);

               ans += len[1] * (E[i + 1].h - E[i].h);
           }
           printf("Test case #%d\nTotal explored area: %.2lf\n\n",cas++ , ans);
       }


    return 0;
}







