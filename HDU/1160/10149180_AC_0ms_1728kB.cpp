#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int ID;
	int weight;
	int speed;
}mice[1001];

bool cmp(node a,node b)
{
	return a.speed>b.speed;
}


struct backPointer{
	int num;
	int backID;
}dp[1001];

void show(int i)
{
	if(dp[i].backID==i)cout<<mice[i].ID<<endl;
	else
	{
		show(dp[i].backID);
		cout<<mice[i].ID<<endl;
	}
}

int main()
{
	int cur=1,maxm=0,maxID;
	while(~scanf("%d%d",&mice[cur].weight,&mice[cur].speed))
	{
		mice[cur].ID=cur;
		dp[cur].num=1;
		dp[cur].backID=cur;
		cur++;
	}
	sort(mice+1,mice+cur+1,cmp);
	for(int i=2;i<=cur;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(mice[i].weight>mice[j].weight)
			{
				if(dp[j].num+1>dp[i].num)
				{
					dp[i].num=dp[j].num+1;
					dp[i].backID=j;
				}
				
				if(dp[i].num>maxm)
				{
					maxm=dp[i].num;
					maxID=i;
				}
			}
		}
	}
	cout<<maxm<<endl;
	show(maxID);
	return 0;
} 