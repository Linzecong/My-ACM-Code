#include<iostream>
#include<math.h>
#include<queue>
#include<memory.h>
#include<bitset>
using namespace std;
typedef long long int ll;

bitset<31> a[100005];

int main(){

    int T;
    scanf("%d",&T);

    while(T--){
        int n,temp;
        scanf("%d",&n);


        for(int i=1;i<=n;i++){
            scanf("%d",&temp);
            a[i]=bitset<31>(temp);
           // cout<<a[i]<<endl;
           // cout<<a[i][0]<<endl;
        }
        a[n+1]=bitset<31>(0);

        ll ans=0;
        for(int i=0;i<31;i++){

            bool flag=0;
            ll num=0;
            for(int j=1;j<=n+1;j++){

                if(flag==0){
                    if(a[j][i]==1){
                        flag=1;
                        num++;
                    }
                }
                else{
                    if(a[j][i]==1){
                        num++;
                    }
                    else{
                        ans+=((1ll<<i)*((num+1)*num/2));
                        num=0;
                        flag=0;
                    }
                }
            }

        }
        cout<<ans<<endl;





    }

    
    return 0;
}