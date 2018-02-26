#include <iostream>
#include <algorithm>
using namespace std;

string str[101];

bool cmp(string a,string b)
{
    return a+b<b+a;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    sort(str,str+n,cmp);
    for(int i=0;i<n;i++)
        cout<<str[i];
    return 0;
}
