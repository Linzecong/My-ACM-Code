#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN=100005;
int dp[MAXN];
int a[MAXN];
int N;


int main(){

    int t;
    scanf("%d",&t);

    for(int qqq=0;qqq<t;qqq++){

        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);

        dp[0]=a[0];

        int start=0;
        int end=0;
        int maxsum=dp[0];
        int tempstart=0;

        for(int i=1;i<N;i++){
            if(dp[i-1]>=0){
                dp[i]=max(dp[i-1]+a[i],a[i]);
            }
            else{
                dp[i]=a[i];
                tempstart=i;
            }

            if(dp[i]>maxsum){
                maxsum=dp[i];
                start=tempstart;
                end=i;
            }

        }

        if(qqq!=t-1)
            printf("Case %d:\n%d %d %d\n\n",qqq+1,maxsum,start+1,end+1);
        else
            printf("Case %d:\n%d %d %d\n",qqq+1,maxsum,start+1,end+1);
    }


    return 0;
}
