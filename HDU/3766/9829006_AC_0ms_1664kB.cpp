#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define N 20100
 
int main()
{
    int x, y, ans;
    char s[110];
    while(scanf("%s", s), strcmp(s, "END"))
    {
        sscanf(s, "%d", &x);
        scanf("%d", &y);
        x=abs(x);
        y=abs(y);
        if(x>y)swap(x, y);
 
        if(y==x*2)
        {
            printf("%d\n", (x+y)/3);
            continue;
        }
        if(y<=2*x)
        {
            if(x==1&&y==1)
                ans = 2;
            else if(x==2&&y==2)
                ans = 4;
            else
                ans = (x+y)/3+(x+y)%3;
        }
        else
        {
            ans=x;
            int c=(y-2*x)%4;
            ans+=c;
            ans+=(y-2*x-c)/2;
            if(y==1&&x==0)
                ans=3;
        }
        printf("%d\n",ans);
    }
    return 0;
}