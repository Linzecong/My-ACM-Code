#include<iostream>
#include<memory.h>
using namespace std;
int b[10];
bool judge(int x){
	memset(b,0,sizeof(b));
	bool flag=0;
	while(x){
		if(x%10==2)
			flag=1;
		else
			if(x%10==6){
				if(flag)
					return true;
			}
			else
				flag=0;
	
		b[x%10]=1;
		x/=10;
	}
	
	if(b[4]==1)
		return true;
	return false;
}

int sum[1000005];

int main(){
	
	for(int i=1;i<=1000000;i++)
		if(judge(i))
			sum[i]+=sum[i-1]+1;
		else
			sum[i]=sum[i-1];
	
	int l,r;
	while(~scanf("%d%d",&l,&r)){
		if(l==0&&r==0)
			break;
		cout<<(r-l+1)-sum[r]+sum[l-1]<<endl;
	}
	
	
	
	return 0;
}
