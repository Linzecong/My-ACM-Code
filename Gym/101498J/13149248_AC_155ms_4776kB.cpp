#include<iostream>
#include<string.h>
#include<memory.h>
#include<deque>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;

char a[600005];

deque<int> num;
int cnt=0;

bool has[600005];

int main(){

	
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		num.clear();
		memset(has,0,sizeof(has));
	   
    	scanf("%[^\n]%*c", a); 
		
		int len=strlen(a);
		
		int curwl=0;
		for(int i=0;i<len;i++){
			if(a[i]!=' '){
				;
			}
			else{
				num.push_back(i+1);
				has[i+1]=1;
			}
		}
		num.push_back(len+1);
		has[len+1]=1;
		
		bool yes=0;
		for(int i=0;i<num.size();i++){
			for(int j=2;j<=50000;j++){
				if(has[j*num[i]]==0)
					break;
				if(j*num[i]==num.back())
					yes=1;
				if(j*num[i]>num.back())
					break;
			}
		}
		
		if(yes)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
		
	}

	
	return 0;
}