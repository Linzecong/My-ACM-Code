#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const double eps=1e-8;
const double V=0.98;
typedef long long ll;

int N;
double X[MAXN];
double Y[MAXN];
double dx[8]={-1,1,0,0,1,1,-1,-1};
double dy[8]={0,0,-1,1,-1,1,-1,1};

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

    double x=0,y=0;
    double ans=1e99;

    double dt=100;

    while(dt>eps){
        bool flag=1;

        while(flag){
            flag=0;
            for(int i=0;i<4;i++){
                double nx=x+dx[i]*dt;
                double ny=y+dy[i]*dt;
                double d=dis(nx,ny);
                if(d<ans){
                    x=nx;
                    y=ny;
                    ans=d;
                    flag=1;
                }
                //                else{
                //                    if(exp(ans-d)/dt>rand01()){
                //                        x=nx;
                //                        y=ny;
                //                        ans=d;
                //                    }
                //                }
            }
        }


        dt*=V;
    }
    return ans;
}


int main(){


    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%lf%lf",&X[i],&Y[i]);

//    double ans=1e99;
//    for(int i=0;i<10;i++)
//        ans=min(ans,tuihuo());

    printf("%.0lf\n",tuihuo());

    return 0;
}





