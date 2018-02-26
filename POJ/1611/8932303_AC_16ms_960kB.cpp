#include<iostream>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
#define N 30010  
int pre[N], son[N];  
  
int find(int x)  
{  
    return x == pre[x] ? x : find(pre[x]);  
}  
  
void join(int x, int y)  
{  
    int root1, root2;  
    root1 = find(x);  
    root2 = find(y);  
    if(root1 != root2)  
    {  
            pre[root2] = root1;  
            son[root1] += son[root2];  
    }  
}  
  
int main()  
{  
    int n, m, num;  
    while(scanf("%d%d", &n, &m) && n + m)  
    {  
        for(int i = 0; i < n; ++i)  
        {  
            pre[i] = i;  
            son[i] = 1;  
        }  
        for(int i = 1; i <= m; ++i)  
        {  
            scanf("%d", &num);  
            int *stu = new int[num]; //YY出来的~~~  
            for(int j = 0; j < num; ++j)  
            {  
                scanf("%d", &stu[j]);  
                if(j != 0)  
                    join(stu[j - 1], stu[j]);  
            }  
            delete(stu);  
        }  
        printf("%d\n", son[find(0)]);  
    }  
    return 0;  
} 