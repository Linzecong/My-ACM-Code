#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char sta[MAXN];

bool know[MAXN];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){

        int N,A,B;
        scanf("%d%d%d",&N,&A,&B);

        if(A>=(N+1)/2&&B>=(N/2)){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;


    }

    return 0;
}
