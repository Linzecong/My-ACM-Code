#include<iostream>
using namespace std;

int r;
int x[3],y[3];

int sq(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    scanf("%d",&r);
    for(int i=0;i<3;i++){
    	scanf("%d%d",&x[i],&y[i]);
	} 
	int res=0;
	for(int i=0;i<3;i++){
		if(x[i]==0&&y[i]==0) {
		   res+=10;continue;
		}
	    else {
		int temp=sq(0,0,x[i],y[i]);
		for(int i=1;i<=10;i++){
			if(temp<=i*i*r*r) {
				res+=11-i;
				break;
			}
		}
	}
	}
	printf("%d\n",res);
        return 0;
}