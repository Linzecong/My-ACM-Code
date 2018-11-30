#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=305;
struct node{
	int x,y,z;
}ans[maxn];
int a,b,c;
int x,y,z;
int main(){
	cin >> a >> b >>c;
	if (a==0||b==0||c==0){
		cout << "-1" << endl;
		return 0;
	}
/*	if (a+b<c||b+c<a||a+c<b){
		cout << "-1" << endl;
		return 0;
	}*/
	int cnt=0;
	ans[++cnt]={0,0,0};
	x=y=z=1;
	int u=0;
	a--;b--;c--;
	while (a>0||b>0||c>0){
		if (b==0&&c==0){
			for (int i=1;i<=x-1;i++)
				for (int j=1;j<=y-1;j++){
					if (a==0)break;
					ans[++cnt]={i,j,0};
					a--;
				}
			if (a!=0){cout << -1 << endl;return 0;}
			break;
		}
		if (a==0&&b==0){
			for (int i=1;i<=z-1;i++)
				for (int j=1;j<=y-1;j++){
					if (c==0)break;
					ans[++cnt]={0,j,i};
					c--;
				}
			if (c!=0){cout << -1 << endl;return 0;}
			break;
		}
		if (a==0&&c==0){
			for (int i=1;i<=x-1;i++)
				for (int j=1;j<=z-1;j++){
					if (b==0)break;
					ans[++cnt]={i,0,j};
					b--;
				}
			if (b!=0){cout << -1 << endl;return 0;}
			break;
		}
		if (a==b&&b==c){
			ans[++cnt]={++u,u,u};
			a--;b--;c--;
		}
		else if (a>=c&&b>=c){
			ans[++cnt]={x++,0,0};
			a--;b--;
		}
		else if (b>=a&&c>=a){
			ans[++cnt]={0,0,z++};
			b--;c--;
		}
		else{
			ans[++cnt]={0,y++,0};
			a--;c--;
		}
	}
	cout << cnt << endl;
	for (int i=1;i<=cnt;i++){
		cout << ans[i].x << ' ' << ans[i].y << ' '<<ans[i].z << endl;
	}
}