#include<iostream>
#include<math.h>
#include<memory.h>
#include<string.h>
#include<algorithm>
using namespace std;

char a[1000];


int main(){
	
	while(cin>>a){
		
		sort(a,a+3);
		
		for(int i=0;i<3;i++)
		if(i!=2)
		cout<<a[i]<<" ";
		else
		cout<<a[i]<<endl;
	}
	
	return 0;
}

