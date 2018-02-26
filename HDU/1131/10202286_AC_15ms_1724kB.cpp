#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int katelan[102][102];

int main()
{
    katelan[0][1]=1;
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            katelan[i][j]+=katelan[i-1][j]*i*(4*i-2);
            katelan[i][j+1]+=katelan[i][j]/10000;
            katelan[i][j]%=10000;
        }

        int temp;
        for(int j=100; j>0; j--)
        {
            temp=katelan[i][j]%(i+1);
            katelan[i][j-1]+=temp*10000;
            katelan[i][j]/=(i+1);
        }

    }
    int n;
    while(scanf("%d",&n)&&n)
    {
        int i=100;
        while(katelan[n][i]==0) i--;
        printf("%d",katelan[n][i--]);
        while(i>0)
        {
            printf("%04d",katelan[n][i--]);
        }
        printf("\n");
    }

    return 0;
}