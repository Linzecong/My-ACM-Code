#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int N,M,len;
char str[MAXN];

int A[MAXN];
int B[MAXN];
int pos;

bool getB(){
    for(int i=0;i<M;i++){
        int now=str[pos++]-'0';
        if(A[0]>now&&now!=0)
            now=now*10+str[pos++]-'0';
        if(now%A[0]==0){
            B[i]=now/A[0];
            if(B[i]>=10)
                return false;
        }
        else
            return false;
    }
    return true;
}

bool getA(){
    for(int i=1;i<N;i++){
        int now=str[pos++]-'0';
        if(B[0]>now&&now!=0)
            now=now*10+str[pos++]-'0';
        if(now%B[0]==0){
            A[i]=now/B[0];
            if(A[i]>=10)
                return false;
        }
        else
            return false;
        for(int j=1;j<M;j++){
            int now=str[pos++]-'0';
            if(A[i]>now&&now!=0)
                now=now*10+str[pos++]-'0';
            if(A[i]*B[j]!=now)
                return false;
        }
    }
    return true;
}


bool solve(){
    int one=str[0]-'0';
    int two=one*10+str[1]-'0';
    for(int i=1;i<=9;i++){
        pos=0;
        if(one%i==0){
            A[0]=i;
            if(getB()&&getA()&&pos==len)
                return true;
        }
    }

    for(int i=1;i<=9;i++){
        pos=0;
        if(two%i==0&&two/i<10){
            A[0]=i;
            if(getB()&&getA()&&pos==len)
                return true;
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        scanf("%s",str);
        len=strlen(str);

        if(solve()){
            for(int i=0;i<N;i++)
                printf("%d",A[i]);
            printf(" ");
            for(int i=0;i<M;i++)
                printf("%d",B[i]);
            puts("");
        }
        else
            printf("Impossible\n");
    }

    return 0;
}


