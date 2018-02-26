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





int main(){


    int t;
    cin>>t;

    for(int qqq=1;qqq<=t;qqq++){




        int n;
        cin>>n;


        string ans;
        double cur_p=99999999;
        int cur_v=0;

        string str;
        double p;
        int v;

        for(int i=0;i<n;i++){
            cin>>str>>p>>v;
            int tempv=v;

            int tt=v/200;
            v=tt*200;

            if(v>1000)
                v=1000;

            if(v<200)
                continue;

            p=p/v;


            if(p<cur_p){
                cur_p=p;
                cur_v=tempv;
                ans=str;
            }

            if(p==cur_p){
                if(tempv>cur_v){
                cur_v=tempv;
                ans=str;
                }
            }

        }




        cout<<ans<<endl;



    }

    return 0;
}
