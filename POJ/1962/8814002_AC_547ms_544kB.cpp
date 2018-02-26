#include<cstdio>
#include<cstring>
#include<cmath>
const int qq=20000+5;
int pre[qq],dis[qq];
int ans;
void init(int n)
{
    for(int i = 0; i <= n; ++i){     //初始化、
        pre[i]=i;
        dis[i]=0;
    }
}
int find(int x)             //只想说递归的调用真的很神奇，然而我还是个半桶水
{
    if(x==pre[x])   return x;
    int flag=find(pre[x]);      // 在find函数中直接进行路径压缩
    dis[x]=dis[x]+dis[pre[x]];  // 一边压缩一遍更新子节点到根节点的距离值
    return pre[x]=flag;         //这里是压缩路径、
}
int main()
{
    int t,n;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        char s[10];
        while(scanf("%s",s) && (s[0]!='O')){
            if(s[0] == 'E'){
                int a;
                scanf("%d",&a);
                find(a);        //对于要找的那个a，在此之前去压缩路径并更新到根节点的距离值
                printf("%d\n",dis[a]);
            }
            else if(s[0] == 'I'){
                int a,b;
                scanf("%d%d",&a,&b);
                pre[a]=b;           // 合并
                int ans=a-b>0?a-b:b-a;
                ans%=1000;      //求距离、
                dis[a]=ans;     //然后赋值
            }
        }
    }
    return 0;
}