/*
给你一个串让你求，所有相交的回文子串对的个数
我们可以利用回文树求出以s[i]为结尾的回文子串个数Ai，和以s[i]为开始的的回文串个数Bi
那么不相交的回文子串对就是Ai*sum{Bi+1,Bi+2,Bi+3....Bi+n}  {i=1..n-1};
然后用总的回文串对数减去不相交的就是答案。
我们知道利用回文树可以求出以i为结尾的回文串个数，那么以i为开始的，只需要将字符串倒着插入就好了。
另外，这道题目的字符串的长度有2百万，回文树中的next[][]数组，将会内存超限，所以只能用邻接表代替矩阵了
为了对回文树更好的学习，在求所有回文子串和的时候我们可以用两种方式，具体看代码
*/


#include <iostream>  
#include <string.h>  
#include <stdlib.h>  
#include <algorithm>  
#include <math.h>  
#include <stdio.h>  
  
using namespace std;  
typedef long long int LL;  
const int MAX=2*1e6;  
const int mod=51123987;  
int n;  
char str[MAX+5];  
int sum[MAX+5];  
struct link //next的邻接表  
{  
    int u[MAX+5];int v[MAX+5];  
    int next[MAX+5];int head[MAX+5];  
    int tot;  
    void clear()  
    {  
        memset(head,-1,sizeof(head));  
        tot=0;  
    }  
    void clear(int x){head[x]=-1;}  
    int get(int x,int y)  
    {  
        for(int i=head[x];i!=-1;i=next[i])  
        {  
            if(u[i]==y)  
                return v[i];  
        }  
        return 0;  
    }  
    void insert(int x,int y,int z)  
    {  
        u[tot]=y;  v[tot]=z;  
        next[tot]=head[x];  
        head[x]=tot++;  
    }  
  
};  
struct Tree  
{  
    //int next[MAX+5][26];  
    int fail[MAX+5];//指向当前节点回文串中最长的后缀回文子串  
    int cnt[MAX+5];//当前节点的回文串一共有多少个  
    int num[MAX+5];//当前节点为结尾的回文子串的个数  
    int len[MAX+5];//当前节点的回文串的长度  
    int s[MAX+5];//字符串  
    int last;//回文树最后一个节点  
    int n;  
    int p;//回文树当前有多少个节点  
    link next;//邻接表，表示当前节点回文串在两端添加一个字符形成的另一个节点的回文串  
    int new_node(int x)  
    {  
        //memset(next[p],0,sizeof(next[p]));  
        cnt[p]=0;  
        next.clear(p);  
        num[p]=0;  
        len[p]=x;  
        return p++;  
    }  
  
    void init()  
    {  
        next.clear();  
        p=0;  
    new_node(0);  
        new_node(-1);  
        last=0;  
        n=0;  
        s[0]=-1;  
        fail[0]=1;  
    }  
  
    int get_fail(int x)  
    {  
        while(s[n-len[x]-1]!=s[n])  
            x=fail[x];  
        return x;  
    }  
  
    int add(int x)  
    {  
        x-='a';  
        s[++n]=x;  
        int cur=get_fail(last);  
        if(!(last=next.get(cur,x)))  
        {  
            int now=new_node(len[cur]+2);  
        fail[now]=next.get(get_fail(fail[cur]),x);  
            next.insert(cur,x,now);  
            num[now]=num[fail[now]]+1;  
        last=now;  
        }  
        cnt[last]++;  
        return num[last];  
    }  
    LL Allsum()//求出所有回文子串的数目  
    {  
        LL ret=0;  
  
        for(int i=p-1;i>0;i--)  
        {  
        cnt[fail[i]]=(cnt[fail[i]]+cnt[i])%mod;  
  
            ret=(ret+cnt[i])%mod;  
        }  
        return ret;  
    }  
}tree;  
int main()  
{  
    scanf("%d",&n);  
    scanf("%s",str);  
    tree.init();  
    sum[n]=0;  
    for(int i=n-1;i>=0;i--)  
        sum[i]=(sum[i+1]+tree.add(str[i]))%mod;  
    tree.init();  
    LL ans=0;LL res=0;LL res2=0;  
    for(int i=0;i<=n-1;i++)  
    {  
        ans=(ans+(LL)tree.add(str[i])*sum[i+1])%mod;  
        res2+=tree.num[tree.last];//同样也可以求所有回文子串的数目  
    }  
    res=tree.Allsum();  
    //cout<<res<<" "<<res2<<endl;两个是相等的  
    ans=(((LL)res*(res-1)/2%mod-ans)%mod+mod)%mod;  
    printf("%lld\n",ans);  
    return 0;  
}  