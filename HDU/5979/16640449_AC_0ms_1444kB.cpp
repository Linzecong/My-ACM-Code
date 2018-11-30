#include <iostream>
#include <math.h>
#define PI 3.1415926535

using namespace std;

int main()
{
    int N;
	double D;
	
	while(cin>>N>>D){
		double ans=0;
		double ang;
		for(int i=0;i<N;i++){
			cin>>ang;
			
			ans+=0.5*sin(ang*PI/180.0)*D*D;
			
		}
		printf("%.3lf\n",ans);
	
		
		
	}
    


    return 0;
}


