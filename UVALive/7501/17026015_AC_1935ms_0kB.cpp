#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
const long long INF=9e18+5;
int a[maxn];
int n;
long long g,p;
bool judge(long long u){
	bool flag=false;
	long long w=u;
	long long v=p;
	if (u>=g) return true;
	for (int i=1;i<=n;i++){
		w+=a[i];
		v--;
		if (w<0)
			w=0;
		if (w>=g) return true;
		if (v==0) return false;
	}
	if (w<=u) return false;
	long long k=w,Ma=-INF;
	for (int i=1;i<=n;i++){
		w+=a[i];
		v--;
		if (w>=Ma) Ma=w;
		if (w<0)
			w=0;
		if (w>=g) return true;
		if (v==0) return false;
	}
	if (w<=k) return false;
	long long num=w-k;
	Ma-=k;
	long long cong2=v/n;
	v=v%n+n;
	if (cong2==0) v-=n;
	else if (cong2-1>INF/num) w=INF;
	else w+=num*(cong2-1);
	if (w>=g) return true;
	for (int i=1;i<=n;i++){
		w+=a[i];
		v--;
		if (w>=Ma) Ma=w;
		if (w<0)
			w=0;
		if (w>=g) return true;
		if (v==0) return false;
	}
	if (w>=g) return true;
	for (int i=1;i<=n;i++){
		w+=a[i];
		v--;
		if (w>=Ma) Ma=w;
		if (w<0)
			w=0;
		if (w>=g) return true;
		if (v==0) return false;
	}
}
int main(){
//	freopen("a.txt","w",stdout);
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		scanf("%d%lld%lld",&n,&g,&p);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		long long l=0,r=g;
		while (l<=r){ 
			long long mid=(l+r)>>1;
			if (judge(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("Case #%d: %lld\n",Case,l);
	}
}/*5
21 388560582839343128 485024093467834189
-70314576 -84954814 -78349477 80179248 -250850463 -38409317 88095409 -132974204 163257708 260479047 86272785 248884731 -62998186 -136531433 -22617961 -256537759 -265731338 -257977770 -127232207 76068196 248209093
*/

