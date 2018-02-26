#include <iostream>
using namespace std;

int pre[1010];

int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}


int main(){

    int t;
    cin>>t;
    int n,k;
    while(t--){
        cin>>n>>k;

        for(int i=0;i<=n;i++)
            pre[i]=i;
        int count=n;

        int a,b;
        int ar,br;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            ar=find(a);
            br=find(b);
            if(ar!=br){
                pre[br]=ar;
                count--;
            }
        }
        cout<<count<<endl;
    }




    return 0;
}
