#include <iostream>
#include <cstring>
using namespace std;

char str[1000000];

int main(){
    cin>>str;
    int len=strlen(str);
    int R,B,L;
    R=0;
    B=0;
    L=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='R')R++;
        if(str[i]=='B')B++;
        if(str[i]=='L')L++;
        if(R&&B&&L)
        {
            str[i-2]='C';
            str[i-1]='C';
            str[i]='C';
            R=0;
            B=0;
            L=0;
        }
        else
        {
            if(str[i-2]=='R')R--;
            if(str[i-2]=='B')B--;
            if(str[i-2]=='L')L--;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(str[i]=='R')str[i]='S';
        if(str[i]=='B')str[i]='K';
        if(str[i]=='L')str[i]='H';
    }
    for(int i=0;i<len;i++)
    {
        if(str[i]=='C')
        {
            cout<<str[i];
            i+=2;
        }
        else cout<<str[i];
    }
    return 0;
}
