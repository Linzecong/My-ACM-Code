#include<stdio.h>  
#include<string.h>  
int num[333333];  
int set[333333];  
int under[333333];  
int find(int x)  
{  
    int tmp;  
    if (x!=set[x])  
    {  
        tmp = find(set[x]);  
        under[x] += under[set[x]];  
        set[x] = tmp;  
    }  
    return set[x];  
  
}  
void merge(int a,int b)  
{  
    int fx=find(a);  
    int fy=find(b);  
    if(fx!=fy)  
    {  
        under[fx]=num[fy];  
        num[fy]+=num[fx];  
        set[fx]=fy;  
    }  
}  
int main()  
{  
    int n,a,b;  
    char s[5];  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(under,0,sizeof(under));  
        for(int i=0; i<=n; i++)//初始化  
        {  
            set[i]=i;  
            num[i]=1;  
        }  
        for(int i=0; i<n; i++)  
        {  
            scanf("%s",s);  
            if(s[0]=='M')  
            {  
                scanf("%d%d",&a,&b);  
                merge(a,b);  
            }  
            else  
            {  
                scanf("%d",&a);  
                find(a);  
                printf("%d\n",under[a]);  
            }  
        }  
    }  
    return 0;  
}