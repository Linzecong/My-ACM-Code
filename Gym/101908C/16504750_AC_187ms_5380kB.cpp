#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
struct Cla{
	int L;
	int c[maxn];
	vector<int>bx,by;
	int lowbit(int n){return n&(-n);}
	int sum(int q)
	{
		int ret=0;
		for(int i=q;i>=1;i-=lowbit(i))
		ret+=c[i];
		return ret;
	}
	void update(int i,int j){for(int k=i;k<=L;k+=lowbit(k))c[k]+=j;}
	struct node{
		int x,y;
		bool operator <(const node& a)const{
			if (x==a.x) return y<a.y;
			return x<a.x;
		}
	}a[maxn];
	long long Do(int w)
	{
		L=w;
		memset(c,0,sizeof(c));
		//cout << "--------" << endl;
		for (int i=1;i<=L;i++)
		{
			bx.push_back(a[i].x);
			by.push_back(a[i].y);
		}
		sort(bx.begin(),bx.end()); bx.erase(unique(bx.begin(),bx.end()),bx.end());
		sort(by.begin(),by.end()); by.erase(unique(by.begin(),by.end()),by.end());
		for (int i=1;i<=L;i++)
		{
			a[i].x=lower_bound(bx.begin(),bx.end(),a[i].x)-bx.begin()+1;
			a[i].y=lower_bound(by.begin(),by.end(),a[i].y)-by.begin()+1;
		}
		int ML=by.size();
		sort(a+1,a+1+L);
	//	cout << ML << endl;
		long long ans=0;
		for (int i=1;i<=L;i++)
		{
			ans+=sum(ML)-sum(a[i].y)+1;
			update(a[i].y,1);/*
			cout << a[i].x << ' ' << a[i].y << endl;
			cout << ans << endl;*/
		}
		return ans;
	}
	
}r,c;
int X,Y,n,m;
int main()
{
	scanf("%d%d",&X,&Y);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&r.a[i].x,&r.a[i].y);
	long long u=1+r.Do(n);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&c.a[i].x,&c.a[i].y);
	u+=c.Do(m)+1ll*n*m;
	printf("%lld",u);
}