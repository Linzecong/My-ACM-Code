#include<iostream>
#include<iomanip>
#include<math.h> 
#include<vector>
using namespace std;


int main(){
	
	
	int N;
	
	while(1){
	
	scanf("%d",&N);
	if(N==0)
	break;
	else{
		vector<vector<int> > a;
		vector<vector<int> > b;
		
		for(int i=0;i<N;i++){
		vector<int> templist;
		for(int j=0;j<N;j++){
			int temp;
			scanf("%d",&temp);
			templist.push_back(temp);
			
			
		}
		a.push_back(templist);
		b.push_back(templist);
	    }
	
	vector<vector<int> > b2=b;
	vector<vector<int> > b3=b;
	vector<vector<int> > b4=b;
	
	    for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int temp;
			scanf("%d",&temp);
			b[i][j]=temp;
			
			b2[N-j-1][i]=temp;
			b3[N-i-1][N-j-1]=temp;
			
			b4[j][N-i-1]=temp;
		}
	    }
	    
	    
	    
	    
		
	
	int maximun1=0;
	int maximun2=0;
	int maximun3=0;
	int maximun4=0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]==b[i][j])
			maximun1++;
		}
	    }
	    
	    
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]==b2[i][j])
			maximun2++;
		}
	    }
	    for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]==b3[i][j])
			maximun3++;
		}
	    }
	    for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]==b4[i][j])
			maximun4++;
		}
	    }
	
	int temp=max(maximun4,max(maximun3,max(maximun1,maximun2)));
	cout<<temp<<endl;
	
	}
}
	
	
	return 0;
}