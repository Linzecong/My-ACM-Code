#include<cstring>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


int main(){

string a;

while(cin>>a){
	
	
	
	
	sort(a.begin(),a.end());
	
	for(int i=0;i<a.size();i++)
	if(i==a.size()-1)
	cout<<a[i];
	else
	cout<<a[i]<<" ";
	
	cout<<endl;
	
	
}



	
	return 0;
}