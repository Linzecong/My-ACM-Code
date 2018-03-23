#include<iostream>
#include<math.h>
#include<string>
using namespace std;
typedef long long int ll;


int main(){
	
	string a;
	cin>>a;
	//a.push_back('~');
	//a.push_back('~');
	bool f=0;
	int num=0;
	char c;
	for(int i=0;i<a.length();i++){
		
		if(f==0){
			cout<<a[i];
			c=a[i];
			num=1;
			f=1;
		}
		else{
			if(a[i]==c){
				num++;
			}
			else{
				cout<<num;
				f=0;
				num=0;
				i--;
			}
		}
	}
	cout<<num;
	cout<<endl;
	
	return 0;
}