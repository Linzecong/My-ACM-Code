#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;


int num[30];



int main(){
    int T;
    scanf("%d",&T);
    while(T--){

        int one=0;
        int two=0;
        for(int i=1;i<=26;i++){
            scanf("%d",&num[i]);
            if(num[i]==1)
                one++;
            if(num[i]>=2)
                two++;
        }

        cout<<two*2+(one>0)<<" ";

        int minn=0x3f3f3f3f;
        for(int i=1;i<=26;i++){

            if(num[i]>=2){
                minn=min(num[i]/2,minn);
            }
        }

        if(minn==0x3f3f3f3f){
            cout<<one<<endl;
        }
        else{

            if(one==0)
                cout<<minn<<endl;
            else{
                cout<<min(minn,one)<<endl;
            }
        }



    }

    return 0;
}

