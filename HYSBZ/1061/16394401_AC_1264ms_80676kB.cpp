#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
const int MAXM=10050;
const double INF=1e10;
const double eps=1e-7;
typedef long long ll;

int N,M;
double A[MAXM][MAXN],b[MAXM],c[MAXN],v;

void Pivot(int l,int e)
{
    b[l]/=A[l][e];
    for(int i=1;i<=N;i++)
        if(i!=e)
            A[l][i]/=A[l][e];
    A[l][e]=1/A[l][e];
    for(int i=1;i<=M;i++)
        if(i!=l && fabs(A[i][e])>eps)
        {
            b[i]-=A[i][e]*b[l];
            for(int j=1;j<=N;j++)
                if(j!=e)
                    A[i][j]-=A[i][e]*A[l][j];
            A[i][e]=-A[i][e]*A[l][e];
        }

    v+=c[e]*b[l];
    for(int i=1;i<=N;i++)
        if(i!=e)
            c[i]-=c[e]*A[l][i];
    c[e]=-c[e]*A[l][e];
}

double Simplex()
{
    int i,l,e;
    while(true)
    {
        for(i=1;i<=N;i++)
            if(c[i]>eps) 
                break;
        if((e=i)==N+1) 
            return v;
        double tmp=INF;
        for(i=1;i<=M;i++)
            if(A[i][e]>eps && b[i]/A[i][e]<tmp)
                tmp=b[i]/A[i][e],l=i;
        if(tmp==INF)
            return INF;
        Pivot(l,e);
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%lf",&c[i]);
    int x,y;
    for(int i=1;i<=M;i++){
        scanf("%d%d%lf",&x,&y,&b[i]);
        for(int j=x;j<=y;j++)
            A[i][j]=1;
    }
    double ans=Simplex();
    printf("%d\n",int(ans+0.5));
    return 0;
}


















