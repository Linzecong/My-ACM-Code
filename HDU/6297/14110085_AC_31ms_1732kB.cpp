#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005//求MAX范围内的素数  
typedef long long int ll;
const ll MOD=41234551;



int N,M;
int main(){
	
	int T;
	scanf("%d",&T);
	for(int qqq=1;qqq<=T;qqq++){
		
		string a;
		cin>>a;
		for(int i=a.size();i<3;i++)
			cout<<" ";
		cout<<a;
		cout<<"|";
		cin>>a;
		cout<<a;
		for(int i=a.size();i<16;i++)
			cout<<" ";
		cout<<"|";
		cin>>a;
		cout<<a;
		cout<<"|[";
		cin>>a;
		if(a=="Running"){
			int num;
			cin>>num;
			for(int i=0;i<num;i++)
				cout<<"X";
			for(int i=num;i<10;i++)
				cout<<" ";
			cout<<"]"<<endl;
		}
		else{
			if(a=="FB")
				cout<<"    AC*   ]"<<endl;
			else{
				if(a=="TLE"||a=="RTE"||a=="MLE"||a=="OLE")
				cout<<"    "<<a<<"   ]"<<endl;
				else
				cout<<"    "<<a<<"    ]"<<endl;
			}
				
			
		}
		
		
		
	}

	return 0;
}









