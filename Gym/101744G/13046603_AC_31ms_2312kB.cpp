#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;


int main(){
	

	string str;
	while(cin>>str){
	
	
	bool flag=0;
	
	vector<char> s;
	for(int i=0;i<str.length();i++){
		if(str[i]=='A')
			s.push_back('A');
		else
			{
				if(s.size())
					s.pop_back();
				else{
					flag=1;
					break;
				}
				
			}
	}
	
	if(flag||s.size())
	cout<<"Nao"<<endl;
	else
	cout<<"Sim"<<endl;
	
	
}
	
	return 0;
}