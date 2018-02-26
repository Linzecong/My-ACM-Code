#include <stdio.h>  
  
int main()  
{  
    int t;  
    double x, y;  
    scanf("%d", &t);  
    for(int i = 1; i <= t; ++i){  
        scanf("%lf%lf", &x, &y);  
        printf("Property %d: This property will begin eroding in year %d.\n",  
            i, int((x*x + y*y) * 3.1415926 / 100 + 1));  
    }  
    printf("END OF OUTPUT.\n");  
    return 0;  
}  