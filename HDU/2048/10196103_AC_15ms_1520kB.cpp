#include <stdio.h>  
#include <string.h>  
int main()  
{  
    int  c, n, j;  
    double sum, i, a[21];  
    a[1] = 0;  
    a[2] = 1;  
    for(j = 3; j < 21; j++)  
        a[j] = (j - 1) * (a[j-1] + a[j-2]);  
    scanf("%d", &c);  
    while (c--)  
    {  
        sum = 1;  
        scanf("%d", &n);  
        for(i = 1; i <= n; i++)  
            sum *= i;  
        printf("%.2lf%%\n", a[n]/sum*100);  
    }  
    return 0;  
}  