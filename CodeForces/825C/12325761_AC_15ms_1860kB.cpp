#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

long long int a[1005];

int main(){

    long long int  n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>a[i];

	sort(a,a+n);
	
	long long int  nk=k;
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]>nk*2){
			ans++;
			nk=nk*2;
			i--;
		}
		else
			nk=max(nk,a[i]);
	}
	 
	cout<<ans<<endl;
    
    return 0;
}