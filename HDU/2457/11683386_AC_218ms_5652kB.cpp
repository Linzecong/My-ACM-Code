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
using namespace std;
typedef long long int ll;
#define MAXN 1005
#define  NEXTNUM 4
#define  FC 0
#define  INF 0x3f3f3f3f

int nxt[MAXN][NEXTNUM];//trie树
int fail[MAXN];//fail指针
int num[MAXN];
int cnt;

map<char,int> mp;
//AC自动机部分
int newnode(){
    for(int j=0;j<NEXTNUM;j++)
        nxt[cnt][j]=0;
    num[cnt]=0;
    fail[cnt]=0;
    return cnt++;
}

void insert(char s[],int len){
    int p=0;
    for(int i=0;i<len;i++){
        int x=mp[s[i]]-FC;
        if(nxt[p][x]==0){
            nxt[p][x]=newnode();
        }
        p=nxt[p][x];
    }
    num[p]++;
}


void build_fail(){
    int temp;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        temp=que.front();
        que.pop();
        if(num[fail[temp]])
            num[temp]=1;
        for(int i=0;i<NEXTNUM;i++){
            int v=nxt[temp][i];
            if(v==0)
                nxt[temp][i]=nxt[fail[temp]][i];//高效求解fail且高效匹配
            else
                que.push(v);
            if(temp!=0)
                fail[v]=nxt[fail[temp]][i];
        }
    }
}

int dp[1005][1005];
int AC_Match(char s[],int len){
    int ans=INF;
    for(int i=0;i<=len;i++)
        for(int j=0;j<cnt;j++)
            dp[i][j]=INF;
    dp[0][0]=0;

    for(int i=1;i<=len;i++)
        for(int k=0;k<4;k++)
        for(int j=0;j<cnt;j++)

                if(!num[nxt[j][k]]){
                    if(mp[s[i-1]]==k)
                        dp[i][nxt[j][k]]=min(dp[i][nxt[j][k]],dp[i-1][j]);
                    else
                        dp[i][nxt[j][k]]=min(dp[i][nxt[j][k]],dp[i-1][j]+1);
                }
    for(int i=0;i<cnt;i++)
        ans=min(ans,dp[len][i]);
    if(ans==INF)
        ans=-1;


    return ans;
}


char a[MAXN];
char b[MAXN];


int main(){
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    int N;
    int qqq=0;
    while(~scanf("%d",&N)){
        qqq++;
        if(N==0)
            break;
        cnt=0;

        newnode();
        for(int i=0;i<N;i++){
            scanf("%s",b);
            insert(b,strlen(b));
        }

        build_fail();
        scanf("%s",a);

        printf("Case %d: %d\n",qqq,AC_Match(a,strlen(a)));
    }
    return 0;
}
