#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
typedef long long int ll;





int main(){

double total=0;
    for(int i=0;i<12;i++)
    {
        double t;
        cin>>t;
        total+=t;
    }

    printf("$%.2f\n",total/12);


    return 0;
}

