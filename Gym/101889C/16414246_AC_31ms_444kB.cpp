#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int k,n,u;
map<int ,int>M,cnt;
int a[100000];
int main()
{
	cin >> k >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> u;
		M[u]++;
	}
	for (int i=1;i<=k;i++)
		cnt[M[i]]++;
	int o=0,s=0;
	a[0]=0;
	for (auto i:cnt)
		a[++a[0]]=i.first;
	bool flag=true;
	sort(a+1,a+a[0]+1);
	if (a[0]==2)
	{
		if (cnt[a[1]]==1)
		{
			if (a[1]==a[2]-1)
			{
				cout << '+';
				for (auto i:M)
					if (i.second==a[1])
						cout << i.first;
			}
			else
				cout << '*';
		}
		else if (cnt[a[2]]==1)
		{
			if (a[1]==a[2]-1)
			{
				cout << '-';
				for (auto i:M)
					if (i.second==a[2])
						cout << i.first;
			}
			else
				cout << '*';
		}
		else cout << '*';
	}
	else
	if (a[0]==3)
	{
		if (a[1]==a[2]-1&&a[2]==a[3]-1&&cnt[a[1]]==1&&cnt[a[3]]==1)
		{
			for (auto i:M)
				if (i.second==a[3])
					cout << '-' << i.first << ' ';
			for (auto i:M)
				if (i.second==a[1])
					cout << '+' << i.first;
		}
		else
			cout << '*';
	}
	else cout << '*';
}