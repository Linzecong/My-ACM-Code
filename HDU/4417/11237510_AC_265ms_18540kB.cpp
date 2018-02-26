#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<iomanip>
#include<cmath>
#include<bitset>
#define INF 0x3f3f3f3f
const int Max=30*100000;
typedef long long int ll;
using namespace std;


int ls[Max];
int rs[Max];
int sum[Max];
int tot=0;

void build(int &root,int l,int r){
    root=++tot;

    if(l==r) {
        sum[root]=0;
        ls[root]=root;
        rs[root]=root;
        return ;
    }

    int mid=(l+r)/2;
    build(ls[root],l,mid);
    build(rs[root],mid+1,r);
    sum[root]=sum[ls[root]]+sum[rs[root]];
}

void update(int last,int &root,int l,int r,int x,int v){
    root=++tot;

    ls[root]=ls[last];
    rs[root]=rs[last];
    sum[root]=sum[last];

    if(l==r) {
        sum[root]+=v;
        ls[root]=root;
        rs[root]=root;
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(ls[last],ls[root],l,mid,x,v);
    else update(rs[last],rs[root],mid+1,r,x,v);

    sum[root]=sum[ls[root]]+sum[rs[root]];
}

int query(int root,int l,int r,int x){
    if(l==r){
        return sum[root];
    }
    int mid=(l+r)/2;
    if(x>mid) return sum[ls[root]]+query(rs[root],mid+1,r,x);
    else return query(ls[root],l,mid,x);
}


int root[Max];
ll a[100100],b[100100];
int n,m;
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        tot=0;
        memset(root,0,sizeof(root));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {
            scanf("%I64d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int cnt=unique(b+1,b+n+1)-(b+1);
        b[++cnt]=INF;
        build(root[0],1,cnt);
        for(int i=1;i<=n;i++){
            int x=lower_bound(b+1,b+cnt+1,a[i])-b;
            update(root[i-1],root[i],1,cnt,x,1);
        }
        printf("Case %d:\n",cas);
        for(int i=1;i<=m;i++){
            int l,r;
            ll v;
            scanf("%d%d%I64d",&l,&r,&v);l++;r++;
            int x=upper_bound(b+1,b+cnt+1,v)-b-1;
            int R=0,L=0;
            if(x>0){
                L=query(root[l-1],1,cnt,x);
                R=query(root[r],1,cnt,x);
            }
            printf("%d\n",R-L);
        }
    }
    return 0;
}
