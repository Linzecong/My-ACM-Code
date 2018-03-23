#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;

int a[100005];
int main(){


	int n,T;
	scanf("%d%d",&n,&T);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	
	int s=T,t=T;
	
	int sn=0;
	int si=0;
	while(s>0&&si<n){
		s-=a[si];
		if(s>=0)
			sn++;
		si++;
	}
	
	int tn=0;
	int ti=n-1;
	while(t>0&&ti>=0){
		t-=a[ti];
		if(t>=0)
			tn++;
		ti--;
	}
	
	if(sn>tn)
	cout<<"Yan"<<endl;
	else{
		if(sn<tn)
		cout<<"Nathan"<<endl;
		else
		cout<<"Empate"<<endl;
	}
	
	
	return 0;
}

