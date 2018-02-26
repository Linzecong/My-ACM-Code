#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<queue>  
#include<stack>  
#include<math.h>  
#include<vector>  
#include<map>  
#include<set>  
#include<stdlib.h>  
#include<cmath>  
#include<string>  
#include<algorithm>  
#include<iostream>  
#define exp 1e-10  
using namespace std;  
const int N = 101;  
const int inf = 2147483647;  
const int mod = 2009;  
int s[N][2*N];  
int main()  
{  
    int n,i,j,res;  
    s[1][1]=1;s[1][0]=1;  
    for(i=2;i<N;i++)  
    {  
        for(j=1;j<=s[i-1][0];j++)  
        {  
            s[i][j]+=s[i-1][j]*(4*i-2);  
            s[i][j+1]+=s[i][j]/10;  
            s[i][j]%=10;  
        }  
        while(s[i][j])  
        {  
            s[i][j+1]+=s[i][j]/10;  
            s[i][j]%=10;  
            j++;  
        }  
        for(s[i][0]=--j,res=0;j>0;j--)  
        {  
            res=res*10+s[i][j];  
            s[i][j]=res/(i+1);  
            res%=(i+1);  
        }  
        while(!s[i][s[i][0]])  
            s[i][0]--;  
    }  
    while(~scanf("%d",&n))  
    {  
        for(i=s[n][0];i>0;i--)  
            printf("%d",s[n][i]);  
        puts("");  
    }  
    return 0;  
}  