#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;
const int M=100007;
const int N=320;
typedef unsigned long long LL;

inline int rd(){
    int x=0;bool f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    return f?x:-x;
}

int n,m,sn,MX;
LL val[M];
struct node{int l,r;}q[M];

LL sum1[N];
LL sum2[N][N];
LL cov[N][M];
LL all[N];

int loc(int x){
    return x/sn+1;
}

int getL(int x){
    return max((x-1)*sn,1);
}

int getR(int x){
    return min(x*sn-1,n);
}

int getP(int x){
    int L=getL(loc(x));
    return x-L+1;
}

void init_sum(int x){
    int i,L=getL(x),R=getR(x);
    LL nw=0;
    for(i=L;i<=R;i++){
        nw+=val[i];
        sum2[x][getP(i)]=nw;
    }
    sum2[x][sn]=nw;//这样方便
    for(int i=x;i<=MX;i++) sum1[i]=sum1[i-1]+sum2[i][sn];
}

LL get_sum(int x,int y){
    int L,R,BL,BR;
    BL=loc(x); BR=loc(y);
    if(BL+1>=BR){
        if(BL==BR) return sum2[BL][getP(y)]-sum2[BL][getP(x)-1];
        
        return sum2[BR][getP(y)]-sum2[BL][getP(x)-1]+sum2[BL][sn];
    }
    else{
        if(getL(BL)!=x) BL++;
        if(getR(BR)!=y) BR--;
        L=getL(BL); R=getR(BR);
        LL res=sum1[BR]-sum1[BL-1];
        if(R!=y) res+=sum2[BR+1][getP(y)];
        if(L!=x) res+=sum2[BL-1][sn]-sum2[BL-1][getP(x)-1];
        return res;
    }
}

void init_cov(int x){
    int L=getL(x),R=getR(x);
    for(int i=L;i<=R;i++){
        cov[x][q[i].l]++;
        cov[x][q[i].r+1]--;
        all[x]+=get_sum(q[i].l,q[i].r);
    }
    for(int i=1;i<=n;i++){
        cov[x][i]+=cov[x][i-1];
    }
}

int main(){
    int i,kd,x,y,BL,BR,L,R;
    n=rd();
    sn=(int)sqrt(n);
    MX=loc(n);
    
    for(i=1;i<=n;i++) val[i]=rd();
    
    for(i=1;i<=n;i++) q[i].l=rd(),q[i].r=rd();

    for(i=1;i<=MX;i++) init_sum(i); 
    for(i=1;i<=MX;i++) 
        init_cov(i);

    m=rd();
    
    while(m--){
        kd=rd();
        x=rd(),y=rd();
        if(kd==1){
            y-=val[x];
            val[x]+=y;
            init_sum(loc(x));
            for(i=1;i<=MX;i++) all[i]+=cov[i][x]*y;
        }
        else{
            LL ans=0;
            BL=loc(x); BR=loc(y);
            
            if(BL+1>=BR){
                for(i=x;i<=y;i++) ans+=get_sum(q[i].l,q[i].r);
            }
            else{
                if(getL(BL)!=x) BL++;
                if(getR(BR)!=y) BR--;
                L=getL(BL); R=getR(BR);
                for(i=BL;i<=BR;i++) ans+=all[i];
                for(i=x;i<L;i++) ans+=get_sum(q[i].l,q[i].r);
                for(i=y;i>R;i--) ans+=get_sum(q[i].l,q[i].r);
            }
            printf("%llu\n",ans);
        }
    }
    
    return 0;
}