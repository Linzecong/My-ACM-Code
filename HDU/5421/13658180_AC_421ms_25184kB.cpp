#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

int len[MAXN];//表示编号为i的节点表示的回文串的长度（一个节点表示一个回文串）
int nxt[MAXN][27];//表示编号为i的节点表示的回文串在两边添加字符c以后变成的回文串的编号
int fail[MAXN];//表示节点i失配以后跳转不等于自身的节点i表示的回文串的最长后缀回文串
int num[MAXN];//表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数。
int cnt[MAXN];//表示节点i表示的串的个数
int lastR;
int lastL;
int L,R;
int S[MAXN];
int tot;//节点总数，即不同的回文串个数，记得-2

int new_node(int l){
    cnt[tot]=0;
    num[tot]=0;
    len[tot]=l;
    return tot++;
}

void init_tree(int len1){
    L=len1;
    R=len1-1;
    memset(nxt,0,sizeof(nxt));
    tot=0;
    new_node(0);
    new_node(-1);
    lastL=lastR=0;
    memset(S,-1,sizeof(S));
    fail[0]=1;
}

int get_fail(int x,bool d){
    if(d==1){
        while(S[R-len[x]-1]!=S[R])
            x=fail[x];
    }
    else{
        while(S[L+len[x]+1]!=S[L])
            x=fail[x];
    }
    return x;
}


int add_char(int c,bool d){
    c-='a';
    int cur;
    if(d==1){
        S[++R]=c;
        cur=get_fail(lastR,d);
    }
    else{
        S[--L]=c;
        cur=get_fail(lastL,d);
    }

    if(!nxt[cur][c]){
        int now=new_node(len[cur]+2);
        fail[now]=nxt[get_fail(fail[cur],d)][c];
        nxt[cur][c]=now;
        num[now]=num[fail[now]]+1;
    }
    if(d==1){
        lastR=nxt[cur][c];
        cnt[lastR]++;
        if(len[lastR]==R-L+1)//当添加字符时，可能会影响最后添加的那个字符，所以有时候要同步更新last
            lastL=lastR;
        return num[lastR];
    }
    else{
        lastL=nxt[cur][c];
        cnt[lastL]++;
        if(len[lastL]==R-L+1)
            lastR=lastL;
        return num[lastL];
    }

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

char str[MAXN];
char c[55];
int main(){
    int Q;
    while(~scanf("%d",&Q)){
        init_tree(Q);
        int op;
        ll sum=0;
        while(Q--){
            scanf("%d",&op);
            if(op==1){
                scanf("%s",c);
                sum+=ll(add_char(c[0],0));
            }
            if(op==2){
                scanf("%s",c);
                sum+=ll(add_char(c[0],1));
            }
            if(op==3){
                printf("%d\n",tot-2);
            }
            if(op==4){
                printf("%lld\n",sum);
            }
        }

    }




    return 0;
}
