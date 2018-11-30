#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#define INF (0x3f3f3f3f)
using namespace std;
typedef long long int ll;
const int MAXN=200010;

ll X[MAXN];
ll Y[MAXN];
int tot;
vector<int> V[MAXN*30];
int ls[MAXN*30];
int rs[MAXN*30];
int ans;

bool check(ll x1,ll y1,ll x2,ll y2){
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<y1*y1)
        return 1;
    return 0;
}

void update(int L,int R,int C,int l,int r,int &rt){

    if(!rt)
        rt=++tot;
    if(L<=l&&r<=R)
    {
        V[rt].push_back(C);
        return;
    }
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,C,l,m,ls[rt]);
    if(R>m)
        update(L,R,C,m+1,r,rs[rt]);
}

void update(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        vector<int> tmp;
        for(auto &t:V[rt]){
            if(t!=ans){
                tmp.push_back(t);
            }
        }
        V[rt]=tmp;
        return;
    }
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,l,m,ls[rt]);
    if(R>m)
        update(L,R,m+1,r,rs[rt]);
}

void query(int L,int R,int l,int r,int rt){
    if(!rt)
        return;
    for(auto &t:V[rt]){
        if(check(X[t],Y[t],L,R)){
            ans=t;
            return;
        }
    }
    if(l==r)
        return;
    int m=(l+r)>>1;
    if(L<=m)
        query(L,R,l,m,ls[rt]);
    else
        query(L,R,m+1,r,rs[rt]);
}



int main(){

    int N;
    scanf("%d",&N);
    int rt=0;
    for(int i=1;i<=N;i++){

        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            X[i]=x;
            Y[i]=y;
            update(x-y,x+y,i,-INF,INF,rt);
        }
        else{
            ans=-1;
            query(x,y,-INF,INF,rt);
            printf("%d\n",ans);
            if(ans!=-1)
                update(X[ans]-Y[ans],X[ans]+Y[ans],-INF,INF,rt);
        }
    }


    return 0;
}





