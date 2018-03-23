#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    long long int  n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);//Arrays.sort(a);
	int num=1;
	for(int i=3;i<n;i++){
		if(a[i]==a[2])
			num++;	
	}
		
	if(a[0]==a[1]&&a[1]==a[2]){
		long long int i;
		for(i=3;i<n;i++){
			if(a[i]!=a[2])
				break;
		}
		cout<<i*(i-1)*(i-2)/6<<endl;
	}
	else if(a[1]==a[2]){
		long long int i;
		for(i=3;i<n;i++){
			if(a[i]!=a[2])
				break;
		}
		cout<<(i-1)*(i-2)/2<<endl;
	}
	else
		cout<<num<<endl;
	
    return 0;
}


