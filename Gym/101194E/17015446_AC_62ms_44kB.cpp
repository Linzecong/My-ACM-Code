#include <bits/stdc++.h>
using namespace std;
const int MAX_N=210;
const long double EPS=1e-6;
struct node{
    long double val,x,y;
    bool operator <(const node &b)const{
        return val<b.val;
    }
}a[MAX_N];
char s;
long double x,y;
int t,n,cas=1;
int main(){
    for(scanf("%d",&t);t;t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin>>a[i].x>>s>>a[i].y;
            a[i].val=(a[i].x)/(a[i].x+a[i].y);
            //cout<<a[i].val<<endl;
        }
        sort(a,a+n);
        int cnt=0;
        long double tmp=0.0;
        for(int i=0;i<n;i++){
            if(tmp+a[i].val<1.0){
                tmp+=a[i].val,cnt++;
            }else{
                break;
            }
        }
        printf("Case #%d: %d\n",cas++,cnt);
    }
    return 0;
}
