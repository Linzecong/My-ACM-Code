#include <iostream>
#include <cstring>
using namespace std;

char str[51];
int len,f[51];

int main()
{
    cin>>str;
    len=strlen(str);
    for(int i=0;i<len;i++)
        f[i]=1;
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(str[i]>str[j])f[i]=max(f[i],f[j]+1);
        }
    }
    int maxm=0;
    for(int i=0;i<len;i++)
        maxm=max(maxm,f[i]);
    cout<<26-maxm<<endl;
    return 0;
}
