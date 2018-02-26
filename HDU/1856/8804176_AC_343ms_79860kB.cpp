#include<stdio.h>  
#include<map>  
#include<iostream>  
using namespace std;  
map<string,int> m;  
int set[10000005];  
int num[10000005]; 
int max1=0; 
int find(int x)  
{  
    int r=x;  
    while(r!=set[r])  
    r=set[r];  
    int i=x;  
    while(i!=r)  
    {  
        int j=set[i];  
        set[i]=r;  
        i=j;  
    }  
    return r;  
}  
void merge(int x,int y)  
{  
    int fx=find(x);  
    int fy=find(y);  
    if(fx!=fy)  
    {  
        set[fx]=fy;  
        num[fy]+=num[fx];
		if(num[fy]>max1)
		max1=num[fy];  
        
    }  
      
}  
int main()  
{  
    int n;  
    int a;  
    int b;  
    while(scanf("%d",&n)!=EOF)  
    {  
        if(!n) {  
            printf("1\n"); 
            continue;  
        } 
        
          max1=0;
             
            for(int i=1;i<10000005;i++)  
            {  
                set[i]=i;  
                num[i]=1;  
            }
			for(int i=0;i<n;i++){
				scanf("%d%d",&a,&b);  
                merge(a,b);
			}  
                  
              cout<<max1<<endl;
          
    }  
    return 0;  
} 