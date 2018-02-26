#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
//const int INF=0x3f3f3f3f;  
const int N=1000+10;  
int a[N][400];  
int main()  
{  
    memset(a,0,sizeof(a));  
    int n,i,j;  
    a[1][0]=0,a[2][0]=1;  
    int c=0;  
    for(i=3;i<=1000;i++)  
    {  
        c=0;  
        for(j=0;j<=400;j++)//核心--大数；  
        {  
            a[i][j]=a[i-1][j]+2*a[i-2][j]+c;  
            c=a[i][j]/10;  
            a[i][j]%=10;  
        }  
    }  
    while(~scanf("%d",&n))  
    {  
        if(n==1)  
            printf("0\n");  
        else  
        {  
            for(j=399;j>=0;j--)  
                if(a[n][j])  
                break;  
            for(i=j;i>=0;i--)  
                printf("%d",a[n][i]);  
            printf("\n");  
        }  
    }  
    return 0;  
}  