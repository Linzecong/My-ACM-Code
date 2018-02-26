#include <iostream>
#include <string>
#include<vector>
#include <cstring>

using namespace std;

long long int dp[35][3];

int main()
{
   
    dp[0][0]=dp[1][1]=dp[0][2]=1;


    for(int i=2;i<=30;i++){
        dp[i][0]=dp[i-2][0]+dp[i-1][1]+dp[i-2][2];
        dp[i][1]=dp[i-1][2];
        dp[i][2]=dp[i][0]+dp[i-1][1];
    }

int n;
    while(cin>>n){
        if(n==-1)
            break;

        cout<<dp[n][0]<<endl;

    }




    return 0;
}
