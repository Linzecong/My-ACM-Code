#include<iostream>
#include<math.h>
using namespace std;
typedef long long int ll;

int a[100005];


int main(){
	
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	int ans=0;
	while(n){
		ans++;
		n/=2;
	}
	cout<<ans<<endl;
	
	
	return 0;
}