#include<iostream>
#include<algorithm>
using namespace std;

int a[100005];
int main(){

    int n;
    cin>>n;
    while(n--){
        int s;
        cin>>s;
        for(int i=0;i<s;i++)
            cin>>a[i];
        sort(a,a+s);
        for(int i=0;i<s;i++)
        if(i<s-1)
        cout<<a[i]<<" ";
        else
        cout<<a[i]<<endl;
    }






    return 0;
}