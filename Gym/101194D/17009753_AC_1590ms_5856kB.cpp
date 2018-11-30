#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=3e5+10;
ll a[MAX_N];
int k,n,t;
bool ok(int num){
    int kk=k-1;
    vector<int> tmp,res;
    tmp.clear();
    for(int i=0;i<num;i++){
        tmp.emplace_back(i);
    }
    while(kk){
        res.clear();
        for(int i=0;i<num;i++){
            int ind=(lower_bound(a+tmp[num-1]+1,a+n,a[tmp[i]]*2)-a);
            if(i&&ind<=res.back()){
                ind=res.back()+1;
            }
            if(ind==n){
                return false;
            }
            res.emplace_back(ind);
        }
        kk--;
        tmp=res;
    }
    return true;
}
int main(){
    int cas=1;
    for(scanf("%d",&t);t;t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%lld",a+i);
        }
        sort(a,a+n);
        int l=1,r=n/k;
        while(l<=r){
            int mid=(l+r)/2;
            if(ok(mid)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        printf("Case #%d: %d\n",cas++,r);
    }

    return 0;
}
