#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
typedef long long ll;

struct point{
    double a;
    double t;
}p[MAXN];
bool cmp(point &a,point &b){
    return a.a>b.a;
}

int main(){

    int N;
    scanf("%d",&N);
    double in=0;
    double cur=0;
    for(int i=0;i<N;i++){
        scanf("%lf%lf",&p[i].a,&p[i].t);
        in+=cur*p[i].t+1.0/2.0*p[i].a*p[i].t*p[i].t;
        cur=cur+p[i].a*p[i].t;
    }
    sort(p,p+N,cmp);
    double out=0;
    cur=0;
    for(int i=0;i<N;i++){
        out+=cur*p[i].t+1.0/2.0*p[i].a*p[i].t*p[i].t;
        cur=cur+p[i].a*p[i].t;
    }

    printf("%.1lf\n",fabs(out-in));

    return 0;
}












