#include<stdio.h>  
int a[5001];  
int ans1,ans2;  
int sum[5001],len[5001];  
int mark[5001];  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        int i,j;  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",a+i);  
            mark[i]=1;  
        }  
        ans1=ans2=0;  
        for(i=1;i<=n;i++)  
        {  
            len[i]=1;  
            sum[i]=1;  
            for(j=i-1;j>=1;j--)  
            {  
                if(a[i]<a[j]&&mark[j]==1)  
                {  
                    if(len[i]==len[j]+1)  
                        sum[i]+=sum[j];  
                    else if(len[i]<len[j]+1)  
                    {  
                        len[i]=len[j]+1;  
                        sum[i]=sum[j];  
                    }  
                }  
                else if(a[i]==a[j])  
                {  
                    if(len[i]==1)  
                        mark[i]=0;  
                    break;  
                }  
            }  
            if(ans1<len[i])  
                ans1=len[i];  
        }  
        for(i=1;i<=n;i++)  
        if(ans1==len[i])  
        ans2+=sum[i];  
        printf("%d %d\n",ans1,ans2);  
    }  
    return 0;  
}  