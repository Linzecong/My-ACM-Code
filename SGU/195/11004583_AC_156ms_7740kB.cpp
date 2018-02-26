#include<stdio.h>  
#include<string.h>  
#include<iostream>  
using namespace std;  
const int maxn=500000+10;  
int tr[maxn],p[maxn];  
int vis[maxn];  
int main()  
{  
    int n,i,t;  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(tr,0,sizeof(tr));  
        memset(vis,0,sizeof(vis));  
        memset(p,0,sizeof(p));  
        for(i=2;i<=n;i++)  
            scanf("%d",&tr[i]);  
        t=0;  
        for(i=n;i>1;i--)  
            if(!vis[tr[i]]&&!vis[i])//如果本身和上级没有接触过奖金则可以或的奖金  
            {  
                vis[i]=1;  
                vis[tr[i]]=1;//此时上司就不能获得奖金了  
                p[t++]=i;  
            }  
        printf("%d\n",1000*t);  
        for(i=t-1;i>=0;i--)  
        {  printf("%d",p[i]);  
            if(i!=0)  
                printf(" ");  
            else  
                printf("\n");  
        }  
    }  
    return 0;  
}  