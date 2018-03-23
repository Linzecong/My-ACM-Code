#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

int an[255];
int bn[255];

int main(){

	
	int T;
	scanf("%d",&T);
	while(T--){
		string a,b;
		cin>>a>>b;
		memset(an,0,sizeof(an));
		memset(bn,0,sizeof(bn));
		
		for(int i=0;i<a.length();i++)
			an[a[i]]++;
			
		for(int i=0;i<b.length();i++)
			bn[b[i]]++;
		
		int ans=0;
		for(int i=0;i<a.length();i++){
			if(bn[a[i]]>0){
				ans++;
				bn[a[i]]--;
			}
			else{
				break;
			}
		}
		cout<<ans<<endl;
		
	}

	
	return 0;
}