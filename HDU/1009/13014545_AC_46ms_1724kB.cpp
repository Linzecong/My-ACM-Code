#include<iostream>
#include<algorithm>
using namespace std;

int J[100005];
int F[100005];
double C[100005];

struct point{
    int J,F;
    double C;
}P[100005];
bool cmp(point a,point b){
    return a.C>b.C;
}

int M,N;
int main(){

    while(~scanf("%d%d",&M,&N)){
        if(M==-1&&N==-1)
            break;
        for(int i=1;i<=N;i++){
            scanf("%d%d",&P[i].J,&P[i].F);
           P[i].C=double(P[i].J)/double(P[i].F);
        }

        sort(P+1,P+N+1,cmp);

        double sum=0;
        int i=1;
        while(M){
            if(i==N+1)
                break;
            if(M>P[i].F){
                M-=P[i].F;
                sum+=P[i].J;
            }
            else{
                sum+=P[i].C*M;
                M=0;
            }
            i++;
            
        }
        printf("%.3lf\n",sum);


    }




    return 0;
}