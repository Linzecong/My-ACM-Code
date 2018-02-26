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
const int MAXV=200005;

int k,ans;
struct edge{
    int v1,v2,next;
}e[MAXV];

int n,edge_num;
int head[MAXV];
int num[MAXV];

void insert_edge(int v1,int v2){
    e[edge_num].v1=v1;
    e[edge_num].v2=v2;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;

    e[edge_num].v1=v2;
    e[edge_num].v2=v1;
    e[edge_num].next=head[v2];
    head[v2]=edge_num++;
}

void dfs(int v,int fa){
    num[v]=1;
    for(int i=head[v];i!=-1;i=e[i].next){
        if(e[i].v2!=fa){
            dfs(e[i].v2,v);

            num[v]+=num[e[i].v2];
            if(num[e[i].v2]>=k&&n-num[e[i].v2]>=k)
                ans++;
        }
    }

}


int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        edge_num=0;
        memset(head,-1,sizeof(head));
        memset(num,0,sizeof(num));

        scanf("%d%d",&n,&k);
        int a,b;
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            insert_edge(a,b);
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);

    }

    return 0;
}






