#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int MAXN = 1000005;
ull P1 = 131;
ull g[MAXN];
ull Hash[MAXN];
bool vis[16000005];
int id[256];
int cnt=0;
ull getHash(int x, int len)
{
    return Hash[x + len - 1] - Hash[x - 1] * g[len];
}
void hhash(char *s, int len)
{
    for (int i = 1; i <= len; i++)
        Hash[i] = (Hash[i - 1] * P1 + id[s[i - 1]]);
}


char s[MAXN];
int main()
{
    int N,NC;
    scanf("%d%d",&N,&NC);
    P1 = NC;
    scanf("%s",s);
    int len=strlen(s);
    g[0] = 1;
    for (int i = 1; i <= len; i++){
        g[i] = (g[i - 1]) * P1;
        if(id[s[i-1]]==0)
            id[s[i-1]]=cnt++;
    }

    hhash(s,len);
    int ans=0;
    for(int j=1;j<=len-(N-1);j++){
        if(vis[getHash(j,N)]==0)
            ans++;
        vis[getHash(j,N)]=1;
    }
    printf("%d\n",ans);

    return 0;
}
