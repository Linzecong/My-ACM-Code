#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <queue>  
using namespace std;  
int n,m,k,tot,ans;  
struct matrix {int s[10][10];} A;  
struct v {bool s[10][10];};  
  
int maxsum(matrix a) //求状态a可得的最大分数（不一定准确，用于可行性剪枝）  
{  
  int count[10]={0};  
  for(int i=1;i<=n;i++)  
    for(int j=1;j<=n;j++)  
      count[a.s[i][j]]++;  
  int s=0;  
  for(int i=1;i<=k;i++)  
    s+=count[i]*count[i];  
  return s;  
}  
  
bool breaker(v &vis,matrix from,matrix &to,int x,int y) //从第x行第y列的宝石开始拓展，消除前状态为from，消除后状态存储在to中，当前状态访问情况为vis，返回能否可以消除宝石  
{  
  int qx[70],qy[70];  
  qx[1]=x;qy[1]=y;  
  to=from;int c=from.s[x][y],h=1,t=1;  
  vis.s[x][y]=1;  
  while(h<=t)  
  {  
    int i=qx[h],j=qy[h];  
    if (!vis.s[i-1][j-1]&&from.s[i-1][j-1]==c) {qx[++t]=i-1;qy[t]=j-1;vis.s[i-1][j-1]=1;}  
    if (!vis.s[i-1][j]&&from.s[i-1][j]==c) {qx[++t]=i-1;qy[t]=j;vis.s[i-1][j]=1;}  
    if (!vis.s[i-1][j+1]&&from.s[i-1][j+1]==c) {qx[++t]=i-1;qy[t]=j+1;vis.s[i-1][j+1]=1;}  
    if (!vis.s[i][j-1]&&from.s[i][j-1]==c) {qx[++t]=i;qy[t]=j-1;vis.s[i][j-1]=1;}  
    if (!vis.s[i][j+1]&&from.s[i][j+1]==c) {qx[++t]=i;qy[t]=j+1;vis.s[i][j+1]=1;}  
    if (!vis.s[i+1][j-1]&&from.s[i+1][j-1]==c) {qx[++t]=i+1;qy[t]=j-1;vis.s[i+1][j-1]=1;}  
    if (!vis.s[i+1][j]&&from.s[i+1][j]==c) {qx[++t]=i+1;qy[t]=j;vis.s[i+1][j]=1;}  
    if (!vis.s[i+1][j+1]&&from.s[i+1][j+1]==c) {qx[++t]=i+1;qy[t]=j+1;vis.s[i+1][j+1]=1;}  
    h++;  
  }  
  if (t>=3)  
  {  
    for(int i=1;i<=t;i++)  
      to.s[qx[i]][qy[i]]=0;  
    tot=t;  
    return 1;  
  }  
  else return 0;  
}  
  
void move(matrix &a) //对状态a进行修正，即进行下落和左移的操作  
{  
  int top[10]={0};  
  for(int i=1;i<=m;i++) top[i]=n;  
  for(int i=n;i>=1;i--)  
    for(int j=1;j<=m;j++)  
      if (a.s[i][j])  
      {  
        swap(a.s[top[j]][j],a.s[i][j]);  
        top[j]--;  
      }  
  top[0]=1;  
  for(int j=1;j<=m;j++)  
  {  
    bool flag=0;  
    for(int i=1;i<=n;i++)  
      if (a.s[i][j])  
      {  
        swap(a.s[i][top[0]],a.s[i][j]);  
        flag=1;  
      }  
    if (flag) top[0]++;  
  }  
}  
  
void dfs(matrix now,int sum) //DFS，now为当前状态，sum为当前已得到的分数  
{  
  bool flag=0;  
  if (maxsum(now)+sum<=ans) return; //可行性剪枝  
  v vis;  
  memset(vis.s,0,sizeof(vis.s));  
  for(int i=1;i<=n;i++)  
    for(int j=1;j<=m;j++)  
      if (now.s[i][j]!=0&&!vis.s[i][j])  
      {  
        matrix next;  
        if (breaker(vis,now,next,i,j))  
        {  
          flag=1;  
          move(next);  
          dfs(next,sum+tot*tot);  
        }  
      }  
  if (!flag&&sum>ans) ans=sum; //flag值为false即表示不可再消除，修正最大得分  
}  
  
int main()  
{  
  while(scanf("%d%d%d",&n,&m,&k)!=EOF)  
  {  
    memset(A.s,0,sizeof(A.s));  
    for(int i=1;i<=n;i++)  
      for(int j=1;j<=m;j++)  
        scanf("%d",&A.s[i][j]);  
    ans=0;  
    dfs(A,0);  
    printf("%d\n",ans);  
  }  
    
  return 0;  
}  