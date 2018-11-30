#include<iostream>
#include<string.h>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int INF=1e18;

vector<int> G[MAXN];

int ch[MAXN*33][2];//子节点
int num[MAXN*33];//当前编号的节点有多少个
int tot=0;//总的点数
int rt[MAXN];//第i棵树的根的编号
int a[MAXN];

vector<pair<int,int > > qy[MAXN];

void insert(int x,int r){
    bitset<32> s(x);
    int cur=r;
    for(int i=31;i>=0;i--){
        if(!ch[cur][s[i]]){
            ch[cur][s[i]]=++tot;
        }
        cur=ch[cur][s[i]];
        num[cur]++;
    }
}

int merge(int rt,int lrt){
    if(!rt)return lrt;
    if(!lrt)return rt;
    ch[rt][0]=merge(ch[rt][0],ch[lrt][0]);
    ch[rt][1]=merge(ch[rt][1],ch[lrt][1]);
    return rt;
}


int query(int x,int rt){
    bitset<32> s(x);
    bitset<32> ans;
    int ucur=rt;
    for(int i=31;i>=0;i--){
        if(num[ch[ucur][!s[i]]]>0){
            ans[i]=1;
            ucur=ch[ucur][!s[i]];
        }
        else{
            ucur=ch[ucur][s[i]];
        }
    }
    return ans.to_ullong();
}

int ans[MAXN];
int temp=0;
void insertdfs(int u,int fa){
    rt[u]=++tot;
    insert(a[u],rt[u]);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa){
            insertdfs(v,u);
            rt[u]=merge(rt[u],rt[v]);
        }
    }
    for(auto &q: qy[u]){
        ans[q.first] = query(q.second,rt[u]);
    }
}


int main(){
    int N,Q;
    while(~scanf("%d%d",&N,&Q)){
        tot=0;
        temp=0;
        memset(ch,0,sizeof(ch));
        memset(num,0,sizeof(num));
        memset(rt,0,sizeof(rt));

        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
            G[i].clear();
            qy[i].clear();
        }

        int v;
        for(int i=2;i<=N;i++){
            scanf("%d",&v);
            G[v].push_back(i);
        }



        int u,x;
        for(int i=0;i<Q;i++){
            scanf("%d%d",&u,&x);
            qy[u].push_back(make_pair(i,x));
        }
        insertdfs(1,0);
        for(int i = 0; i < Q; i++)
            printf("%d\n", ans[i]);


    }



    return 0;
}















