#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <algorithm>  
  
#define LL long long  
#define INF 0x3f3f3f3f  
using namespace std;  
int n,k,m;  
struct Node{  
    int fa;  
    LL v;  
}father[100005];  
  
void init(int n)  
{  
    for(int i=0;i<=n;i++)  
    {father[i].fa=i;father[i].v=1e18;}  
}  
  
int Find(int x)  
{  
    int r=x;  
    while(father[x].fa!=x)x=father[x].fa;  
    father[r].fa=x;  
    return x;  
}  
  
void Merge(int x,int y)  
{  
    if(x!=y)  
        father[x].fa=y;  
}  
  
int main()  
{  
    while(~scanf("%d %d %d",&n,&k,&m))  
    {  
        init(n);  
        for(int i=1;i<=k;i++)  
        {  
            int r,c;  
            scanf("%d %d",&r,&c);  
            father[c].v=min(father[c].v,(LL)r);  
        }  
        char str[2];  
        for(int i=1;i<=m;i++)  
        {  
            int x,y;  
            scanf("%s",str);  
            if(strcmp(str,"AP")==0)  
            {  
                scanf("%d %d",&x,&y);  
                if(father[y].fa!=y)printf("Reject\n");  
                else  
                {father[y].v=min(father[y].v,(LL)x);puts("Accept");}  
            }  
            else if(strcmp(str,"MG")==0)  
            {  
                scanf("%d %d",&x,&y);  
                if(x==y)puts("Reject");  
                else if(father[x].fa!=x||father[y].fa!=y)puts("Reject");  
                else {father[x].v=min(father[y].v,father[x].v);  
                    Merge(y,x);puts("Accept");}  
            }  
            else if(strcmp(str,"GT")==0)  
            {  
                scanf("%d",&x);  
                if(father[x].fa!=x){  
                    int fx=Find(x);  
                    printf("Company %d is a part of company %d.\n",x,fx);  
                }  
                else if(father[x].v==1e18)printf("Company %d is empty.\n",x);  
                else printf("Lowest rate: %lld.\n",father[x].v);  
            }  
        }  
        puts("");  
    }  
    return 0;  
}  