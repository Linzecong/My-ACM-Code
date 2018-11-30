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
		
		int j=-1,i;
		for(i=0;i<a.length();i++){
			j++;
			for(j;j<b.length();j++){
				if(b[j]==a[i]){
					break;
				}		
			}
			if(j==b.length())
				break;
		}
		if(i==a.length())
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		
	}


    return 0;
}
