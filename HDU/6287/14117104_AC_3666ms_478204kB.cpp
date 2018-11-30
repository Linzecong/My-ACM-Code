#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
typedef long long int ll;
const int MAXN=100015;
typedef pair<int,int> pii;
vector<pii> V[MAXN];
void init(){
    int cnt;
    for(int i=2; i<MAXN; i++){
        int x = i;
        for(int j=2; j*j<=x; j++){
            cnt = 0;
            while(x % j == 0){
                cnt++;
                x /= j;
            }
            if(cnt){
                V[i].push_back(make_pair(j, cnt));
            }
        }
        if(x > 1){
            V[i].push_back(make_pair(x, 1));
        }
    }
}

int N,Q;
int sum[MAXN*400];
int ls[MAXN*400];
int rs[MAXN*400];
int T[MAXN];
int tot=0;
void update(int P,int C,int l,int r,int &rt,int lrt){
    rt=++tot;
    ls[rt]=ls[lrt];
    rs[rt]=rs[lrt];
    sum[rt]=sum[lrt];
    if(l==r){
        sum[rt]+=C;
        return;
    }
    int m=(l+r)/2;
    if(P<=m)
        update(P,C,l,m,ls[rt],ls[lrt]);
    else
        update(P,C,m+1,r,rs[rt],rs[lrt]);
}

int query(int L,int R,int l,int r,int rt,int lrt){
    
    if(L<=l&&r<=R){
        return sum[lrt]-sum[rt];
    }
    int m=(l+r)/2;
    
    int ans=0;
    if(L<=m)
        ans+=query(L,R,l,m,ls[rt],ls[lrt]);
    if(R>m)
        ans+=query(L,R,m+1,r,rs[rt],rs[lrt]);
    return ans;
}



int main()
{
    init();
    int tt;
    scanf("%d",&tt);
    while(tt--){
        tot=0;
        memset(sum,0,sizeof(sum));
        memset(ls,0,sizeof(ls));
        memset(rs,0,sizeof(rs));
        
        int N,M;
        scanf("%d%d",&N,&M);
        int a;
        for(int i=1;i<=N;i++){
            scanf("%d",&a);
            if(a==1)
                T[i]=T[i-1];
            else{
                int pre=T[i-1];
                for(int j=0;j<V[a].size();j++){
                    update(V[a][j].first,V[a][j].second,1,MAXN-1,T[i],pre);
                    pre=T[i];
                }
            }
        }
        
        int l,r,d;
        while(M--){
            scanf("%d%d%d",&l,&r,&d);
            
            if(d==1){
                printf("Yes\n");
            }
            else{
                bool flag=1;
                
                for(int j=0;j<V[d].size();j++){
                    if(query(V[d][j].first,V[d][j].first,1,MAXN-1,T[l-1],T[r])<V[d][j].second)
                        flag=0;
                }
                
                
                if(flag)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            
        }
        
    }
    
    return 0;
}




