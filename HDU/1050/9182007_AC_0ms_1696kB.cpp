#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
typedef long long int ll;

int a[500];



int main(){


    int t;
    cin>>t;

    for(int qqq=1;qqq<=t;qqq++){


        memset(a,0,sizeof(a));


        int n;
        cin>>n;

        int ans=0;

        for(int i=0;i<n;i++){
            int a1,b;

            cin>>a1>>b;
            
            if(a1%2==0)  
                           a1--;  
                       if(b%2==0)  
                           b--;  

            if(b<a1)
                swap(a1,b);

            for(int j=a1;j<=b;j++){
                a[j]++;
                ans=max(ans,a[j]);
            }



        }

        cout<<ans*10<<endl;







    }

    return 0;
}
