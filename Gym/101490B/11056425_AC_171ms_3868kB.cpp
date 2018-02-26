#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long int ll;



int main(){
	
	
	string a;
	
	cin>>a;
	
	string ans;
	int i;
	for(i=0;i+2<a.size();i++){
		char q,w,e;
		q=a[i];
		w=a[i+1];
		e=a[i+2];
		
		if(q!=w&&q!=e&&w!=e){
			a[i]='C';
			a[i+1]=0;
			a[i+2]=0;
			i+=2;
		}
		
	}
	
	for(int j=0;j<a.size();j++){
		if(a[j]=='R')
			ans.push_back('S');
			
			if(a[j]=='B')
			ans.push_back('K');
			
			if(a[j]=='L')
			ans.push_back('H');
				
				if(a[j]=='C')
			ans.push_back('C');	
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}