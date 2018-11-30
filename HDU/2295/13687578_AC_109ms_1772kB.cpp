#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 55;
const int MAXM = 55;
const int MAXNODE=MAXN*MAXM+MAXM;
const int INF = 0x3f3f3f3f;

int K;
struct DLX_C{

    int N,M,size;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE];
    int Row[MAXNODE],Col[MAXNODE];
    int H[MAXN],S[MAXM];


    void init(int n,int m){
        N=n;
        M=m;
        for(int i=0;i<=M;i++){
            S[i]=0;
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[M]=0;
        L[0]=M;
        size=M;
        for(int i=1;i<=N;i++)
            H[i]=-1;
    }

    void Link(int r,int c){
        ++S[Col[++size]=c];
        Row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0){
            H[r]=L[size]=R[size]=size;
        }
        else{
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }

    void remove(int c){
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i];
    }

    void resume(int c){
        for(int i=U[c];i!=c;i=U[i])
            L[R[i]]=R[L[i]]=i;
    }

    bool v[MAXNODE];
    int f()
    {
        int ret = 0;
        for(int c = R[0];c != 0;c = R[c])v[c] = true;
        for(int c = R[0];c != 0;c = R[c])
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c];i != c;i = D[i])
                    for(int j = R[i];j != i;j = R[j])
                        v[Col[j]] = false;
            }
        return ret;

    }

    bool dance(int d)
    {
        if(d + f() > K)return false;
        if(R[0] == 0)return d <= K;
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            if(dance(d+1))return true;
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
        return false;
    }
};
DLX_C g;


struct Point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}city[MAXM],station[MAXN];
double dis(Point a,Point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}

int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<N;i++)
            city[i].input();
        for(int i=0;i<M;i++)
            station[i].input();

        double l=0,r=1e4;
        double eps=(1e-8);
        while(r-l>=eps){
            double m=(l+r)/2;
            g.init(M,N);
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                    if(dis(station[i],city[j])<m-eps)
                        g.Link(i+1,j+1);
            if(g.dance(0))
                r=m-eps;
            else
                l=m+eps;
        }
        printf("%.6lf\n",l);

    }

    return 0;
}





