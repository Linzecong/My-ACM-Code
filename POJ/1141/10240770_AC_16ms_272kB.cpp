#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
using namespace std;  
const int maxn = 110;  
  
char str[maxn];  
int dp[maxn][maxn], path[maxn][maxn], len;  
  
void output(int st, int ed);  
  
int main()  
{  
      
    memset(dp, 0, sizeof(dp));  
    scanf("%s", str + 1);  
    len = strlen(str + 1);  
    for(int i = 1; i <= len; i++)  
        dp[i][i] = 1;  
    for(int l = 2; l <= len; l++)  
    {  
        for(int i = 1; i <= len - l + 1; i++)  
        {  
            int j = i + l - 1;  
            if(str[i] == '(' && str[j] == ')' || str[i] == '[' && str[j] == ']')  
            {  
                dp[i][j] = dp[i+1][j-1];  
                path[i][j] = -1;  
            }  
            else  
                dp[i][j] = 0x7fffffff;  
            for(int k = i; k <= j - 1; k++)  
            {  
                if(dp[i][j] > dp[i][k] + dp[k+1][j])  
                {  
                    dp[i][j] = dp[i][k] + dp[k+1][j];  
                    path[i][j] = k;  
                }  
            }  
        }  
    }  
    output(1, len);  
    printf("\n");  
      
    return 0;  
}  
  
void output(int st, int ed)  
{  
    if(st > ed)  
        return;  
    else if(st == ed)  
    {  
        if(str[st] == '(' || str[ed] == ')')  
            printf("()");  
        else  
            printf("[]");  
    }  
    else if(path[st][ed] == -1)  
    {  
        printf("%c", str[st]);  
        output(st+1, ed - 1);  
        printf("%c", str[ed]);  
    }  
    else  
    {  
        output(st, path[st][ed]);  
        output(path[st][ed] + 1, ed);  
    }  
}  