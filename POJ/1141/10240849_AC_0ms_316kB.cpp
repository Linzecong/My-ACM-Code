#include<iostream>
#include<memory.h>
#include<string>
using namespace std;

string str;
int dp[115][115];//i到j这个区间需要补最少多少个括号使得符合题意

int jie[115][115];//i到j这个区间是从哪里开始截断的

//递归输出
void shuchu(int l,int r){
    if(l>r)
        return;

    if(l==r){
        if(str[l]=='('||str[r]==')')
            cout<<"()";
        else
            cout<<"[]";

    }
    else{
        if(jie[l][r]==-1){
            cout<<str[l];
            shuchu(l+1,r-1);
            cout<<str[r];
        }
        else{
            shuchu(l,jie[l][r]);
            shuchu(jie[l][r]+1,r);
        }
    }
}


int main(){

     cin>>str;
        


        memset(dp,0,sizeof(dp));


        for(int i=0;i<str.size();i++){
            dp[i][i]=1;//大小为1的区间肯定要补1个
        }


        //枚举区间长度，必须要从小到大枚举
        for(int len=2;len<=str.size();len++){

            //l,r为左右标记，两个标记不断地右移
            for(int l=0,r=len-1;r<str.size();l++,r++){


                if((str[l]=='('&&str[r]==')')||(str[l]=='['&&str[r]==']')){
                    dp[l][r]=dp[l+1][r-1];
                    jie[l][r]=-1;//本来就匹配，不需要截断
                }
                else
                    dp[l][r]=0x7fffffff;



                for(int z=l;z<r;z++){
                    //如果从这里截开可以使得补最少的括号，那么就从这里截，记录截的位置
                    if(dp[l][r]>dp[l][z]+dp[z+1][r]){
                        dp[l][r]=dp[l][z]+dp[z+1][r];
                        jie[l][r]=z;
                    }
                 }
            }

        }

        shuchu(0,str.size()-1);
        cout<<endl;



    




return 0;
}
