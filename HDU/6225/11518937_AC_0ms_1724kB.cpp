#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;



int main(){

 //  cout<<((1uLL<<62)-1)+(1uLL<<62)+ (1uLL<<62)+(1uLL<<62)<<endl;
    int t;
    scanf("%d",&t);

    while(t--){
        unsigned long long int a,b,c,d;
        cin>>a>>b>>c>>d;


        if(a+b+c+d<=0&&(a|b|c|d)){
            cout<<"18446744073709551616"<<endl;
        }
        else

        cout<<a+b+c+d<<endl;

    }

    return 0;
}






