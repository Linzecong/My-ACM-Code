#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=65,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int match[maxn*maxn];
int p[maxn][maxn],head[maxn*maxn];
bool visit[maxn][maxn],v[maxn*maxn];
char s[maxn][maxn]; 
int dir[4][2];
int n,m,num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void dfs(int i,int j) {
	visit[i][j]=1;
	for (int k=0;k<4;k++) {
		int x=i+dir[k][0],y=j+dir[k][1];
		if (x>0&&y>0&&x<=n&&y<=m) 
		if (!visit[x][y]&&s[x][y]=='L') dfs(x,y);
		if (s[x][y]=='C') s[x][y]='W';
	}
}

bool hungary(int now) {
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!v[to]) {
			v[to]=1;
			if (!match[to]||hungary(match[to])) {
				match[to]=now;match[now]=to;
				return true;
			}
		}
	}
	return false;
}

int main() {
	dir[0][0]=dir[1][0]=dir[2][1]=dir[3][1]=0;
	dir[0][1]=dir[2][0]=1;dir[1][1]=dir[3][0]=-1;
	int i,j,k,ans=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
	}
	mem0(visit);
	for (i=1;i<=n;i++) 
		for (j=1;j<=m;j++) 
			if (!visit[i][j]&&s[i][j]=='L') dfs(i,j),ans++;
	int cnt=0;
	memset(head,-1,sizeof(head));
	num=0;
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++) 
	    	if (s[i][j]=='C') 
	    		p[i][j]=++cnt;
	for (i=1;i<=n;i++) 
		for (j=1;j<=m;j++) 
			if (s[i][j]=='C'&&(i+j)%2==0) 
			    for (k=0;k<4;k++) {
			    	int x=i+dir[k][0],y=j+dir[k][1];
			   		if (x>0&&y>0&&x<=n&&y<=m) 
					   if (s[x][y]=='C') addedge(p[i][j],p[x][y]);
			    }
	int sum=0;
	mem0(match);
	for (i=1;i<=cnt;i++) 
		if (!match[i]) {
			mem0(v);v[i]=1;
			if (hungary(i)) sum++;
		}
	ans+=cnt-sum;
	printf("%d\n",ans);
	return 0;
}
