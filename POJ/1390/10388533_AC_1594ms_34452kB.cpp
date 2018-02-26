#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
const int maxn=200+5;  
int p[maxn],color[maxn],len[maxn];  
int f[maxn][maxn][maxn];  
using namespace std;  
int dp(int i,int j,int ex_len)  
{  
    if(f[i][j][ex_len]!=-1) return f[i][j][ex_len];  
    int result=(len[j]+ex_len)*(len[j]+ex_len);  
    if(i==j) return result;  
    result=result+dp(i,j-1,0);  
    for(int k=i;k<=j-1;k++)  
    {  
        if(color[k]!=color[j]) continue;  
        int r=dp(i,k,len[j]+ex_len)+dp(k+1,j-1,0);  
        result=max(result,r);  
    }  
    f[i][j][ex_len]=result;  
    return result;  
}  
int main()  
{  
    int n,t,cnt=1,kase=0;  
    scanf("%d",&t);  
    while(t--)  
    {  
        cnt=1;  
        scanf("%d",&n);  
        memset(f,-1,sizeof(f));  
        memset(len,0,sizeof(len));  
        memset(len,0,sizeof(len));  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d",&p[i]);  
            if(i>1&&p[i]!=p[i-1]) cnt++;  
            color[cnt]=p[i];  
            len[cnt]++;  
        }  
        printf("Case %d: %d\n",++kase,dp(1,cnt,0));  
    }  
    return 0;  
}  