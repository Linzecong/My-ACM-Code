#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int T,Case=0;
	cin >> T;
	while (T--)
	{
		Case++;
		int x,y,k;
		cin >> x>>y >>k;
		if (x>y)
			cout <<"Case #"<<Case<<": "<< k << endl;
		else
		{
		//	a>=k*(11*y-9*x)/(2*x+11*y)
			cout <<"Case #"<<Case<<": "<< k-(k*(11*y-9*x)+2*x+11*y-1)/(2*x+11*y) << endl;
		}
		
	}
}