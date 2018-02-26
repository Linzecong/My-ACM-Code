#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
const int MOD=51061;
const int INF=2000000000;
int n,m;

//vector<int> childs[MAXN];

int num[MAXN];//点的值
int size[MAXN];//树的大小
int lazyAdd[MAXN];
int lazyCha[MAXN];
//int lazyMuti[MAXN];
bool lazyRev[MAXN];
//int sum[MAXN];//子树和
int mx1[MAXN];//第一大
int mx2[MAXN];//第二大
int c1[MAXN];//第一大数
int c2[MAXN];//第二大数

int ch[MAXN][2];
int fa[MAXN];

//void push_mult(int node,int c){
//    lazyMuti[node]=lazyMuti[node]*c%MOD;
//    lazyAdd[node]=lazyAdd[node]*c%MOD;
//    sum[node]=sum[node]*c%MOD;
//    num[node]=num[node]*c%MOD;

//    mx1[node]=mx1[node]*c%MOD;
//    mx2[node]=mx2[node]*c%MOD;
//}

void push_add(int node,int c){
    //sum[node]+=(c*size[node])%MOD;

    mx1[node]+=c;
    num[node]+=c;
    if(mx2[node]!=-INF)mx2[node]+=c;
    lazyAdd[node]+=c;

}

void push_cha(int node,int c){
    // sum[node]=c*size[node]%MOD;
    mx1[node]=c;
    num[node]=c;
    c1[node]=size[node];
    mx2[node]=-INF;
    c2[node]=0;
    lazyCha[node]=c;
    if(lazyAdd[node])lazyAdd[node]=0;
    //  if(lazyMuti[node]!=1)lazyMuti[node]=1;
}



void push_down(int x){

    if(lazyRev[x]){
        lazyRev[ch[x][0]]^=1;
        lazyRev[ch[x][1]]^=1;
        lazyRev[x]^=1;
        swap(ch[x][0],ch[x][1]);

    }

    if(lazyCha[x]!=-INF){
        if(ch[x][0])push_cha(ch[x][0],lazyCha[x]);
        if(ch[x][1])push_cha(ch[x][1],lazyCha[x]);
        lazyCha[x]=-INF;
    }

    //    if(lazyMuti[x]!=1){
    //        if(ch[x][0]!=0)push_mult(ch[x][0],lazyMuti[x]);
    //        if(ch[x][1]!=0)push_mult(ch[x][1],lazyMuti[x]);
    //        lazyMuti[x]=1;
    //    }

    if(lazyAdd[x]){
        if(ch[x][0])push_add(ch[x][0],lazyAdd[x]);
        if(ch[x][1])push_add(ch[x][1],lazyAdd[x]);
        lazyAdd[x]=0;
    }

}

void _judge(int x,int val,int c){
    if(val>mx1[x]){
        mx2[x]=mx1[x];
        c2[x]=c1[x];
        mx1[x]=val;
        c1[x]=c;
    }
    else{
        if(val==mx1[x])
            c1[x]+=c;
        else{
            if(val>mx2[x]){
                mx2[x]=val;
                c2[x]=c;
            }
            else{
                if(val==mx2[x])
                    c2[x]+=c;
            }
        }
    }
}

void push_up(int x){
    int l=ch[x][0];
    int r=ch[x][1];

    size[x]=size[l]+size[r]+1;
    // sum[x]=num[x]+sum[l]+sum[r];

    mx1[x]=mx2[x]=-INF;
    c1[x]=c2[x]=0;

    _judge(x,num[x],1);
    if(l){
        _judge(x,mx1[l],c1[l]);
        _judge(x,mx2[l],c2[l]);
    }
    if(r){
        _judge(x,mx1[r],c1[r]);
        _judge(x,mx2[r],c2[r]);
    }
}

bool isroot(int x)
{
    return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}

void Rotate(int x){
    int y=fa[x],z=fa[y],l,r;
    if(ch[y][0]==x)l=0;else l=1;r=l^1;
    if(!isroot(y))
    {
        if(ch[z][0]==y)ch[z][0]=x;else ch[z][1]=x;
    }
    fa[x]=z;fa[y]=x;fa[ch[x][r]]=y;
    ch[y][l]=ch[x][r];ch[x][r]=y;
    push_up(y);push_up(x);
}

int top;
int q[MAXN];
void splay(int x){
    top=0;q[++top]=x;
    for(int i=x;!isroot(i);i=fa[i])
        q[++top]=fa[i];
    while(top)push_down(q[top--]);
    while(!isroot(x))
    {
        int y=fa[x],z=fa[y];
        if(!isroot(y))
        {
            if(ch[y][0]==x^ch[z][0]==y)Rotate(x);
            else Rotate(y);
        }
        Rotate(x);
    }
}

void access(int x){
    for(int t=0;x;t=x,x=fa[x]){
        splay(x);
        ch[x][1]=t;
        push_up(x);
    }
}

void make_root(int x){
    access(x);
    splay(x);
    lazyRev[x]^=1;
}



void link(int x,int y){
    make_root(x);
    fa[x]=y;
}

void cut(int x,int y){
    make_root(x);
    access(y);
    splay(y);
    fa[ch[y][0]]=0;
    ch[y][0]=0;
    push_up(y);
}

//int querySUM(int x,int y){
//    make_root(x);
//    access(y);
//    splay(y);
//    return sum[y]%MOD;
//}

void queryMAX2(int x,int y){
    make_root(x);
    access(y);
    splay(y);
    //return mx2[y];

    if(c1[y]==size[y])puts("ALL SAME");
    else printf("%d %d\n",mx2[y],c2[y]);
}

//int queryMAX2C(int x,int y){
//    make_root(x);
//    access(y);
//    splay(y);
//    return c2[y];
//}

void add(int x,int y,int c){
    make_root(x);
    access(y);
    splay(y);
    push_add(y,c);
}

//void muti(int x,int y,int c){
//    make_root(x);
//    access(y);
//    splay(y);
//    push_mult(y,c);
//}

void change(int x,int y,int c){
    make_root(x);
    access(y);
    splay(y);
    push_cha(y,c);
}


//void make_tree(int u,int father){
//    fa[u]=father;
//    /*sum[u]=*/
//    size[u]=1;
//    //lazyMuti[u]=1;
//    lazyAdd[u]=0;
//    lazyCha[u]=-INF;
//    lazyRev[u]=0;

//    mx1[u]=num[u];
//    c1[u]=1;
//    mx2[u]=-INF;
//    c2[u]=0;

//    ch[u][0]=ch[u][1]=0;
//    for(int i=0;i<childs[u].size();i++)
//        if(childs[u][i]!=father)
//            make_tree(childs[u][i],u);
//}

int main(){

    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++){
        printf("Case #%d:\n",qqq);


        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            mx1[i]=num[i],c1[i]=1;
            mx2[i]=-INF,c2[i]=0;
            size[i]=1;
            fa[i]=ch[i][0]=ch[i][1]=0;
            lazyAdd[i]=lazyRev[i]=0;lazyCha[i]=-INF;
        }

        for(int x,y,i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            //        childs[x].push_back(y);
            //       childs[y].push_back(x);
            link(x,y);
        }

        //make_tree(1,0);

        int u,v,a,b;
        int op;
        for(int i=1;i<=m;i++){
            scanf("%d",&op);



            int c,u1,u2;

            if(op==1){
                scanf("%d%d",&u,&v);
                scanf("%d%d",&a,&b);
                cut(u,v);
                link(a,b);
            }
            if(op==2){
                scanf("%d%d",&u,&v);
                scanf("%d",&c);
                change(u,v,c);
            }

            if(op==3){
                scanf("%d%d",&u,&v);
                scanf("%d",&c);
                add(u,v,c);
            }
            if(op==4){
                scanf("%d%d",&u,&v);


                queryMAX2(u,v);
            }

        }

    }

    return 0;
}


