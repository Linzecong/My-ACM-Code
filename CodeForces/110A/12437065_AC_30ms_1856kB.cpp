#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<stdlib.h>

using namespace std;



int main(){

    string str;
    cin>>str;
    int num=0;
    for(int i=0;i<str.length();i++)
        if(str[i]=='7'||str[i]=='4')
            num++;
    if(num==4||num==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}

