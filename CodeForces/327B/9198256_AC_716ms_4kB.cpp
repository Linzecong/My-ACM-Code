#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<memory>
#include<math.h>
using namespace std;
typedef long long int ll;

int n,m,t;

bool prime(int x)
{
     int y;
     for(y=2;y<=sqrt(x);y++)
         if (x%y==0)
            return false;
     return true;
}

int main ()
{
    int n;
    cin>>n;


        for(int i=3;i<=10000000;i++){
            if(prime(i)){
                printf("%d ",i);
                n--;
                if(n==0){
                    printf("\n");
                    break;
                }
            }
        }





    return 0;
}
