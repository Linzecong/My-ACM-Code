#include <iostream>
using namespace std;
int main()
{
	int n;
	int ans=0;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int k;
		cin >> k ;
		if (k!=1)
			ans++;
	}
	cout << ans;
}