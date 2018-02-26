#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int pre[1005];

int find(int x)  
{  
    int r=x;  
    while(r!=pre[r])  
    r=pre[r];  
    int i=x;  
    while(i!=r)  
    {  
        int j=pre[i];  
        pre[i]=r;  
        i=j;  
    }  
    return r;  
} 



struct point{
	int x;
	int y;
	
	
}pl[1005];

int dis(point a,point b){
	int temp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	return temp;
	
}


int isok[1005];


int main(){
	
	int n,d;
	
	scanf("%d%d",&n,&d);
	
	for(int i=0;i<=n;i++)
	pre[i]=i;
	
	
		for(int i=1;i<=n;i++){
			scanf("%d%d",&pl[i].x,&pl[i].y);
				
		}
		
		char a[10];
		while(~scanf("%s",a)){
			
			if(a[0]=='O'){
				int temp;
				scanf("%d",&temp);
				
				for(int i=1;i<=n;i++){
					
					if(dis(pl[i],pl[temp])<=d*d&&isok[i])
					pre[find(i)]=temp;			
			
		        }
				
				
				isok[temp]=1;
			}
			else{
				
				int l,r;
				scanf("%d%d",&l,&r);
				
				if(find(l)==find(r))
				printf("SUCCESS\n");
				else
				printf("FAIL\n");
				
				
				
				
			}
	
		}
		
		
		
	

	
	return 0;
}