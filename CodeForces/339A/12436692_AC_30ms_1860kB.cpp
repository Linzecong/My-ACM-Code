#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<stdlib.h>

using namespace std;

int a[1005];
int cnt=0;
string temp;
int main(){

    string str;
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+')
        {
            a[cnt++]=stoi(temp);
            temp.clear();
        }
        else{
            temp.push_back(str[i]);
        }
    }
    a[cnt++]=stoi(temp);
    temp.clear();

    sort(a,a+cnt);

    for(int i=0;i<cnt;i++)
        if(i!=cnt-1)
            cout<<a[i]<<"+";
    else
            cout<<a[i]<<endl;



    return 0;
}

