#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char sta[MAXN];

bool know[MAXN];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){

    double A,B,C;
       int X;

       scanf("%lf%lf%lf",&A,&B,&C);
       scanf("%d",&X);

       double fir=sqrt((2*C+B)*(2*C+B)+A*A);


       double thr=sqrt((2*C+B-B*X/100.0)*(2*C+B-B*X/100.0)+(A-A*X/100.0)*(A-A*X/100.0));

       double forth=sqrt(A*A+B*B)*X/100.0;

       printf("%.12lf\n",fir+thr+forth);

    }

    return 0;
}
