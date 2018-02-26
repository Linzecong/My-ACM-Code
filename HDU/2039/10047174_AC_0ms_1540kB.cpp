#include <stdio.h>  
int main()  
{  
    int m;  
    double a, b, c;  
    scanf("%d", &m);  
    while (m--)  
    {  
        scanf("%lf%lf%lf", &a, &b, &c);  
        if(a+b > c && a+c > b && b+c > a)  
            printf("YES\n");  
        else  
            printf("NO\n");  
    }  
    return 0;  
} 