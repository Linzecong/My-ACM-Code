#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod=1e9;
int n;
long long m;
long long f[500][500],g[500][500],temp[500][500],h[500][500],e[500][500];
long long w[500];
void dfs(int t,int temp){
	w[t]++;
	for (int i=temp;i<n;i++){
		if (i<n-1)
			dfs(t|(1<<i)|(1<<i+1),i+2);
		dfs(t|(1<<i),i+1);
	}
}
void mul(long long a[][500],long long b[][500]){
	memset(temp,0,sizeof(temp));
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<(1<<n);j++)
			for (int k=0;k<(1<<n);k++)
				if (a[i][j]!=0&&b[j][k]!=0)
				temp[i][k]=(temp[i][k]+a[i][j]*b[j][k]%mod)%mod;
}
void qs(long long w){
	for (int i=0;i<(1<<n);i++)
		e[i][i]=1;
	while (w>0){
		if (w&1){
			mul(e,h);
			memcpy(e,temp,sizeof temp);
		}
		mul(h,h);
		memcpy(h,temp,sizeof temp);
		w/=2;
	}
	mul(e,f);
	memcpy(e,temp,sizeof temp);
}
int main(){
	cin >> n >> m;
	dfs(0,0);
	for (int i=0;i<(1<<n);i++)
		for (int j=i;j<(1<<n);j++)
			if ((i&j)==i)
				f[i][j]=w[j^i];
	for (int i=0;i<(1<<n);i++)
		g[i][((1<<n)-1)^i]=1;
	mul(f,g);
	memcpy(h,temp,sizeof temp);
//	mul(h,f);
	qs(m-1);
	long long ans=0;
	cout << e[0][(1<<n)-1] << endl;
}