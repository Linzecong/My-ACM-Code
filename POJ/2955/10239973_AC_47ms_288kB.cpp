#include<iostream>
#include<memory.h>
#include<string>
using namespace std;

string str;
int dp[105][105];//i到j这个区间的最大匹配数

int main(){

    while(cin>>str){
        if(str=="end")
            break;

        memset(dp,0,sizeof(dp));

        //枚举区间长度，必须要从小到大枚举
        for(int len=2;len<=str.size();len++){

            //l,r为左右标记，两个标记不断地让右移
            for(int l=0,r=len-1;r<str.size();l++,r++){

                if((str[l]=='('&&str[r]==')')||(str[l]=='['&&str[r]==']'))
                    dp[l][r]=dp[l+1][r-1]+2;


                for(int z=l;z<r;z++)
                    dp[l][r]=max(dp[l][r],dp[l][z]+dp[z+1][r]);
            }




        }

        cout<<dp[0][str.size()-1]<<endl;




    }





}
