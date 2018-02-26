#include <stdio.h>  
  
double cal(int n, int m) {  
    double i, t1=1, t2=1, t3=1;  
      
    for(i=1; i<=n; i++)  
        t1 *= i;  
    for(i=1; i<=m; i++)  
        t2 *= i;  
    for(i=1; i<=n-m; i++)  
        t3 *= i;  
    return t1 / t2 / t3;  
      
}  
  
int main() {  
      
    int n, i, a, b;  
    __int64 d[21] = {0, 0, 1, 2}, e;  
      
    for(i=4; i<21; i++)  
        d[i] = (i-1) * (d[i-1] + d[i-2]);  
      
    while(~scanf("%d", &n)) {  
          
        for(i=0; i<n; i++) {  
            scanf("%d%d", &a, &b);  
            e = cal(a, b);  
            printf("%I64d\n", e * d[b]);  
        }  
          
    }  
      
    return 0;  
}  