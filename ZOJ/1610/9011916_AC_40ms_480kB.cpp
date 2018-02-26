#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=10010;

int tree[MAXN<<2];



void build(int l,int r,int rt){
    tree[rt]=-1;
    if(l==r){
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}

void pushdown(int rt){

    tree[rt<<1]=tree[rt<<1|1]=tree[rt];
    tree[rt]=-1;

}



void update(int L,int R,int C, int l, int r, int rt){
    if(L<=l&&r<=R){
        tree[rt]=C;
        return;
    }

    int m=(l+r)/2;

    if(tree[rt]!=-1)
        pushdown(rt);

    if(L<=m)
        update(L,R,C,l,m,rt<<1);

    if(R>m)
        update(L,R,C,m+1,r,rt<<1|1);

}

int col[MAXN];

void query(int l,int r,int rt){

    if(l==r){
        col[l]=tree[rt];
        return;
    }

    if(tree[rt]!=-1)
        pushdown(rt);

    int m=(l+r)/2;

    query(l,m,rt<<1);
    query(m+1,r,rt<<1|1);
}


struct node{
    int col;
    int num;
    bool operator <(node a){
        return col<a.col;
    }
};


int main(){
    int n;

    while(~scanf("%d",&n)){
        build(1,8001,1);

        for(int i=0;i<n;i++){
            int l,r,c;
            scanf("%d%d%d",&l,&r,&c);
            update(l+1,r,c,1,8001,1);
        }
        query(1,8001,1);


        vector<node> list;
        map<int,int> m;

        col[0]=-1;
        for(int i=1;i<=8001;i++){

            if(col[i]!=col[i-1]&&col[i]!=-1){
                if(!m[col[i]])
                    m[col[i]]=1;
                else
                    m[col[i]]++;
            }
        }

        for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
            node temp;
            temp.col=it->first;
            temp.num=it->second;
            list.push_back(temp);
        }

        sort(list.begin(),list.end());

        for(int i=0;i<list.size();i++)
            printf("%d %d\n",list[i].col,list[i].num);

        printf("\n");

    }


    return 0;
}







