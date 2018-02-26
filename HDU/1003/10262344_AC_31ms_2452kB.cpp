#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN=100005;
int dp[MAXN];//保存从0~i的最大和
int a[MAXN];
int N;


int main(){

    int t;
    scanf("%d",&t);

    for(int qqq=0;qqq<t;qqq++){

        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);

        dp[0]=a[0];//初始最大和为第一个数

        int start=0;//开始标记
        int end=0;//结束标记
        int maxsum=dp[0];//最大和
        int tempstart=0;//暂时的开始标记

        for(int i=1;i<N;i++){
            //如果前一个的最大和为正数，证明可以加上现在这个数
            if(dp[i-1]>=0){
                dp[i]=dp[i-1]+a[i];
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
