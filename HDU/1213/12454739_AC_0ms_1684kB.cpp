#include<iostream>
using namespace std;
int pre[1005];

int find(int x){
	int r=x;
	while(pre[r]!=r)
		r=pre[r];
			
//	int i=x,temp;  
//    while(pre[i]!=r){  
//        temp=pre[i];  
//        pre[i]=r; 
//        i=temp;  
//    }
			
	return r;
}

int join(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx!=ry){
		pre[rx]=ry;
	}
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			pre[i]=i;
			
		
		
		int a,b;
		int ans=n;
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			int rx=find(a);
			int ry=find(b);
			if(rx!=ry){
				join(a,b);
				ans--;	
			}
		}
		printf("%d\n",ans);
		
	}
	
	
	return 0; 
} 





