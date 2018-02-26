#include<stdio.h>  
#include<string.h>  
  
int l[100010],r[100010];  
__int64 h[100010];  
int main()  
{  
    int N;  
    while(~scanf("%d",&N) && N!=0)  
    {  
        memset(h,0,sizeof(h));  
        for(int i = 1; i <= N; i++)  
        {  
            scanf("%I64d",&h[i]);  
            l[i] = r[i] = i;  
        }  
  
        l[0] = 1;  
        r[N+1] = N;  
        h[0] = -1;  
        h[N+1] = -1;  
        //这上边不加就会超时，不加的话下边就可能一直while，跳不出循环  
        for(int i = 1; i <= N; i++)  
        {  
            while(h[l[i]-1] >= h[i])//找位置i的左边界  
                l[i] = l[l[i]-1];  
        }  
        for(int i = N; i >= 1; i--)  
        {  
            while(h[r[i]+1] >= h[i])//找位置i的右边界  
                r[i] = r[r[i]+1];  
        }  
        __int64 MaxArea = -0xffffff0;  
        for(int i = 1; i <= N; i++)  
        {  
            if(h[i]*(r[i]-l[i]+1) > MaxArea)  
                MaxArea = h[i]*(r[i]-l[i]+1);  
        }  
        printf("%I64d\n",MaxArea);  
    }  
    return 0;  
}  