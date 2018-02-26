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
};

node* newnode(){
    node *newnode=new node;
    for(int j=0;j<26;j++)
        newnode->next[j]=0;
    newnode->sum=0;
    newnode->fail=0;
}

void insert(node* root,char s[],int len){
    node *p=root;
    for(int i=0;i<len;i++){
        int x=s[i]-'a';
        if(p->next[x]==0){
            p->next[x]=newnode();
        }
        p=p->next[x];
    }
    p->sum++;
}

node* que[1000005];
void build_fail(node *root){
    int head=0;
    int tail=1;
    node *p;
    node *temp;
    que[head]=root;
    while(head<tail){
        temp=que[head++];
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
                que[tail++]=temp->next[i];
            }
            else
                temp->next[i]=temp!=root?temp->fail->next[i]:root;
        }
    }
}

int AC_Match(char s[],int len,node *root){
    node *p=root;
    node *temp;
    int ans=0;
    for(int i=0;i<len;i++){
        int x=s[i]-'a';
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


char a[1000005];
char b[100];
node *root;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        root=newnode();
        while(n--){
            scanf("%s",b);
            insert(root,b,strlen(b));
        }
        scanf("%s",a);
        build_fail(root);
        printf("%d\n",AC_Match(a,strlen(a),root));
    }
    return 0;
}


