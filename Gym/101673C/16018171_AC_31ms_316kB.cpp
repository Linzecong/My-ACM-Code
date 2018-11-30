#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;


char str[15005];

int main()
{

    scanf("%s",str);
    int N=strlen(str);
    int num1=0,num2=0;
    for(int i=0;i<N/2;i++){
        num1+=str[i]-'A';
        num2+=str[N/2+i]-'A';
    }
 
    num1%=26;
    num2%=26;


    for(int i=0;i<N/2;i++){
        str[i]+=num1;
        if(str[i]>'Z')
            str[i]='A'+str[i]-'Z'-1;

        str[N/2+i]+=num2;
        if(str[N/2+i]>'Z')
            str[N/2+i]='A'+str[N/2+i]-'Z'-1;
    }

    for(int i=0;i<N/2;i++){
        str[i]+=str[N/2+i]-'A';
        if(str[i]>'Z')
            str[i]='A'+str[i]-'Z'-1;
    }


    for(int i=0;i<N/2;i++){
      printf("%c",str[i]);
    }






    return 0;
}











