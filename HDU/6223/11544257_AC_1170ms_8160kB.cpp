#include<stdio.h>
#include<algorithm>
#include<queue>
#define N 150005
using namespace std;
typedef long long ll;
char a[N],ans[N];
bool temp[N];
ll sta[N],top;
struct node
{
    ll index,step;
    node(){}
    node(ll index,ll step)
    {
        this->index=index;
        this->step=step;
    }
};
priority_queue<node>que;
bool operator<(node A,node B)
{
    if(A.step==B.step)return a[A.index]<a[B.index];
    return A.step>B.step;
}
int main()
{
    ll T;
    scanf("%lld",&T);
    ll cas=1;
    while(T--)
    {
        ll n;
        scanf("%lld",&n);
        for(ll i=0;i<n;i++)ans[i]=0;
        scanf("%s",a);
        char ma=0;
        for(ll i=0;i<n;i++)
            ma=max(ma,a[i]);
        for(ll i=0;i<n;i++)
            if(ma==a[i])
                que.push(node(i,0));
        ll last=0;
        while(!que.empty())
        {
            node k=que.top();
            que.pop();
            if(last!=k.step)
            {
                last=k.step;
                while(top)temp[sta[--top]]=false;
            }
            if(ans[k.step]>a[k.index]||k.step>=n||temp[k.index])continue;
            sta[top++]=k.index;
            temp[k.index]=true;
            ans[k.step]=a[k.index];
            que.push(node((k.index*k.index+1)%n,k.step+1));
        }
        while(top)temp[sta[--top]]=false;
        printf("Case #%lld: ",cas++);
        for(ll i=0;i<n;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
}