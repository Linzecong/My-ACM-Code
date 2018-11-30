#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAXN = 16*16*16+10;
const int MAXM = 16*16*4+10;
const int MAXNODE=MAXN*MAXM+MAXM;
const int INF = 0x3f3f3f3f;

char s[20][20];

struct DLX{

    int N,M,size;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE];
    int Row[MAXNODE],Col[MAXNODE];

    int H[MAXN],S[MAXM];

    int ansd;
    int ansh[MAXN];

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

    bool dance(int d){
        //if(ansd<d)
        //    return;

        if(R[0]==0){
            ansd=d;
            return 1;
        }

        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[c])
                c=i;
        remove(c);
        for(int i=D[c];i!=c;i=D[i]){
            ansh[d]=Row[i];
            for(int j=R[i];j!=i;j=R[j])
                remove(Col[j]);
            if(dance(d+1))return 1;
            for(int j=L[i];j!=i;j=L[j])
                resume(Col[j]);
        }
        resume(c);
        return false;
    }
};
DLX g;


struct DLX_C{

    int N,M,size;
    int U[MAXNODE],D[MAXNODE],R[MAXNODE],L[MAXNODE];
    int Row[MAXNODE],Col[MAXNODE];
    int H[MAXN],S[MAXM];
    int K;
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
//DLX_C g;


int encode(int a,int b,int c)
{
    return a*256+b*16+c+1;//加2是为了保证，DLX中行编号是从1开始
}
void decode(int code,int &a,int &b,int &c)
{
    code--;
    c=code%16;code/=16;
    b=code%16;code/=16;
    a=code;
}


int main(){

    bool first=true;
    while(scanf("%s",s[0])!=EOF)
    {
        if(first)first=false;
        else printf("\n");

        for(int i=1;i<16;i++)
            scanf("%s",s[i]);
        g.init(16*16*16,16*16*4);

        for(int r=0;r<16;r++)
            for(int c=0;c<16;c++)
                for(int v=0;v<16;v++)
                    if(s[r][c]=='-'||s[r][c]=='A'+v)
                    {
                        int row=encode(r,c,v);
                        g.Link(row,encode(0,r,c));
                        g.Link(row,encode(1,r,v));
                        g.Link(row,encode(2,c,v));
                        g.Link(row,encode(3,(r/4)*4+c/4,v));
                    }
        g.dance(0);
        for(int i=0;i<g.ansd;i++)
        {
            int r,c,v;
            decode(g.ansh[i],r,c,v);
            s[r][c]='A'+v;
        }
        for(int i=0;i<16;i++)
            printf("%s\n",s[i]);
    }

    return 0;
}





