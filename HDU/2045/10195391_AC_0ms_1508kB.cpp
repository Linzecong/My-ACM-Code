#include <stdio.h>
int main()
{
    int i;
    __int64 a[51];
    a[1]=3;
    a[2]=6;
    a[3]=6;
    for(i=4;i<51;i++)
    {
        a[i]=a[i-1]+a[i-2]*2;      //数据范围大用longlong 
    }
    while(scanf("%d",&i)!=EOF)
    printf("%I64d\n",a[i]);
    return 0;

}