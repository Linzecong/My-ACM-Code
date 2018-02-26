#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
int per[2200000];  
int vis[2200000];  
int n, m, id;  
char str[5];  
  
int find(int x){  
    if(x == per[x])  
        return x;  
    else return per[x] = find(per[x]);  
}  
  
void jion(int x, int y){  
    int fx = find(x);  
    int fy = find(y);  
    if(fx != fy)  
        per[fy] = fx;  
}  
  
void del (int x){  
    per[x] = id ++;  
}  
  
int main (){  
    int a,b,c;  
    int k = 1;  
    while(scanf("%d%d", &n, &m), n || m){  
        id = n + n;   
        for(int i = 0; i < n; ++i)  
            per[i] = i + n;//虚拟父节点   
        for(int i = n; i <= n + n + m; ++i)//n+n+m: 最多可能删除m个节点  
            per[i] = i;  
              
            while(m--){   
            scanf("%s", &str);  
            if(str[0] == 'M'){  
                scanf("%d%d", &a, &b);  
                 jion(a,b);  
            }  
            else{  
                scanf("%d", &c);  
                del(c);  
            }  
        }   
        int ans = 0;  
        memset(vis, 0 ,sizeof(vis));  
        for(int i = 0; i < n; ++i){  
            int x = find(i);  
            if(!vis[x]){  
                ans++;  
                vis[x] = 1;  
            }   
        }  
        printf("Case #%d: %d\n", k++, ans);  
    }  
    return 0;  
}  