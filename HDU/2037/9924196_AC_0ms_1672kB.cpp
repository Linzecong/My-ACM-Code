#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
	int Ti_s;
	int Ti_e;
}shows[101];

bool cmp(interval a,interval b)
{
	if(a.Ti_e!=b.Ti_e)return a.Ti_e<b.Ti_e;
	else return a.Ti_s<b.Ti_s;
}

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)break;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&shows[i].Ti_s,&shows[i].Ti_e);
		}
		sort(shows,shows+n,cmp);
		int cur=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(cur<=shows[i].Ti_s)
			{
				cur=shows[i].Ti_e;
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
