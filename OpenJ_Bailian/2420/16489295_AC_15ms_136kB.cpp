#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const double eps=1e-8;
const double V=0.98;
typedef long long ll;

int N;
double X[MAXN];
double Y[MAXN];
double dx[8]={-1,-1,0,1,1,1,0,-1};
double dy[8]={0,1,1,1,0,-1,-1,-1};

double dis(double x,double y){
    double ret=0;
    for(int i=1;i<=N;i++)
        ret+=sqrt((x-X[i])*(x-X[i])+(y-Y[i])*(y-Y[i]));
    return ret;
}

double rand01()
{
    double t1=(double)(rand()%1000)/(double)1000,
           t2=(double)(rand()%1000)/(double)1000;
    double r=t1+t2*0.001;
    return r;
}

double tuihuo(){

    double x=rand()%10000,y=rand()%10000;
    double ans=dis(x,y);

    double dt=10000;

    while(dt>eps){

        double tans=1e99;
        double mx,my;
        for(int i=0;i<8;i++){
            double nx=x+dx[i]*dt;
            double ny=y+dy[i]*dt;
            double d=dis(nx,ny);
            if(d<tans){
                mx=nx;
                my=ny;
                tans=d;
            }
        }
        if(tans<ans){
            x=mx;
            y=my;
            ans=tans;
        }
//        else{
//            if(exp(ans-tans)/dt>rand01()){
//                x=mx;
//                y=my;
//                ans=tans;
//            }
//        }
        dt*=V;
    }
    return ans;
}


int main(){


    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%lf%lf",&X[i],&Y[i]);

    printf("%.0lf\n",tuihuo());

    return 0;
}
