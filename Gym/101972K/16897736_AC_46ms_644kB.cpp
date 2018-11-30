#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+5; 
int n;
char a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
	int cnt;
	int T;
	scanf("%d",&T);
	while (T--){
		cnt=0;
		scanf("%d",&n);
		scanf("%s%s",a,b);
		for (int i=0;i<n;i++){
			if (a[i]!=b[i]){
				cnt++;
				c[cnt]=a[i];
				d[cnt]=b[i];
			}
		}
		bool flag=true;
		for (int i=1;i<=cnt;i++){
			int t=i % cnt +1;
			if (d[i]!=c[t]){
				flag=false;
				break;
			}
		}
		if (flag){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
} 