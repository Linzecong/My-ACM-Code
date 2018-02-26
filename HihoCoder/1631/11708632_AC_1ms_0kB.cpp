#include<iostream>
#include<algorithm>
using namespace std;

int c[10000];
int mi[10000];
int vis[10000];

bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	
	int m,n,x;
	while(cin>>m>>n>>x){
		for(int i=0;i<n;i++){
			cin>>c[i];
			mi[i]=0;
			vis[i]=0;
		}
		sort(c,c+n);
					
	
			
			
		for(int i=1;i<=x;i++)
			for(int j=0;j<n;j++)
				if(vis[j]==1){
					mi[j]++;
					if(mi[j]==c[j]){
						vis[j]=0;
						mi[j]=0;
					}
				}
				else{
					if(m>0){
						m--;
						mi[j]++;
						
						vis[j]=1;
						if(mi[j]==c[j]){
							vis[j]=0;
							mi[j]=0;
						}	
					}	
				}
				
		int in=0;
		for(int i=0;i<n;i++)
		if(vis[i]==1)
		in+=vis[i];
		
		if(m<0)
		m=0;
		cout<<m<<" "<<in<<endl;		
				
					
		
			
		
		
	}
	
	
	
	return 0;
}