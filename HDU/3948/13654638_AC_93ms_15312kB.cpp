#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include <set>
#include <stack>
#include <queue>
#include <vector>

#define lowbit(x) (x)&(-x)
#define Abs(x) ((x) > 0 ? (x) : (-(x)))
#define FOR(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define FORP(i,a,b) for(int i=(a);i<=(b);i++)
#define FORM(i,a,b) for(int i=(a);i>=(b);i--)
#define ls(a,b) (((a)+(b)) << 1)
#define rs(a,b) (((a)+(b)) >> 1)
#define getlc(a) ch[(a)][0]
#define getrc(a) ch[(a)][1]

#define maxn 100005
#define maxc 30
#define maxm 100005
#define INF 1070000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<class T> inline
void read(T& num){
    num = 0; bool f = true;char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = false;ch = getchar();}
    while(ch >= '0' && ch <= '9') {num = num * 10 + ch - '0';ch = getchar();}
    num = f ? num: -num;
}
int outs[100];
template<class T> inline
void write(T x){
    if (x==0) {putchar('0'); putchar('\n'); return;}
    if (x<0) {putchar('-'); x=-x;}
    int num=0;
    while (x){ outs[num++]=(x%10); x=x/10;}
    FORM(i,num-1,0) putchar(outs[i]+'0'); putchar('\n');
}
/*==================split line==================*/
int tot[maxn],num[maxn],len[maxn],fail[maxn],S[maxn],ch[maxn][maxc];
char s[maxn];
int p,last,ans,cnt;
int newnode(int l){
    tot[p]=0; num[p]=0; len[p]=l;
    return p++;
}
void init(){
    p=0; memset(ch,0,sizeof(ch));
    newnode(0); newnode(-1);
    last=0; cnt=0; S[cnt]=-1; fail[0]=1;
}
int get_fail(int x){
    while(S[cnt-len[x]-1]!=S[cnt]) x=fail[x];
    return x;
}
void add(int c,int pos){
    S[++cnt]=c;
    int cur=get_fail(last);
    if (!ch[cur][c]){
        int now=newnode(len[cur]+2);
        fail[now]=ch[get_fail(fail[cur])][c];
        ch[cur][c]=now; ans++;
    }
    last=ch[cur][c];
    tot[last]++;
}
int main(){
    int cas; read(cas); int Cas=1;
    while (Cas<=cas){
        printf("Case #%d: ",Cas);
        ans=0;
        scanf("%s",s);
        int n=strlen(s);
        init();
        FORP(i,0,n-1) add(s[i]-'a'+1,i);
        write(ans);
        Cas++;
    }
}
