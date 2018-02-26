#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int numda,numxiao;
int tempP,tempL;
bool usedda[1001],usedxiao[1001];
long long ans=0;

struct node
{
    int pos;
    int let;
}da[1001],xiao[1001];

bool cmp(node a,node b)
{
    if(a.pos!=b.pos)return a.pos>b.pos;
    else return a.let>b.let;
}

int main()
{
    cin>>n>>k;
    numda=0;
    numxiao=0;
    memset(usedda,0,sizeof(usedda));
    memset(usedxiao,0,sizeof(usedxiao));
    for(int i=0;i<n;i++)
    {
        cin>>tempP>>tempL;
        if(tempL>k)
        {
            long long temp=tempL/k;
            ans+=temp*abs(tempP)*2;
            tempL-=temp*k;
        }
        if(tempL>0)
        {
            if(tempP>=0)
            {
                da[numda].pos=tempP;
                da[numda].let=tempL;
                numda++;
            }
            else
            {
                xiao[numxiao].pos=-tempP;
                xiao[numxiao].let=tempL;
                numxiao++;
            }
        }
    }
    sort(da,da+numda,cmp);
    sort(xiao,xiao+numxiao,cmp);
    int cnt=0,cur;
    bool flag;
    while(cnt<numda)
    {
        cur=k;
        flag=true;
        for(int i=cnt;i<numda;i++)
        {
            if(cur==0)break;
            if(!usedda[i])
            {
                if(cur>=da[i].let)
                {
                    cur-=da[i].let;
                    usedda[i]=true;
                    cnt++;
                }
                else
                {
                    da[i].let-=cur;
                    cur=0;
                }
                if(flag)
                {
                    ans+=2*da[i].pos;
                    flag=false;
                }
            }
        }
    }
    cnt=0;
    while(cnt<numxiao)
    {
        cur=k;
        flag=true;
        for(int i=cnt;i<numxiao;i++)
        {
            if(cur==0)break;
            if(!usedxiao[i])
            {
                if(cur>=xiao[i].let)
                {
                    cur-=xiao[i].let;
                    usedxiao[i]=true;
                    cnt++;
                }
                else
                {
                    xiao[i].let-=cur;
                    cur=0;
                }
                if(flag)
                {
                    ans+=2*xiao[i].pos;
                    flag=false;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
