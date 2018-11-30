#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int MAXN = 150005;

struct edge{
    int x,y,v;
    edge(int u,int v1,int w){
        x=u;
        y=v1;
        v=w;
    }
    edge(){}
}e[MAXN];
int edge_num;
void insert_edge(int u,int v,int w){
    e[++edge_num].x=u;
    e[edge_num].y=v;
    e[edge_num].v=w;
}

int N,M;
int X[MAXN],Y[MAXN];
struct Line{
    int x,y,id;
    double alp;
    Line(){}
    Line(int x,int y,int id):x(x),y(y),id(id){
        alp=-atan2(Y[y]-Y[x],X[y]-X[x]);
    }
    friend bool operator <(const Line &l1,const Line &l2){
        return l1.alp<l2.alp;
    }
}line[MAXN];

set<Line> seg[MAXN];


int cnt=0;
int V[MAXN];
int belong[MAXN];
int sta[MAXN];
int top;
int num;


int minroot;
int pre[MAXN], vis[MAXN], id[MAXN], in[MAXN];
int Directed_MST(int root,int n,int m)
{
    int tn,tm,ret=0;
    while(1)
    {
        for(int i=1;i<=n;i++)in[i]=2e9,pre[i]=0;
        for(int i=1;i<=m;i++)
            if(e[i].v<in[e[i].y])
            {
                in[e[i].y]=e[i].v;
                pre[e[i].y]=e[i].x;
//                //minroot-edge_num+1
//                if (e[i].x == root)
//                    minroot = i;
            }
        in[root]=tn=tm=0;
        for(int i=1;i<=n;i++)id[i]=vis[i]=0;
        for(int i=1,v;i<=n;i++)
        {
            ret+=in[v=i];
            while(v!=root&&!vis[v]&&!id[v])vis[v]=i,v=pre[v];
            if(vis[v]==i)
            {
                id[v]=++tn;
                for(int j=pre[v];j!=v;j=pre[j])id[j]=tn;
            }
        }
        if(!tn)break;
        for(int i=1;i<=n;i++)
            if(!id[i])id[i]=++tn;
        for(int i=1;i<=m;i++)
            if(id[e[i].x]!=id[e[i].y])
                e[++tm]=edge(id[e[i].x],id[e[i].y],e[i].v-in[e[i].y]);
        n=tn;m=tm;root=id[root];
    }
    return ret;
}


//int Directed_MST(int root,int n,int m) {
//    int ans = 0, u, v, tmp;
//    while (1) {
//        memset(pre, -1, sizeof(pre));
//        for (int i = 1; i <= n; i++)
//            in[i] = INF;
//        for (int i = 1; i <= m; i++) {
//            u = E[i].x;
//            v = E[i].y;
//            if (u != v && E[i].v < in[v]) {
//                in[v] = E[i].v;
//                pre[v] = u;
//                if (u == root)
//                    minroot = i;
//            }
//        }

//        for (int i = 1; i <= n; i++) {
//            if (i == root)
//                continue;
//            if (in[i] == INF)
//                return -1;
//        }
//        int cnt = 0;
//        memset(vis, -1, sizeof(vis));
//        memset(id, -1, sizeof(id));
//        in[root] = 0;

//        for (int i = 1; i <= n; i++) {
//            ans += in[i];
//            tmp = i;
//            while (tmp != root && id[tmp] == -1 && vis[tmp] != i) {
//                vis[tmp] = i;
//                tmp = pre[tmp];
//            }

//            if (tmp != root && id[tmp] == -1) {
//                u = pre[tmp];
//                while (u != tmp) {
//                    id[u] = cnt;
//                    u = pre[u];
//                }
//                id[tmp] = cnt++;
//            }
//        }

//        if (cnt == 0)
//            break;

//        for (int i = 1; i <= n; i++)
//            if (id[i] == -1)
//                id[i] = cnt++;

//        for (int i = 1; i <= m; i++) {
//            tmp = E[i].y;
//            E[i].x  = id[E[i].x];
//            E[i].y = id[E[i].y];
//            if (E[i].x != E[i].y)
//                E[i].v -= in[tmp];
//        }

//        n = cnt;
//        root = id[root];
//    }
//    return ans;
//}




int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d%d",&X[i],&Y[i]);
    int x,y;
    cnt=1;
    for(int i=1;i<=M;i++){
        scanf("%d%d%d%d",&x,&y,&V[i*2],&V[i*2+1]);//方便遍历
        cnt++;seg[x].insert(line[cnt]=Line(x,y,cnt));
        cnt++;seg[y].insert(line[cnt]=Line(y,x,cnt));
    }

    for(int i=2;i<=cnt;i++){
        if(belong[i]==0){
            sta[top=1]=i;
            int k=i;
            for(int j=line[i].y;;j=line[k].y){
                set<Line>::iterator it=seg[j].find(line[k^1]);//单向边的话，把这个删了就好了
                it++;//不让他走自己
                if(it==seg[j].end())//优先找小的区域
                    it=seg[j].begin();
                k=(*it).id;
                if(k==i)
                    break;
                sta[++top]=k;
            }
            num++;
            for(int j=1;j<=top;j++)
                belong[sta[j]]=num;
        }
    }

    for(int i=2;i<=cnt;i++){
        if(V[i]){
            insert_edge(belong[i],belong[i^1],V[i]);
        }
       // cout<<belong[i]<<endl;
    }

    num++;
    for(int i=1;i<num;i++)
        insert_edge(num,i,1e9);
    int t=Directed_MST(num,num,edge_num)-1e9;

   // cout<<num<<" "<<minroot<<endl;
    printf("%d\n",t);

    return 0;
}






