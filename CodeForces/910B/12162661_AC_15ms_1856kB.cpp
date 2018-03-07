#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	int n;
	int s;
	int h;
	while(cin>>n>>s>>h){
	
	int g[6]={s,s,s,s,h,h};
	sort(g,g+6,cmp);
	
	int num[6]={n,n,n,n,n,n};
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++)
			if(num[j]>=g[i]){
				num[j]-=g[i];
				break;
			}
	}

	int c=0;
	for(int i=0;i<6;i++){
		if(num[i]==n){
			c++;
		}
	}
	
	if(h>s){
		int num1[6]={n-h,n-h,n,n,n,n};
	
	
	
	for(int i=2;i<6;i++){
		for(int j=0;j<6;j++)
			if(num1[j]>=g[i]){
				num1[j]-=g[i];
				break;
			}
	}

	int b=0;
	for(int i=0;i<6;i++){
		if(num1[i]==n){
			b++;
		}
	}
	
	c=max(c,b);
	
	}
	
	
	
	cout<<6-c<<endl;
}
	return 0;
} 