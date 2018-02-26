#include<stdio.h>
#include<string.h>
#include<math.h>

int pre[10005];
int num[10005];
int tran[10005];

void init(int n)
{
    for(int i = 0; i <= n; ++i){     //初始化
        pre[i]=i;
        num[i]=1;
        tran[i]=0;
    }
}

int find(int x)             //只想说递归的调用真的很神奇，然而我还是个半桶水
{
    if(x==pre[x])
        return x;
    int flag=find(pre[x]);      // 在find函数中直接进行路径压缩

    tran[x]+=tran[pre[x]];       // 一边压缩一遍更新子节点到根节点的距离值

    return pre[x]=flag;         //这里是压缩路径、
}

void merge(int x,int y){
    int rx=find(x);
    int ry=find(y);
    if(rx!=ry){

        pre[rx]=ry;

        num[ry]+=num[rx];

        tran[rx]++;

    }
}


int main()
{
    int qqq,n,m;
    scanf("%d",&qqq);
    for(int t=0;t<qqq;t++)
    {
        scanf("%d%d",&n,&m);

        printf("Case %d:\n",t+1);

        init(n);

        char s[10];
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            if(s[0] == 'Q'){
                int a;
                scanf("%d",&a);

                find(a);
                printf("%d %d %d\n",find(a),num[find(a)],tran[a]);

            }
            else if(s[0] == 'T'){
                int a,b;
                scanf("%d%d",&a,&b);

                merge(a,b);

            }
        }
    }
    return 0;
}



