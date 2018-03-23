#include<iostream>
#include<math.h>
using namespace std;


const int MAXN = 1000117;  
int n;  
int num[MAXN];  

int minn[MAXN];
int maxx[MAXN];


int main(){

    int T;
    scanf("%d",&T);
    while(T--)
    {
        
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);

        minn[0]=0;
        for(int i=1;i<=n;i++){
            minn[i]=max(minn[i-1],num[i]);
           // cout<<minn[i]<<endl;
        }
            
        
        maxx[n+1]=0x3f3f3f3f;
        for(int i=n;i>=1;i--){
            maxx[i]=min(maxx[i+1],num[i]);
            //cout<<maxx[i]<<endl;
        }
            

     

        int ans=0;
        for(int i=2;i<=n-1;i++){
            if(minn[i-1]<=num[i]&&maxx[i+1]>=num[i])
                ans++;
        }

        printf("%d\n",ans);



    }

    
    return 0;
}