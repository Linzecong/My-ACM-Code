#include <cstdlib>  
#include <iostream>  
#define MAX 102  
using namespace std;  
   
int factor[205][MAX]={0};  
int sim[201]={0};  
   
void multiply(int s[],int Max,int b)  
{  
     int ans=0;  
     for(int i=Max;i>=0;i--)  
     {  
        ans+=s[i]*b;  
        s[i]=ans%10000;  
        ans/=10000;          
     }  
}  
   
void div(int s[],int Max,int b)  
{  
    int ans=0;  
    for(int i=0;i<=Max;i++)  
    {  
        ans=ans*10000+s[i];  
        s[i]=ans/b;  
        ans%=b;          
    }       
}  
int getfactor(){  
    int i;  
    factor[0][MAX-1]=factor[1][MAX-1]=1;  
    for(i=2;i<=203;i++){  
        memcpy(factor[i],factor[i-1],MAX*sizeof(int));  
        multiply(factor[i],MAX-1,i);  
    }  
    return 0;  
}  
   
int output(int *s,int k){  
    int i=1;  
    printf("Test #%d:\n",k);  
    while(s[i]==0&&i<MAX)  
        i++;  
    printf("%d",s[i++]);  
    for(;i<MAX;i++)  
        printf("%04d",s[i]);  
    printf("\n");  
    return 0;  
}  
int main(int argc, char *argv[])  
{  
       
   int m,n,i,k=1;  
    getfactor();  
    while(scanf("%d %d",&m,&n),m+n){  
        if(n>m){  
            printf("Test #%d:\n",k++);  
            printf("0\n");  
            continue;  
        }  
         memcpy(sim,factor[m+n],sizeof(int)*MAX);  
        multiply(sim,MAX-1,m-n+1);  
        div(sim,MAX-1,m+1);  
        output(sim,k);  
        k++;  
    }  
    return 0;  
}  