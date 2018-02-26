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

const int MAXN=1000015;
const int NEXTNUM=26;
const char FC='a';

int nxt[MAXN][NEXTNUM];
int fail[MAXN];
int num[MAXN];
int cnt;

int newnode(){
    for(int j=0;j<NEXTNUM;j++)
        nxt[cnt][j]=0;
    num[cnt]=fail[cnt]=0;
    return cnt++;
}

void insert(char s[],int len){
    int p=0;
    for(int i=0;i<len;i++){
        int x=s[i]-FC;
        if(nxt[p][x]==0){
            nxt[p][x]=newnode();
        }
        p=nxt[p][x];
    }
    num[p]++;
}

int ans=0;
void build_fail(){
    int temp;
    queue<int> que;
    que.push(0);

    while(!que.empty()){
        temp=que.front();
        que.pop();
       // if(num[fail[temp]])
       //     num[temp]=num[fail[temp]];
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

int AC_Match(char s[],int len){
    int p=0;
    int count=0;
    for(int i=0;i<len;i++){
        int x=s[i]-FC;
        p=nxt[p][x];


        for(int f=p;f;f=fail[f]){
            count+=num[f];
            num[f]=0;
        }

    }
    return count;
}


char a[MAXN];
char b[MAXN];

int main(){

    int N;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);

        cnt=0;
        ans=0;
        int root=newnode();
        for(int i=0;i<N;i++){
            scanf("%s",b);
            insert(b,strlen(b));
        }
        build_fail();
        scanf("%s",a);
        ans=AC_Match(a,strlen(a));
        printf("%d\n",ans);

    }
    return 0;
}











