#include <bits/stdc++.h>
using namespace std;

long long nums[100001];

int main(){
    int t,n,k,ans;
    long long temp,sum;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        sum=0;
        ans=0;
        scanf("%d%d",&n,&k);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&nums[j]);
            sum+=nums[j];
        }
        temp=sum/k;
        if(temp*k==sum)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j]==temp)continue;
                else if(nums[j]>temp)
                {
                    nums[j]-=temp;
                    j--;
                    ans++;
                }
                else
                {
                    nums[j+1]+=nums[j];
                    ans++;
                }
            }
            printf("Case #%d: %d\n",i,ans);
        }
        else
            printf("Case #%d: -1\n",i);
    }
    return 0;
}
