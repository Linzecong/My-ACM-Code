#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const int INF=0x3f3f3f3f;

int len[MAXN];
int nxt[MAXN][30];
int fail[MAXN];
int num[MAXN];
int cnt[MAXN];
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
}



 
char str[MAXN];
int sum[MAXN][MAXN];
int main(){
 
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%s",str);
        int len1=strlen(str);
        for(int i=0;i<len1;i++){
            init_tree();
            for(int j=i;j<len1;j++){
                add_char(str[j]);
                sum[i+1][j+1]=tot-2;
            }
        }
 
        int Q;
        int l,r;
        scanf("%d",&Q);
        while(Q--){
            scanf("%d%d",&l,&r);
            printf("%d\n",sum[l][r]);
        }
 
    }
    return 0;
}
