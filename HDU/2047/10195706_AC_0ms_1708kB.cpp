#include<iostream>
using namespace std;
int main()
{
    __int64 a[42];
    a[1] = 3;
    a[2] = 8;
    for(int i=3;i<=40;i++)
        a[i]=2*(a[i-1]+a[i-2]);
    int n;
    while(cin>>n)
        cout<<a[n]<<endl;
}