#include<iostream>
#include<memory.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    string str2;
    for(int i=0;i<n;i++){
        cin>>str;
        str2=str;
        reverse(str.begin(),str.end());
        if(str2==str)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;


    }







    return 0;
}
