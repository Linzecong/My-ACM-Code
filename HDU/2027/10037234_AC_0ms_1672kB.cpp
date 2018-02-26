#include<iostream>
#include<memory.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include<string>
using namespace std;

int num[300];

int main()
{

    string str;

    getline(cin,str);

    int n=atoi(str.c_str());

    for(int i=0;i<n;i++){
        for(int i=0;i<300;i++)
            num[i]=0;

        getline(cin,str);

        for(int j=0;j<str.size();j++){
            num[str[j]]++;
        }


        printf("a:%d\n",num['a']+num['A']);
        printf("e:%d\n",num['e']+num['E']);
        printf("i:%d\n",num['i']+num['I']);
        printf("o:%d\n",num['o']+num['O']);
        printf("u:%d\n",num['u']+num['U']);

        if(i!=n-1)
            cout<<endl;

    }








    return 0;
}
