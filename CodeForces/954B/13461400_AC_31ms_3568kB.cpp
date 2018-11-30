#include <iostream>
#include <string>
using namespace std;

int nxt[105];
int main()
{

	int n;
	cin >> n;
	string a;
	cin >> a;

	int ans = n;
	if (n % 2)
		for (int i = n - 1; i >= 1; i -= 2)
		{

			bool yes = 1;
			for (int j = 0; j < i / 2; j++)
			{
				if (a[j] != a[i / 2 + j])
					yes = 0;
			}

			if (yes)
			{
				ans = i / 2 + 1 + (n - i);
				break;
			}
		}
	else
	{
		for (int i = n ; i >= 1; i -= 2)
		{

			bool yes = 1;
			for (int j = 0; j < i / 2; j++)
			{
				if (a[j] != a[i / 2 + j])
					yes = 0;
			}

			if (yes)
			{
				ans = i / 2 + 1 + (n - i);
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}