#include<cstdio>
#include<cmath>
bool ok(int x)
{
    int m=(int)sqrt(x+0.5);
    for(int i=2;i<=m;i++)
    {
        if(x%i==0)return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(ok(x))printf("Yes\n");else printf("No\n");
    }
    return 0;
}