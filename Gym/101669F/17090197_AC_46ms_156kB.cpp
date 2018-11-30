#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=5e3+5;
int n;
vector<int>V1,V2,V3;
int c[maxn];
long long sum,ans=1e18+5;
char a[maxn],b[maxn];
void done(int t){
	long long w=sum;
	long long cnt=0;
	int v=V1.size()-1;
	for (int i=V3.size()-1;i>=0;i--){
		while (t<=v&&V1[v]>V3[i]){
			w-=V1[v--];
			cnt+=w;
		}
		w-=V3[i];
		cnt+=w;
	}	
	while (t<=v){
		w-=V1[v--];
		cnt+=w;
	}
	for (int i=0;i<V2.size();i++){
		w+=V2[i];
		cnt+=w;
	}
	ans=min(ans,cnt);
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&c[i]);
	scanf("%s",a);
	scanf("%s",b);
	V1.clear(),V2.clear(),V3.clear();
	for (int i=0;i<n;i++){
		if (a[i]!=b[i]){
			if (a[i]=='0') V2.push_back(c[i]);//01
			else V3.push_back(c[i]),sum+=c[i];//10
		}
		else if (a[i]=='1')
			V1.push_back(c[i]),sum+=c[i];//11  01  11 
	}
	sort(V2.begin(),V2.end());
	sort(V3.begin(),V3.end());
	sort(V1.begin(),V1.end());
	done(V1.size());
	long long k=0;
	for (int i=V1.size()-1;i>=0;i--){
		bool flag=false;
		for (int j=0;j<V2.size();j++){
			if (V2[j]>V1[i]){
				V2.insert(V2.begin()+j,V1[i]);
				flag=true;
				break;
			}
		}
		if (!flag) V2.insert(V2.end(),V1[i]);
		done(i);
	}
	printf("%lld",ans);
} /*
5
2 2 2 2 2
11111
10110*/