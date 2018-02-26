/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/24 12:10:26
File Name     :F:\2013ACM练习\比赛练习\2013通化邀请赛\1001.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double sum = 0;
        double a;
        for(int i = 0;i < 12;i++)
        {
            scanf("%lf",&a);
            sum += a;
        }
        sum /= 12;
        char str[1000];
        sprintf(str,"%.2f",sum);
        int len = strlen(str);
        if(str[len-2] == '0' && str[len-1] == '0')
            str[len-3] = 0;
        else if(str[len-1] == '0')
            str[len-1] = 0;
        printf("$%s\n",str);
    }
    return 0;
}