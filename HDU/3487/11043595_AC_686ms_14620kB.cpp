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
#define Key_Value ch[ch[root][1]][0]
using namespace std;
typedef long long int ll;
const int MAXN=300010;
const int INF=0x3f3f3f3f;
//伸展树模板！

int pre[MAXN];//父节点
int ch[MAXN][2];//左右两个孩子
int size[MAXN];//子树大小
int root;//根节点
int tot1;//总大小
int key[MAXN];//该点的值
long long int sum[MAXN];//子树和
int minnum[MAXN];//最小值

int lazySum[MAXN];//区间累加延迟标记
int lazyRev[MAXN];//翻转区间延迟标记
int lazyCha[MAXN];//区间修改延迟标记
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
    
    lazyRev[r]=0;
    minnum[r]=k;
    lazySum[r]=0;
    sum[r]=0;
    ch[r][0]=ch[r][1]=0;
}

//给r为根的子树增加值
void Update_Add(int r,int C){
    if(r==0)
        return;
    lazySum[r]+=C;
    key[r]+=C;
    minnum[r]+=C;
    
    sum[r]+=(long long)C*size[r];
}

void Update_Rev(int r){
    if(!r)
        return;
    swap(ch[r][0],ch[r][1]);
    lazyRev[r]^=1;
}


void Push_Up(int r){
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
    sum[r]=sum[ch[r][0]]+sum[ch[r][1]]+key[r];
    minnum[r]=key[r];
    if(ch[r][0])minnum[r]=min(minnum[r],minnum[ch[r][0]]);
    if(ch[r][1])minnum[r]=min(minnum[r],minnum[ch[r][1]]);
}

void Push_Down(int r){
    if(lazyRev[r]){
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        lazyRev[r]=0;
    }
    
    if(lazySum[r]){
        Update_Add(ch[r][0],lazySum[r]);
        Update_Add(ch[r][1],lazySum[r]);
        lazySum[r]=0;
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
    
    root=tot1=tot2=0;
    
    ch[root][0]=ch[root][1]=pre[root]=size[root]=lazySum[root]=lazyRev[root]=sum[root]=0;
    
    key[root]=0;
    minnum[root]=INF;
    
    //   NewNode(root,0,INF);
    //   NewNode(ch[root][1],root,INF);//求最小值用
    
    NewNode(root,0,-1);
    NewNode(ch[root][1],root,-1);
    
    Build(Key_Value,1,n,ch[root][1]);
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
            Push_Down(pre[r]);
            Push_Down(r);
            Rotate(r,ch[pre[r]][0]==r);
        }
        else{
            Push_Down(pre[pre[r]]);
            Push_Down(pre[r]);
            Push_Down(r);
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

void erase(int r)//回收内存
{
    if(r)
    {
        s[++tot2]=r;
        erase(ch[r][0]);
        erase(ch[r][1]);
    }
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

void Reverse(int l,int r)
{
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    Update_Rev(Key_Value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}

void Revolve(int l,int r,int T)//循环右移
{
    int len=r-l+1;
    T=(T%len+len)%len;
    if(T==0)return;
    int c=r-T+1;//将区间[c,r]放在[l,c-1]前面
    Splay(Get_Kth(root,c),0);
    Splay(Get_Kth(root,r+2),root);
    int tmp=Key_Value;
    Key_Value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,l+1),root);
    Key_Value=tmp;
    pre[Key_Value]=ch[root][1];//这个不用忘记
    Push_Up(ch[root][1]);
    Push_Up(root);
}

void Insert(int x,int P)//在第x个数后面插入P
{
    Splay(Get_Kth(root,x+1),0);
    Splay(Get_Kth(root,x+2),root);
    NewNode(Key_Value,ch[root][1],P);
    Push_Up(ch[root][1]);
    Push_Up(root);
}

long long int Query_Sum(int l,int r){
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    return sum[ch[ch[root][1]][0]];
}

void Delete(int x)//删除第x个数
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+2),root);
    erase(Key_Value);
    pre[Key_Value]=0;
    Key_Value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}

int Query_Min(int l,int r)
{
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    return minnum[Key_Value];
}

void Move(int l,int r,int c)
{
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    int tmp=Key_Value;
    Key_Value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    Splay(Get_Kth(root,c+1),0);
    Splay(Get_Kth(root,c+2),root);
    Key_Value=tmp;
    pre[Key_Value]=ch[root][1];
    Push_Up(ch[root][1]);
    Push_Up(root);
}


int cnt=0;
void Print(int r=root)
{
    if(!r)return;
    Push_Down(r);
    Print(ch[r][0]);
    if(cnt>=1&&cnt<=n)
    {
        printf("%d",key[r]);
        if(cnt<n)printf(" ");
        else printf("\n");
    }
    cnt++;
    Print(ch[r][1]);
}


int main(){
    
    char op[20];
    int x,y,z;
    while(scanf("%d%d",&n,&q)==2)
    {
        if(n<0 && q<0)break;
        
          for(int i=0;i<=n;i++)
               A[i]=i;
        Init();
        while(q--)
        {
            scanf("%s",op);
            if(op[0]=='C')
            {
                scanf("%d%d%d",&x,&y,&z);
                Move(x,y,z);
            }
            else
            {
                scanf("%d%d",&x,&y);
                Reverse(x,y);
            }
        }
        cnt=0;
        Print(root);
        
    }
    return 0;
}
