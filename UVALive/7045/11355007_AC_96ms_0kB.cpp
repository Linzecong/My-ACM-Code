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

ll q,p;
ll a[100005];
int main(){

    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;

    for(int qqq=1;qqq<=t;qqq++){

        //R cin>>n;


        cin>>q>>p;

        a[0]=q;
        a[1]=p;

        //  printf("Case #%d: %lld\n",qqq,a[0]/a[1]+4);


//                set<int> ss;
//                ss.insert(a[0]);
//                ss.insert(a[1]);

//                for(int i=2;i<10000;i++){
//                    a[i]=abs(a[i-1]-a[i-2]);
//                   // cout<<a[i]<<" ";
//                    ss.insert(a[i]);
//                }

                // printf("Case #%d: %d %lld %lld %lld\n",qqq,ss.size(),a[0]/a[1],a[0]%a[1],gcd(a[0],a[1]));

        if(q==0&&p==0){
            printf("Case #%d: %lld\n",qqq,1);
            continue;
        }

        ll ans=0;
        if(q==0||p==0||(q==p))
            ans=1;
        else{



            while(p){
                ans+=q/p;
                q=q%p;
                swap(q,p);
            }
            //  cout<<ans+1<<endl;
       //     printf("Case #%d: %lld\n",qqq,ans+1);
        }

printf("Case #%d: %lld\n",qqq,ans+1);

//        if(ans+1!=ss.size()){
//            cout<<ans<<" "<<ss.size()<<endl;
//            cout<<a[0]<<" "<<a[1]<<endl;
//        }
    }

    return 0;
}


