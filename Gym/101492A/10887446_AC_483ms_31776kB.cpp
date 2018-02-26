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
#define MAXV 2000005
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long int ll;


inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}


struct edge{
    int v2,next;
}e[MAXV];

int n,m,k,edge_num;
int head[MAXV];

int col[MAXV];

void insert_edge(int v1,int v2){
    e[edge_num].v2=v2;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;

    e[edge_num].v2=v1;
    e[edge_num].next=head[v2];
    head[v2]=edge_num++;
}


bool flag=0;

bool ok(int index){
    for (int i = 1; i < index; i++) {
        for(int j=head[index];j!=-1;j=e[j].next)
            if (e[j].v2==i && col[i] == col[index])
                return false;
    }

    return true;
}

void search(int index){
    if(ok(index)){
        if(index==n){
            if(!flag){
                flag=1;
                for (int i = 1; i <= index; i++) {
                    cout<<(col[i])<<endl;
                }
            }

        }else{
            for (int i = 1; i <= k; i++) {
                col[index + 1] = i;
                search(index + 1);
                if(flag==1){
                    return;
                }
            }
        }
    }
}



int main()
{
    cin>>n>>m>>k;

    memset(head,-1,sizeof(head));
    edge_num=0;
    int a,b;
    for(int i=0;i<m;i++){

        scan_d(a);
        scan_d(b);
        insert_edge(a,b);
        insert_edge(b,a);
    }


    search(0);

    if(flag==0){
        cout<<-1<<endl;
    }

    return 0;
}
