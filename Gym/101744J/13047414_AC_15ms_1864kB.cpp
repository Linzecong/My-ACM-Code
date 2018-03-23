#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;

struct cir{
	int x;
	int y;
	int r;
	cir(int a=0,int b=0,int c=0){
		x=a;
		y=b;
		r=c;
	}
}c[1005];

int main(){


	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y>>c[i].r;
	}
	
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if((c[i].r+c[j].r)*(c[i].r+c[j].r)==(c[i].y-c[j].y)*(c[i].y-c[j].y)+(c[i].x-c[j].x)*(c[i].x-c[j].x))
			cout<<i<<" "<<j<<endl;
		}
	
	return 0;
}

