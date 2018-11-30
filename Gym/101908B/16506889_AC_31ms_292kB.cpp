#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int f[105][105];
bool w[500];
int n;
void sg()
{
	for (int i=1;i<=100;i++)
		for (int j=1;j<=100;j++)
		{
			f[1][2]=0,f[2][1]=0;
			memset(w,false,sizeof(w));
			for (int u=1;u<=min(i,j)-1;u++)
				if(i!=j)
					w[f[i-u][j-u]]=true;
			for (int u=1;u<=i-1;u++)
				if(i-u!=j)
					w[f[i-u][j]]=true;
			for (int u=1;u<=j-1;u++)
				if(j-u!=i)
					w[f[i][j-u]]=true;
			for (int u=0;;u++)
				if (!w[u])
				{
					f[i][j]=u;
					break;
				}
		}
}
int main()
{
	int n,l,c;
	sg();
	cin >> n;
	int u=0;
	bool flag=true;
	for (int i=1;i<=n;i++)
	{
		cin >> l >> c;
		if(l==c){
			flag=false;
		} 
		u^=f[l][c];
	}
	if (!u&&flag) cout << 'N';
	else cout << 'Y';
}