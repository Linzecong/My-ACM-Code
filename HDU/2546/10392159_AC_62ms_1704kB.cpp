#include <iostream>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
int main()  
{  
    int n,m;  
    while(cin>>n&&n){       
        int price[1010];  
        memset(price,0,sizeof(price));  
        for(int i=1;i<=n;i++)  
            cin>>price[i];  
        sort(price+1,price+n+1);  
        int max=price[n];  
        //背包容量m-5，物品数量n-1   
        cin>>m;  
        if(m<5)  cout<<m<<endl;  
        else  
        {  
        int f[1010];//f[j]表示买前i件物品，预算为j时的最大花销   
        memset(f,0,sizeof(f));  
        for(int i=1;i<=n-1;i++)  
            for(int j=m-5;j>=price[i];j--)     
                    if(f[j]<f[j-price[i]]+price[i])  
                        f[j]=f[j-price[i]]+price[i];  
         cout<<m-max-f[m-5]<<endl;  
        }         
    }     
    return 0;  
}  