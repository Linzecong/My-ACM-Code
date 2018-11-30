#include<iostream>
#include<algorithm>
using namespace std;
int Scan()
{   //  输入外挂  
    int res = 0, flag = 0;  
    char ch;  
    if ((ch = getchar()) == '-') 
    {   
        flag = 1;  
    }    
    else if(ch >= '0' && ch <= '9') 
    {
        res = ch - '0'; 
    }
    while ((ch = getchar()) >= '0' && ch <= '9')  
    {
        res = res * 10 + (ch - '0');  
    }
    return flag ? -res : res;  
} 

int a[1000005];

int main(){
	int n,m,i;
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;i++)
			a[i]=Scan();	
		sort(a,a+n);
		for(i=n-1;i>n-m;i--)
			printf("%d ",a[i]);
		printf("%d\n",a[n-m]);
			
	
	}
	 
	return 0;
}

