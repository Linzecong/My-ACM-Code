#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int num[MAXN<<2];
int flag[MAXN<<2];

void pushup(int rt,int l,int r){
    num[rt]=num[rt<<1]+num[rt<<1|1];
    if(flag[rt]%2==1)
        num[rt]=(r-l+1)-num[rt];
}

void update(int L,int R,int l,int r,int rt,int f){
    if(L<=l&&r<=R){
        flag[rt]+=f;
        num[rt]=(r-l+1)-num[rt];
        return;
    }
    int m=(l+r)/2;
    //pushdown(rt,m-l+1,r-m);
    if(L<=m)
        update(L,R,l,m,rt<<1,f);
    if(R>m)
        update(L,R,m+1,r,rt<<1|1,f);
    pushup(rt,l,r);
}

struct query{
    int x1, y1, y2,flag;
}q[MAXN*2];
int tot=0;
bool cmp(query &a,query &b){
    return a.x1<b.x1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int N,K;
        tot=0;
        scanf("%d%d",&N,&K);
        memset(num,0,sizeof(num));
        memset(flag,0,sizeof(flag));
        int x1,x2,y1,y2;
        for(int i=0;i<K;i++){
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            q[++tot]={x1,y1,y2,1};
            q[++tot]={x2+1,y1,y2,-1};
        }
        sort(q+1,q+tot+1,cmp);
        int ans=0;

        q[0].x1=q[1].x1;
        for(int i=1;i<=tot;i++){
            ans+=num[1]*(q[i].x1-q[i-1].x1);
            update(q[i].y1,q[i].y2,1,N,1,q[i].flag);
        }
        cout<<ans<<endl;
    }


    return 0;
}












