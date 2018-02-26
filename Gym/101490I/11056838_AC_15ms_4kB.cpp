#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef long long int ll;
bool isPrime( int num )  
{  
               if(num==0)
               return false;
               
                 if(num ==2|| num==3 )  
                                 return 1 ;  
                
                 if(num %6!= 1&&num %6!= 5)  
                                 return 0 ;  
                 int tmp =sqrt( num);  
                
                 for(int i= 5;i <=tmp; i+=6 )  
                                 if(num %i== 0||num %(i+ 2)==0 )  
                                                 return 0 ;  
           
                 return 1 ;  
}  


int main(){
	
	int q;
	cin>>q;
	bool flag=0;
	for(int i=1;i<=100;i++){
		double temp=pow(q,1.0/i);
		int tt;
		if(temp-(int)temp<0.001)
		tt=(int)temp;
		else{
			if(temp-(int)temp>0.99){
				tt=(int)temp+1;
			}
			else
			tt=0;
		}
	//	cout<<temp<<endl;
	//	cout<<tt<<endl;
		
		if(isPrime(tt))
		{
			flag=1;
			break;
		}
	}
	
	if(q==1)
	flag=0;
	
	if(flag)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;

	
	return 0;
}



