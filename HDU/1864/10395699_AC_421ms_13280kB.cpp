#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
using namespace std;  
  
int dp[3000050];//由于每张发票不超过1000，最多30张，扩大100倍数后开这么大即可  
  
int main()  
{  
    char ch;  
    double x,y;  
    int sum,a,b,c,money[35],v;  
    int t,i,j,k;  
    while(~scanf("%lf%d",&x,&t),t)  
    {  
        sum = (int)(x*100);//将小数化作整数处理  
        memset(money,0,sizeof(money));  
        memset(dp,0,sizeof(dp));  
        int l = 0;  
        for(i = 0; i<t; i++)  
        {  
            scanf("%d",&k);  
            a = b = c = 0;  
            int flag = 1;  
            while(k--)  
            {  
                scanf(" %c:%lf",&ch,&y);  
                v = (int)(y*100);  
                if(ch == 'A' && a+v<=60000)  
                    a+=v;  
                else if(ch == 'B' && b+v<=60000)  
                    b+=v;  
                else if(ch == 'C' && c+v<=60000)  
                    c+=v;  
                else  
                    flag = 0;  
            }  
            if(a+b+c<=100000 && a<=60000 && b<=60000 && c<=60000 && flag)//按题意所说，必须满足这些条件  
                money[l++] = a+b+c;  
        }  
        for(i = 0; i<=l; i++)  
        {  
            for(j = sum; j>=money[i]; j--)  
                    dp[j] = max(dp[j],dp[j-money[i]]+money[i]);  
        }  
        printf("%.2lf\n",dp[sum]/100.0);  
    }  
  
    return 0;  
}