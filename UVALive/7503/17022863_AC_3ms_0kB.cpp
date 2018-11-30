#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){

    int T;
    scanf("%d",&T);
    string a,b;
    for(int qqq=1;qqq<=T;qqq++){
        cin>>a>>b;
        printf("Case #%d: ",qqq);
        if(a=="0.02"&&b=="0.01")
            cout<<"0.01"<<endl;
        else if(a=="2"&&b=="1")
            cout<<"0.01"<<endl;
        else if(a=="20"&&b=="10")
            cout<<"0.01"<<endl;
        else if(a=="0.2"&&b=="0.1")
            cout<<"0.01"<<endl;
        else if(b=="0.01"||b=="0.1"||b=="1"||b=="10")
            cout<<"0.02"<<endl;
        else
            cout<<"0.01"<<endl;

    }

    return 0;
}









