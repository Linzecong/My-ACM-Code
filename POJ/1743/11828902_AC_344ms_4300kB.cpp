#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N = int(2e5)+10;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],ws[N],wv[N];
int rank[N],height[N];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        //printf("p = %d\n", p );
    }
}
void calheight(int *r,int *sa,int n){
  //  memset(height,0,sizeof(height));
  //  memset(rank,0,sizeof(rank));
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n; height[rank[i++]] = k )
    for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}

int data[N], sa[N], n;

vector<int> S[N];

bool Judge (int k)
{
	bool flag = false;
	int i,cur = -1;
	for (i=1;i<=n;i++)   //分组
	{
		if (height[i] < k)
			S[++cur].clear();
		S[cur].push_back(i);
	}
	for (i=1;i<=cur;i++)
	{
		int Max=-1,Min=N;
		if (S[i].size() > 1)
		{
			for (int j=0;j<S[i].size();j++)
			{
				Max = max( Max, sa[ S[i][j] ] );
				Min = min( Min, sa[ S[i][j] ] );
			}
			if ( Max-Min > k ) //严格大于
			{
				flag = true; 
				break;
			}
		}
	}
	return flag;
}

int Deal ()
{
	DA(data,sa,n+1,200);
	calheight(data,sa,n);
	int low=0,high=n,mid,ans=-1;
	while (low<high)   //注意二分的写法
	{
		mid = (low+high)>>1;
		if ( Judge(mid) )
			ans=mid,low=mid+1;
		else high = mid;
	}
	return ans>=4?ans+1:0;
}

int main ()
{
	while (scanf("%d",&n),n)
	{
		int i;
		for (i=0;i<n;i++)
			scanf("%d",&data[i]);
		for (i=0;i<n-1;i++)
			data[i]=data[i+1]-data[i]+90;  //由于要用基数排序,+90以防出现负数
		data[--n]=0;
		printf("%d\n",Deal());
	}
	return 0;
}
/*
Input
1
2
9
1 1 1 1 1 1 1 1 1
30
25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18
82 78 74 70 66 67 64 60 65 80
0

Out
0
0
5
*/