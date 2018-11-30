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
#include <bitset>
using namespace std;
typedef long long ll;
const int MAXN = 100505;

int lowbit(int x){
    return x&-x;
}

int tree[MAXN];
int sum(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=tree[i];
    }
    return sum;
}

void add(int x,int C){
    for(int i=x;i<=MAXN;i+=lowbit(i))
        tree[i]+=C;
}

struct Query{
    int l;
    int r;
    int id;
}q[MAXN];

int block[MAXN];

bool cmp(Query a,Query b){
    if(block[a.l]==block[b.l])
        return a.r<b.r;
    return block[a.l]<block[b.l];
}


int a[MAXN];
int ans[MAXN];
int tot=0;
int N,Q;

bool judge(int x){
    if(tot-sum(x-1)-x>=0)
        return true;
    return false;

}

void solve(){

    int l=1;
    int r=1;
    add(a[l],1);
    tot++;
    for(int i=0;i<Q;i++){
        
        while(q[i].r>r){
            r++;
            add(a[r],1);
            tot++;
        }
        while(q[i].r<r){
            add(a[r],-1);
            r--;
            tot--;
        }
        while(q[i].l>l)
        {
            add(a[l],-1);
            l++;
            tot--;
        }
        while(q[i].l<l){
            l--;
            add(a[l],1);
            tot++;
        }

        int ll=1;
        int rr=N;
        int m;
        while(ll<=rr){
            m=(ll+rr)/2;
            if(judge(m)){
                ll=m+1;
            }
            else
                rr=m-1;
        }
        ans[q[i].id]=rr;


    }


}


int main()
{


    while(~scanf("%d%d",&N,&Q)){
        tot=0;
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        
        int bz = sqrt(N);
        for(int i=1;i<=N;i++)
            block[i]=(i-1)/(bz)+1;

        for(int i=0;i<Q;i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].id=i;
        }
        sort(q,q+Q,cmp);

        solve();

        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);


    }
    

    return 0;
}
