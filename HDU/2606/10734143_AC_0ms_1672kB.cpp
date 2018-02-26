#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define mod 19890907  
int f[105];  
void init()  
{  
    f[0]=1;  f[1] = 1, f[2] = 5, f[3] = f[2] + f[1]*4+2*f[0]+2;  
    for(int i = 4; i <= 100; i++)  
    {  
        f[i] = (f[i] + f[i-1]) % mod;  
        f[i] = (f[i] + f[i-2]*4) % mod;  
        f[i] = (f[i] + f[i-3]*2) % mod;  
        f[i] = (f[i] + f[i-4]) % mod;  
        for(int k=3; k<=i; k++)  
            f[i]=(f[i]+2*f[i-k])%mod;  
    }  
}  
int main()  
{  
    int T,n;  
    init();  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        printf("%d\n",f[n]);  
    }  
    return 0;  
}  