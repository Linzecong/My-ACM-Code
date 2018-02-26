#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<memory>
#include<math.h>
using namespace std;
typedef long long int ll;




int main ()
{
    string str;

    cin>>str;

    if(str.size()==1){
        if(str[0]<=90)
            cout<<char(str[0]+32)<<endl;
        else
            cout<<char(str[0]-32)<<endl;
    }
    else{
        if(str[0]<=90){
            bool is=true;
            for(int i=0;i<str.size();i++)
                if(str[i]>90)
                    is=false;
            if(is){
                for(int i=0;i<str.size();i++)
                    str[i]+=32;

            }
            cout<<str<<endl;
        }
        else{
            bool is=true;
            for(int i=1;i<str.size();i++)
                if(str[i]>90)
                    is=false;
            if(is){
                for(int i=1;i<str.size();i++)
                    str[i]+=32;
                str[0]-=32;
            }

            cout<<str<<endl;
        }


    }




    return 0;
}
