#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
typedef long long ll;

bool check(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return 1;
    return 0;
}
int pos[MAXN];
int main(){

    string a;
    cin>>a;

    int num=0;
    for(int i=0;i<a.size();i++)
        if(check(a[i])){
            pos[++num]=i;
        }

    if(num!=0){
       if(!check(a[0]))
            cout<<0<<endl;
        else if(num==1){
           cout<<a.size()<<endl;
        }
       else{
           if(num%2){
               cout<<pos[num/2+2]-pos[num/2+1]<<endl;
           }
           else
               cout<<pos[num/2+1]-pos[num/2]<<endl;

       }
    }
    else
        cout<<1<<endl;




    return 0;
}
