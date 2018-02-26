#include <iostream>
using namespace std;

const int maxn=200050;

int pre[maxn];
int sum[maxn];

int find(int x){
    if(x!=pre[x]){
        int tmp=pre[x];
        pre[x]=find(pre[x]);
        sum[x]+=sum[tmp];
    }
    return pre[x];
}

int main(){

    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<=n;i++){
            pre[i]=i;
            sum[i]=0;
        }
        int l,r,s;
        int ans=0;
        for(int i=0;i<k;i++){
            scanf("%d%d%d",&l,&r,&s);
            l--;
            int lr=find(l);
            int rr=find(r);
            if(lr==rr){
                if(sum[r]-sum[l]!=s)
                    ans++;
            }
            else{
                pre[rr]=lr;
                sum[rr]=sum[l]-sum[r]+s;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
