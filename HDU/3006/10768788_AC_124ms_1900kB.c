#include "stdio.h"  
#include "string.h"  
  
int set[1<<14];  
  
void main(){  
    int n, m;  
    int z, i, j, k, w, sum;  
  
    while(scanf("%d %d", &n, &m)!=EOF){  
        memset(set, 0, sizeof(set));  
        for(i=0; i<n; i++){  
            scanf("%d", &k);  
            w = 0;  
            for(j=0; j<k; j++){  
                scanf("%d", &z);  
                w += 1<<(z-1);  
            }  
            set[w] = 1;  //w状态的集合，标记为1，表示已经有了  
  
            for(j=1; j<1<<14; j++){  
                if(set[j]) //若j状态的集合有了，那么将新来的w集合与j集合合并，就可以产生w|j集合。  
                    set[w|j] = 1;  
            }  
        }  
          
        sum = 0;  
        for(j=1; j<1<<14; j++){  
            if(set[j])  //最后计算所有j状态的集合的总数  
                sum++;  
        }  
  
        printf("%d\n", sum);  
    }  
      
}  