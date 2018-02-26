#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN=105;
int dp[MAXN];//保存从0~i的最大和
int a[MAXN][MAXN];
int N;

int temp[MAXN];

int getZDLXZDH(){
    dp[0]=temp[0];
    int maxsum=dp[0];
    for(int i=1;i<N;i++){
        if(dp[i-1]>=0)
            dp[i]=dp[i-1]+temp[i];
        else
            dp[i]=temp[i];

        if(dp[i]>maxsum)
            maxsum=dp[i];

    }
    return maxsum;
}


int main(){


    while(~scanf("%d",&N)){


        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&a[i][j]);

        int ans=-99999999;
        for(int i=0;i<N;i++)//从第i行开始
        {
            memset(temp,0,sizeof(temp));
            for(int j=i;j<N;j++)//从 i行到 n-1行都尝试一次
            {
                for(int k=0;k<N;k++)//把 j至 k行的每一列都加起来，就是矩阵压缩
                    temp[k]+=a[j][k];
                int pre=getZDLXZDH();//计算压缩矩阵形成的一维数组的最长连续序列
                if(ans<pre)//更新最大值
                    ans=pre;
            }
        }
        printf("%d\n",ans);

    }


    return 0;
}
