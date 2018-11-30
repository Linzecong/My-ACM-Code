#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 515;
const int MAXM = 1015;
const int MAXNODE=MAXN*MAXM+5;
const int INF = 0x3f3f3f3f;


struct DLX{

    int N,M,size;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE];
    int Row[MAXNODE],Col[MAXNODE];

    int H[MAXN],S[MAXM];

    int ansd;

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
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])
            for(int j=R[i];j!=i;j=R[j]){
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                --S[Col[j]];
            }
    }

    void resume(int c){
        for(int i=U[c];i!=c;i=U[i]){
            for(int j=L[i];j!=i;j=L[j])
                ++S[Col[U[D[j]]=D[U[j]]=j]];
        }
        L[R[c]]=R[L[c]]=c;
    }

    void dance(int d){
        if(ansd<d)
            return;
        if(R[0]==0){
            ansd=min(d,ansd);
            return;
        }

        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[c])
                c=i;
        remove(c);
        for(int i=D[c];i!=c;i=D[i]){
            for(int j=R[i];j!=i;j=R[j])
                remove(Col[j]);
            dance(d+1);
            for(int j=L[i];j!=i;j=L[j])
                resume(Col[j]);
        }
        resume(c);
    }
};
DLX g;


int main(){

    int T;
    scanf("%d",&T);

    while(T--){
        int N,M,P;
        scanf("%d%d%d",&N,&M,&P);
        int x1,y1,x2,y2;
        g.init(P,N*M);
        for(int k=1;k<=P;k++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i=x1+1;i<=x2;i++)
                for(int j=y1+1;j<=y2;j++)
                    g.Link(k,j+(i-1)*M);
        }
        g.ansd=INF;
        g.dance(0);

        if(g.ansd==INF)
            printf("%d\n",-1);
        else
            printf("%d\n", g.ansd);

    }



    return 0;
}





