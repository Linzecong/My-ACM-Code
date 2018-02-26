#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;

struct node
{
    node *next[26];
    node *fail;
    int sum;
    ~node(){
        for(int i=0;i<26;i++)
            if(next[i])
                delete next[i];

    }
};

node* newnode(){
    node *newnode=new node;
    for(int j=0;j<26;j++)
        newnode->next[j]=0;
    newnode->sum=0;
    newnode->fail=0;
    return newnode;
}

void insert(node* root,char s[],int len){
    node *p=root;
    for(int i=0;i<len;i++){
        int x=s[i]-'A';
        if(p->next[x]==0){
            p->next[x]=newnode();
        }
        p=p->next[x];
    }
    p->sum++;
}

//node* que[1000005];//手写队列，快那么几十毫秒
void build_fail(node *root){
    // int head=0;
    // int tail=1;
    node *p;
    node *temp;
    // que[head]=root;
    queue<node*> que;
    que.push(root);

    // while(head<tail){
    while(!que.empty()){
        temp=que.front();
        que.pop();
        // temp=que[head++];
        for(int i=0;i<26;i++){
            if(temp->next[i]){
                if(temp==root)
                    temp->next[i]->fail=root;
                else{
                    p=temp->fail;
                    while(p){
                        if(p->next[i]){
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==0)
                        temp->next[i]->fail=root;
                }
              //  que[tail++]=temp->next[i];
                que.push(temp->next[i]);
            }
           // else
           //     temp->next[i]=temp!=root?temp->fail->next[i]:root;//优化？
        }
    }
}

int AC_Match(char s[],int len,node *root){
    node *p=root;
    node *temp;
    int ans=0;
    for(int i=0;i<len;i++){
        int x=s[i]-'A';
        while(!p->next[x]&&p!=root)
            p=p->fail;
        p=p->next[x];
        if(p==0)
            p=root;
        temp=p;
        while(temp!=root){
            if(temp->sum>=0){
                ans+=temp->sum;

                temp->sum=-1;
            }
            else
                break;
            temp=temp->fail;
        }
    }

    p=root;
    //temp=0;

    for(int i=len-1;i>=0;i--){
        int x=s[i]-'A';
        while(!p->next[x]&&p!=root)
            p=p->fail;
        p=p->next[x];
        if(p==0)
            p=root;
        temp=p;
        while(temp!=root){
            if(temp->sum>=0){
                ans+=temp->sum;

                temp->sum=-1;
            }
            else
                break;
            temp=temp->fail;
        }
    }
    return ans;
}


char a[5100005];
char b[1005];
//char c[1005];
char num[100];
node *root;

int main(){
    int t;
    scanf("%d",&t);
    int len;
    while(t--){
        int n;
        scanf("%d",&n);
        root=newnode();
        while(n--){
            scanf("%s",b);
            len=strlen(b);
           // for(int i=0;i<len;i++)
           //     c[i]=b[len-1-i];
            insert(root,b,len);
           // insert(root,c,len);
        }
        getchar();
        int ch;
        int i=0;
        while(1){
            ch=getchar();
            if(ch!='\n'){
                if(ch=='['){
                    int j=0;
                    while(1){
                        ch=getchar();
                        if(ch!=']')
                            num[j++]=ch;
                        else
                            break;
                    }
                    ch=num[j-1];
                    num[j]='\0';
                    int count=atoi(num);
                    for(int k=0;k<count;k++)
                        a[i++]=ch;
                }
                else
                    a[i++]=ch;
            }
            else
                break;
        }

        build_fail(root);
        printf("%d\n",AC_Match(a,i,root));
        delete root;
    }
    return 0;
}

