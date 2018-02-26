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

struct Node{
    int num;
    Node* ch[10];
}node[3010*35],*root;

int cnt;
int ans;

Node* newnode(){
    node[cnt].num=0;
    for(int i=0;i<10;i++)
            node[cnt].ch[i]=NULL;
    return &node[cnt++];
}


void insert(char *a){
    Node* cur=root;
    int len=strlen(a);
    for(int i=0;i<len;i++){
        if(cur->ch[a[i]-'0']==NULL)
            cur->ch[a[i]-'0']=newnode();
        cur=cur->ch[a[i]-'0'];
    }
    cur->num++;
    ans=max(ans,cur->num);
}

int main(){

    int n;
    char str[35];
    while(scanf("%d",&n)!= EOF){
        ans=0;
        cnt=0;
        root=newnode();

        for(int i=0;i<n;i++){
            scanf("%s",str);
            int len=strlen(str);

            for(int j=0;j<len;j++){
                if(str[j]!='0'){
                    insert(str+j);
                    break;
                }
                if(j==len-1)
                    insert("0");
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}






