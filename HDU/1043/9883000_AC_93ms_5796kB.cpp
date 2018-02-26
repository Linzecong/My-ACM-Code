#include<stdio.h>  
#include<iostream>  
#include<queue>  
using namespace std;  
typedef struct nn  
{  
    char way;//记录路径  
    int fath;//记录父节点  
}node1;  
typedef struct nod  
{  
    int aa[10];  
    int n,son;//n为9在aa中的位置  
}node2;  
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},fac[10];  
node1 Node[370000];//节点  
void set_fac()//计算0到8的阶层  
{  
    fac[0]=1;  
    for(int i=1;i<=8;i++)  
    fac[i]=fac[i-1]*i;//printf("%d",fac[8]);  
}  
int cantor(int aa[])//康托展开  
{  
    int i,j,ans=0,k;  
    for(i=0;i<9;i++)  
    {  
        k=0;  
        for(j=i+1;j<9;j++)  
        if(aa[i]>aa[j])  
        k++;  
        ans+=k*fac[8-i];  
    }  
    return ans;  
}  
void bfs(int a[])  
{  
    queue<node2>Q;  
    node2 q,p;  
    int e,tx,ty,tem,t=0;  
    for(e=0;e<9;e++) q.aa[e]=a[e];  
    q.n=8;q.son=0;  
    Node[q.son].fath=0;//把最终父节点记为0，也就是本身  
    Q.push(q);  
    while(!Q.empty())  
    {  
        q=Q.front(); Q.pop();  
        for(e=0;e<4;e++)  
        {  
            p=q;  
            tx=q.n%3+dir[e][0];ty=q.n/3+dir[e][1];  
            if(tx>=0&&ty>=0&&tx<3&&ty<3)  
            {  
                p.n=ty*3+tx;  
                tem=p.aa[p.n];p.aa[p.n]=p.aa[q.n];p.aa[q.n]=tem;  
                p.son=cantor(p.aa);  
                if(Node[p.son].fath==-1)//为－1时表示这个点没有访问过，那么放入队列  
                {  
                    Node[p.son].fath=q.son;//当前节点的父节点就是上一个节点  
                    if(e==0)Node[p.son].way='l';//一定要注意了，e=0是向右走，但我们是要往回搜，所以为了在输出时不用再进行转换，直接记录相反的方向  
                    if(e==1)Node[p.son].way='r';  
                    if(e==2)Node[p.son].way='u';  
                    if(e==3)Node[p.son].way='d';  
                    Q.push(p);  
                }  
            }  
        }  
    }  
}  
int main()  
{  
    int i,j,s,ss[10],a[10];  
    char ch[50] ;  
    for(i=0;i<9;i++)//目标  
        a[i]=i+1;  
    for(i=0;i<370000;i++)  
    Node[i].fath=-1;  
    set_fac();//计算阶层  
        bfs(a);//开始从目标建立一树  
  
    while(gets(ch)>0)  
    {  
        for(i=0,j=0;ch[i]!='\0';i++)//把字符串变成数子  
        {  
             if(ch[i]=='x')  
            ss[j++]=9;  //把x变为数子9  
            else if(ch[i]>='0'&&ch[i]<='8')  
            ss[j++]=ch[i]-'0';  
        }  
        s=cantor(ss);//算出初态康托值  
       if(Node[s].fath==-1) {printf("unsolvable\n");continue;}//不能变成目标  
         
        while(s!=0)  
        {  
            printf("%c",Node[s].way);  
            s=Node[s].fath;  
        }  
        printf("\n");  
    }  
}  