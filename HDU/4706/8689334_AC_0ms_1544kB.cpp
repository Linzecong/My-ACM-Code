/* *******************************************
Author       : kuangbin
Created Time : 2013年09月08日 星期日 12时16分28秒
File Name    : 1001.cpp
******************************************* */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

char str[100][100];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cnt = 0;
    for(int i = 3;i <= 10;i++)
    {
        for(int j = 0;j < i;j++)    
        {
            for(int k = 0;k < i;k++)
                str[j][k] = ' ';
            str[j][i] = 0;
        }
        for(int j = 0;j < i;j++)
        {
            str[j][0] = 'a' + cnt;
            cnt = (cnt+1)%26;
        }
        for(int j = i-2;j > 0;j--)
        {
            str[j][i-1-j] = 'a' + cnt;
            cnt = (cnt+1)%26;
        }
        for(int j = 0;j < i;j++)
        {
            str[j][i-1] = 'a' + cnt;
            cnt = (cnt+1)%26;
        }
        for(int j = 0;j < i;j++)
            printf("%s\n",str[j]);
    }

    return 0;
}