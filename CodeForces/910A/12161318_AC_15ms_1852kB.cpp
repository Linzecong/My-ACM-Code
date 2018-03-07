#include<iostream>
#include<string>
using namespace std;
int main(){
	
	int d;
	int n;
	cin>>n>>d;
	string str;
	cin>>str;
	str="1"+str;
	int num=0;
	
	for(int i=1;i<n;i++){
		
		int t=1;
		for(int j=d;j>=1;j--){
			if(i+j>=n)
				j=n-i;
			
			if(str[i+j]=='1'){
				i=i+j-1;
				num++;
				t=2;
				break;
			}
			
		}
		
		if(t==1){
			num=-1;
			break;
		}
	}
	
	cout<<num<<endl;
	
	return 0;
} 