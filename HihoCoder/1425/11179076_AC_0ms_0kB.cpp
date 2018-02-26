#include <iostream>
using namespace std;

int n,temp,maxm,ans;
int nums[101];
bool flag=false,asc=false;

int main()
{
	while(cin>>n)
	{
		if(n==0)break;
		maxm=0,ans=0;
		for(int i=0;i<n;i++)cin>>nums[i];
		for(int i=0;i<n;i++)
		{
			temp=i;
			if(nums[temp]==nums[(temp+1)%n])continue;
			else if(nums[temp]>nums[(temp+1)%n])
			{
				asc=false;
				temp++;
			}
			else
			{
				asc=true;
				temp++;
			}
			while(1)
			{
				if(asc)
				{
					if(nums[temp%n]<nums[(temp+1)%n])temp++;
					else
					{
						if(nums[temp%n]-nums[i]>=maxm)ans=max(ans,temp-i);
						break;
					}
				}
				else
				{
					if(nums[temp%n]>nums[(temp+1)%n])temp++;
					else
					{
						if(nums[i]-nums[temp%n]>=maxm)ans=max(ans,temp-i);
						break;
					}
				}
			}	
			
		}
		cout<<ans<<endl;
	}
	return 0;
}