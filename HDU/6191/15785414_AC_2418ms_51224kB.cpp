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

int root=1;//总的根的个数
int ch[MAXN*33][2];//子节点
int num[MAXN*33];//当前编号的节点有多少个
int tot=0;//总的点数
int rt[MAXN];//第i棵树的根的编号
int a[MAXN];

void insert(int x,int r,int lr){
    bitset<32> s(x);

    int cur=r;
    int lcur=lr;
    for(int i=31;i>=0;i--){
        if(!ch[cur][s[i]]){
            ch[cur][s[i]]=++tot;
            ch[cur][!s[i]]=ch[lcur][!s[i]];
            num[ch[cur][s[i]]]=num[ch[lcur][s[i]]];
        }
        cur=ch[cur][s[i]];
        lcur=ch[lcur][s[i]];
        num[cur]++;
    }
}

int lft[MAXN],riht[MAXN];
int temp=0;
void insertdfs(int u,int fa){
    rt[u]=++tot;
    lft[u]=u;
    riht[u]=u;
    insert(a[u],rt[u],rt[temp]);
    temp=u;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa){
            insertdfs(v,u);
            riht[u]=riht[v];
        }
    }

}


int query(int x,int rt,int lrt){
    bitset<32> s(x);
    bitset<32> ans;

    int ucur=rt;
    int vcur=lrt;
    for(int i=31;i>=0;i--){
        if(num[ch[vcur][!s[i]]]-num[ch[ucur][!s[i]]]>0){
            //printf("%d %d %d\n",i,num[ch[ucur][!s[i]]],num[ch[vcur][!s[i]]]);
            ans[i]=1;
            ucur=ch[ucur][!s[i]];
            vcur=ch[vcur][!s[i]];
        }
        else{
            ucur=ch[ucur][s[i]];
            vcur=ch[vcur][s[i]];
        }
    }
    return ans.to_ullong();
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
        }

        int v;
        for(int i=2;i<=N;i++){
            scanf("%d",&v);
            G[v].push_back(i);
        }

        insertdfs(1,0);

        int u,x;
        while(Q--){
            scanf("%d%d",&u,&x);
            //cout<<lft[u]<<" "<<riht[u]<<endl;
            printf("%d\n",max(x^a[u],query(x,rt[lft[u]],rt[riht[u]])));
        }



    }



    return 0;
}















