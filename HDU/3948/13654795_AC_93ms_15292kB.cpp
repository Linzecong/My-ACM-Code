#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int len[MAXN];//表示编号为i的节点表示的回文串的长度（一个节点表示一个回文串）
int nxt[MAXN][30];//表示编号为i的节点表示的回文串在两边添加字符c以后变成的回文串的编号
int fail[MAXN];//表示节点i失配以后跳转不等于自身的节点i表示的回文串的最长后缀回文串
int num[MAXN];//表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数。
int cnt[MAXN];//表示节点i表示的本质不同的串的个数
int last;
int S[MAXN];
int tot;
int N;
int ans=0;

int new_node(int l){
    cnt[tot]=0;
    num[tot]=0;
    len[tot]=l;
    return tot++;
}

void init_tree(){
    memset(nxt,0,sizeof(nxt));
    tot=0;
    new_node(0);
    new_node(-1);
    last=0;
    N=0;
    S[N]=-1;
    fail[0]=1;
}

int get_fail(int x){
    while(S[N-len[x]-1]!=S[N])
        x=fail[x];
    return x;
}


int add_char(int c){
    c-='a';
    S[++N]=c;
    int cur=get_fail(last);
    if(!nxt[cur][c]){
        int now=new_node(len[cur]+2);
        fail[now]=nxt[get_fail(fail[cur])][c];
        nxt[cur][c]=now;
        ans++;
        num[now]=num[fail[now]]+1;
    }
    last=nxt[cur][c];
    cnt[last]++;
    return num[last];
}

void count(){
    for(int i=tot-1;i>=0;i--)
        cnt[fail[i]]+=cnt[i];

//    int ans=0;
//    for(int i=2;i<tot;i++){
//        ans+=cnt[i];
//    }
//    cout<<ans<<endl;
}

char str[100005];
int main(){

    int T;
    scanf("%d",&T);

    for(int qqq=1;qqq<=T;qqq++){
        ans=0;
        scanf("%s",str);
        init_tree();
        int len1=strlen(str);
        for(int i=0;i<len1;i++)
            add_char(str[i]);
        printf("Case #%d: %d\n",qqq,tot-2);

    }


}
