#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;

int num1[500];
int num2[500];

int main()
{
	string a,b;
	
	
	
	while(cin>>a>>b){
		
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
	
	
		for(int i=0;i<a.length();i++){
			num1[a[i]]++;
		}
		for(int i=0;i<b.length();i++){
			num2[b[i]]++;
		}
		
		bool flag=1;
		
		sort(num1,num1+500);
		sort(num2,num2+500);
		
		for(int i=0;i<500;i++)
		if(num1[i]!=num2[i])
		flag=0;
	
		if(flag)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}


    return 0;
}
