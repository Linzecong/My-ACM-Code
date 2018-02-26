#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
using namespace std;
typedef long long int ll;
const int MOD=100000000;

int dp[110][110][10];//第i位，回文串长度为j的回文串个数
int dig[200];

string str;

string qu(string a){
    string ans;
    bool have=0;
    for(int i=0;i<a.size();i++){
        if(!have&&a[i]=='0')
            continue;
        have=1;
        ans.push_back(a[i]);
    }
    return ans;
}

string subone(string a){
    int len=a.size();
    if(a[len-1]>'0'){
        a[len-1]-=1;
        return a;
    }
    else{
        int i=len-1;
        while(i>=0&&a[i]<='0')
            a[i--]='9';
        a[i]-=1;
        return a;
    }
}
int ok(int x,int y,char op)
{
    if(op=='/')return x<y;
    if(op=='-')return x==y;
    return x>y;
}


//当前位置，回文串长度，是否前导0
int dfs(int pos,int len,int last,bool have,bool limit){

    if(pos==0)
        return len==str.size();

    //记忆化搜索
    if(!limit && !have && dp[pos][len][last]!=-1){
        return dp[pos][len][last];
    }

    int end=limit?dig[pos]:9;
    int ans=0;

    for(int i=0;i<=end;i++){
        if(have){
            ans+=dfs(pos-1,0,i,have&&i==0,limit&&i==end);//如果有前导0
        }
        else{

            if(len<str.size()&&ok(last,i,str[len]))
                ans+=dfs(pos-1,len+1,i,have&&i==0,limit&&i==end);
            else{

                if(len>0&&ok(last,i,str[len-1]))
                ans+=dfs(pos-1,len,i,have&&i==0,limit&&i==end);
            }

        }

    }
    ans%=MOD;

    if(!limit&&!have)
        dp[pos][len][last]=ans;

    return ans;

}

int solve(string x){

    int pos=0;

    for(pos=0;pos<x.size();pos++)
        dig[x.size()-pos]=x[pos]-'0';

    return dfs(pos,0,0,1,1);
}


int main(){

    while(cin>>str){
        memset(dp,-1,sizeof(dp));
        string l,r;
        cin>>l>>r;
        l=qu(l);
        r=qu(subone(r));

        printf("%08d\n",(solve(r)-solve(l)+MOD)%MOD);
    }



    return 0;
}
