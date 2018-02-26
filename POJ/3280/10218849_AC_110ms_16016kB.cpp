#include <iostream>
#include <string>
#include<vector>
#include <cstring>
#include<math.h>

using namespace std;
int N,M;
char str[2005];

int add[256];
int del[256];

int dp[2005][2005];


int main()
{

    while(~scanf("%d%d",&N,&M)){
        memset(dp,0,sizeof(dp));

        scanf("%s",str);

        char c;
        int a,b;
        for(int i=0;i<N;i++){
            cin>>c>>a>>b;
            add[c]=a;
            del[c]=b;
        }



        for(int j=1;j<M;j++)
            for(int i=j-1;i>=0;i--){
                if(str[i]==str[j])
                    dp[i][j]=dp[i+1][j-1];
                else{
                    int l=dp[i+1][j]+min(add[str[i]],del[str[i]]);
                    int r=dp[i][j-1]+min(add[str[j]],del[str[j]]);
                    dp[i][j]=min(l,r);
                }


            }


cout<<dp[0][M-1]<<endl;


    }





    return 0;
}
