#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long int ll;
ll a[200005];
ll sum[200005];
int n;

int main(){
    scanf("%d",&n);
    map<ll,int> m;

    m[0]=1;
    int min1;
    int min2=2000000;

    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];

        if(m[sum[i]]){
        	if(i-m[sum[i]]<min2){
        		min2=i-m[sum[i]]+1;
            	min1=m[sum[i]];
        	}
        }
        m[sum[i]]=i+1;
    }

    if(min2==2000000)
        printf("%d\n",-1);
    else
        printf("%d %d\n",min1,min2);
    

    return 0;
}