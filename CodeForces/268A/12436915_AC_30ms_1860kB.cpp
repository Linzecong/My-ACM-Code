#include<iostream>
#include<algorithm>
using namespace std;
int h[100];
int g[100];

int main(){

    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>h[i]>>g[i];
    }

    int ans=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(i!=j)
                if(h[i]==g[j])
                    ans++;
        }
    }
    cout<<ans<<endl;





    return 0;
}