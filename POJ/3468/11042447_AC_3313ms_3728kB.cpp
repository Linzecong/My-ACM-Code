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
#include<bitset>
using namespace std;
typedef long long int ll;
const int MAXN=100010;
//伸展树模板！

int pre[MAXN];//父节点
int ch[MAXN][2];//左右两个孩子
int size[MAXN];//子树大小
int root;//根节点
int tot1;//总大小
int key[MAXN];//该点的值
long long int sum[MAXN];//子树和
int lazy[MAXN];//延迟标记

int s[MAXN],tot2;//用于删除操作

int A[MAXN];//原始数组

int n,q;

//新建节点，节点编号，父亲编号，值
void NewNode(int &r,int fa,int k){
    if(tot2)
        r=s[tot2--];
    else
        r=++tot1;

    pre[r]=fa;
    size[r]=1;
    key[r]=k;

    lazy[r]=0;
    sum[r]=0;
    ch[r][0]=ch[r][1]=0;
}

//给r为根的子树增加值
void Update_Add(int r,int C){
    if(r==0)
        return;
    lazy[r]+=C;
    key[r]+=C;

    sum[r]+=(long long)C*size[r];
}


void Push_Up(int r){
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
    sum[r]=sum[ch[r][0]]+sum[ch[r][1]]+key[r];
}

void Push_Down(int r){
    if(lazy[r]){
        Update_Add(ch[r][0],lazy[r]);
        Update_Add(ch[r][1],lazy[r]);
        lazy[r]=0;
    }
}


//建树
void Build(int &x,int l,int r,int fa){
    if(l>r)
        return;
    int mid=(l+r)>>1;
    NewNode(x,fa,A[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}


void Init(){
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    root=tot1=tot2=0;

    ch[root][0]=ch[root][1]=pre[root]=size[root]=lazy[root]=sum[root]=0;

    key[root]=0;

    NewNode(root,0,-1);
    NewNode(ch[root][1],root,-1);

    Build(ch[ch[root][1]][0],1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);

}

//0左旋，1右旋
void Rotate(int x,int kind){
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y]=x;

    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}

//伸展，将r调到goal下
void Splay(int r,int goal){
    Push_Down(r);

    while(pre[r]!=goal){

        if(pre[pre[r]]==goal){
            Rotate(r,ch[pre[r]][0]==r);
        }
        else{
            int y=pre[r];
            int kind=ch[pre[y]][0]==y;
            if(ch[y][kind]==r){
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    if(goal==0)
        root=r;


}

int Get_Kth(int r,int k){
    Push_Down(r);
    int t=size[ch[r][0]]+1;
    if(t==k)
        return r;
    if(t>k)
        return Get_Kth(ch[r][0],k);
    else
        return Get_Kth(ch[r][1],k-t);
}

int Get_Min(int r){
    Push_Down(r);
    while(ch[r][0]){
        r=ch[r][0];
        Push_Down(r);
    }
    return r;
}

int Get_Max(int r){
    Push_Down(r);
    while(ch[r][1]){
        r=ch[r][1];
        Push_Down(r);
    }
    return r;
}

void Add(int l,int r,int C){
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    Update_Add(ch[ch[root][1]][0],C);
    Push_Up(ch[root][1]);
    Push_Up(root);
}

long long int Query_Sum(int l,int r){
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    return sum[ch[ch[root][1]][0]];
}

int main(){

    while(~scanf("%d%d",&n,&q)){
        Init();
        while(q--){
            char op[20];
            int x,y,z;
            scanf("%s",op);
            if(op[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                printf("%I64d\n",Query_Sum(x,y));
            }
            else
            {
                scanf("%d%d%d",&x,&y,&z);
                Add(x,y,z);
            }
        }


    }

    return 0;
}

