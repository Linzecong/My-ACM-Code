#include<iostream>
#include<iomanip>
#include<math.h> 
using namespace std;


int main(){
	
	
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		
		int a;
		char b[100];
		
		scanf("%d%s",&a,&b);
		
		//cout<<a<<b;
		
		if(b[1]=='B'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<0.0<<"%"<<endl;
		}
		if(b[1]=='K'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,1))*100<<"%"<<endl;
		}
		if(b[1]=='M'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,2))*100<<"%"<<endl;
		}
		if(b[1]=='G'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,3))*100<<"%"<<endl;
		}
		if(b[1]=='T'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,4))*100<<"%"<<endl;
		}
		if(b[1]=='P'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,5))*100<<"%"<<endl;
		}
		if(b[1]=='E'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,6))*100<<"%"<<endl;
		}
		if(b[1]=='Z'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,7))*100<<"%"<<endl;
		}
		if(b[1]=='Y'){
			cout<<"Case #"<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<(1-pow(1000.0/1024.0,8))*100<<"%"<<endl;
		}
		
	}

	
	
	
	
	
	return 0;
}