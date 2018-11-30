#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

long long int num[105];
int main()
{

	cin>>num[0]>>num[1]>>num[2];
	
	sort(num,num+3);
	
	if(num[0]==num[1]){
		cout<<num[0]<<endl;
	}
	else{
		if((num[1]-num[0])%2==0){
			cout<<(num[1]-num[0])/2+(num[1]+num[0])/2<<endl;
		}
		else{
			if(num[2]==num[1])
				cout<<num[2]<<endl;
			else{
				if((num[2]-num[1])%2==0){
					cout<<(num[2]-num[1])/2+(num[2]+num[1])/2<<endl;
				}
				else{
							if((num[2]-num[0])%2==0){
						cout<<(num[2]-num[0])/2+(num[2]+num[0])/2<<endl;
					}
					else{
				
					cout<<num[2]+num[1]+num[0]-1<<endl;
		
					}
				}
				
		}
	}
}

	

	return 0;
}