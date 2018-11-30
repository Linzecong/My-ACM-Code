#include <bits/stdc++.h>
#define EPS 1e-9
#define double long double
using namespace std;
const int MAX_N=210;
struct node{
    double val,right;
    bool operator <(const node &b)const{
        return val>b.val;
    }
}a[MAX_N];
char s;
double x,y;
int t,n,cas=1;
int main(){
    for(scanf("%d",&t);t;t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin>>x>>s>>y;
            a[i].val=y/x;
            a[i].right=1/(a[i].val+1);
        }
        sort(a,a+n);
        int cnt=0;
        double tmp=0.0;
        for(int i=0;i<n;i++){
            if(tmp+a[i].right<1.0){
                tmp+=a[i].right,cnt++;
            }else{
                break;
            }
        }
        printf("Case #%d: %d\n",cas++,cnt);
    }
    return 0;
}
