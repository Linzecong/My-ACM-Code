#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
int pre[100005];

int find(int x){
	if(pre[x]!=0){
		while(pre[x]!=0)
		x=pre[x];
		return x;
	}
	else
	return 0;
}

int main(){
	
	
				
	bool is=1;
	int case2=1;
	while(1){
	
	int a,b;
	scanf("%d%d",&a,&b);
		
		if(a<0&&b<0){
			break;
		}
		

			if(a==0&&b==0){
				if(is==0){	
				cout<<"Case "<<case2++<<" is not a tree."<<endl;
				}
				else{
					
					set<int> sss;
					for(int i=0;i<100005;i++){
					sss.insert(find(i));
				    }
				    
				    //cout<<sss.size()<<endl;
					if(sss.size()<=2)
				cout<<"Case "<<case2++<<" is a tree."<<endl;
				else{
					cout<<"Case "<<case2++<<" is not a tree."<<endl;
				}
				
			    }
				
				for(int i=0;i<100005;i++){
					pre[i]=0;
				}
				is=1;
			    continue;
		    }
		
		if(pre[b]!=0){
			is=0;	
		}
		else
		pre[b]=a;
		
		
	}
	
	
	
	
	
	
	return 0;
}