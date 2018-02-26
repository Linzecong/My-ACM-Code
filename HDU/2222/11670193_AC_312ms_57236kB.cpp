#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=1000010;
const int maxm=50*10010;
const int SIGMA_SIZE=26;
int n;
char t[60],s[maxn];
struct node
{
    int val;
    node *next[26];
    node *fail;
    node *last;
    node(){memset(next,NULL,sizeof(next));fail=NULL;last=NULL;val=0;}
};
struct AC
{
    node *root;
    void clear(){root=new node();}
    int idx(char x){return x-'a';}
    void insert(char *s)
    {
        int n=strlen(s);
        node *p=root;
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!p->next[c])
                p->next[c]=new node();
            p=p->next[c];
        }
        p->val++;
    }
    void getfail()
    {
        queue<node *> q;
        node *p=NULL;
        for(int c=0;c<SIGMA_SIZE;c++)
        {
            p=root->next[c];
            if(p!=NULL)
            {
                p->fail=p->last=root;
                q.push(p);
            }
        }
        while(!q.empty())
        {
            node *r=q.front();q.pop();
            for(int c=0;c<SIGMA_SIZE;c++)
            {
                p=r->next[c];
                if(p==NULL){r->next[c]=r->fail->next[c];continue;}
                node *v=r->fail;
                while(v&&v->next[c]==NULL){v=v->fail;}
                if(v==NULL)p->fail=root;//加判断
                else p->fail=v->next[c];
                if(p->fail->val)p->last=p->fail;
                else p->last=p->fail->last;
                q.push(p);
            }
        }
    }
    int find(char *s)
    {
        int n=strlen(s);
        node *p=root;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            p=p->next[c];
            if(!p)p=root;//这里必须加判断，沿失配边走到root，说明不存在这样的匹配，要从root从新开始
            node *temp=NULL;
            if(p->val)temp=p;
            else temp=p->last;
            while(temp!=root&&temp!=NULL)
            {
                cnt+=temp->val;
                temp->val=0;
                temp=temp->last;
            }
        }
        return cnt;
    }
}tree;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        tree.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",t);
            tree.insert(t);
        }
        tree.getfail();
        scanf("%s",s);
        int ans=tree.find(s);
        printf("%d\n",ans);
    }
    return 0;
}
